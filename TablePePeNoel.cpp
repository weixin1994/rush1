#include <iostream>
#include "TablePePeNoel.h"

TablePePeNoel::TablePePeNoel() :
    _broken(false)
{
    for (int i = 0; i < 10; ++i)
        _objects[i] = NULL;
}

TablePePeNoel::~TablePePeNoel()
{
    for (int i = 0; i < 10; ++i)
        delete _objects[i];
}

Object* TablePePeNoel::take(unsigned int mask)
{
    for (int i = 0; i < 10; ++i)
    {
        if (_objects[i])
        {
            if ((1 << _objects[i]->getSubType()) & mask)
            {
                Object* obj = _objects[i];
                _objects[i] = NULL;
                return obj;
            }
        }
    }
    return NULL;
}

void TablePePeNoel::put(Object* obj)
{
    for (int i = 0; i < 10; ++i)
    {
        if (!_objects[i])
        {
            _objects[i] = obj;
            return;
        }
    }

    std::cout << TABLEPEPENOEL_COLAPSE << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        delete _objects[i];
        _objects[i] = NULL;
    }
    _broken = true;
}

size_t TablePePeNoel::_getObjCount() const
{
    size_t count = 0;
    for (int i = 0; i < 10; ++i)
        if (_objects[i])
            ++count;
    return count;

}

/* C'est dynamic_cast<caster_f>moi qui a fait */
std::string* TablePePeNoel::Look()
{
    std::string* tab = new std::string[_getObjCount()];
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (_objects[i])
            tab[j++] = _objects[i]->getTitle();
    }
    return tab;
}

bool TablePePeNoel::isBroken() const
{
    return _broken;
}

TablePePeNoel& TablePePeNoel::operator<<(Object* obj)
{
    put(obj);
    return *this;
}

