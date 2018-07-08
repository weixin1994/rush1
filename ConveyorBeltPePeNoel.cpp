#include <stdlib.h>
#include <time.h>
#include "Wrap.h"
#include "ConveyorBeltPePeNoel.h"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel(PaPaXML* papa) :
    _obj(NULL), _MrXML(papa) 
{
    std::cout << PAPAXML_HELLO << std::endl;
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{}

Object* ConveyorBeltPePeNoel::take()
{
    Object* tmp = _obj;
    _obj = NULL;
    return tmp;
}

void ConveyorBeltPePeNoel::put(Object* obj)
{
    if (_obj)
    {
        std::cout << CONVEYORBELTPEPENOEL_CANT_PUT << std::endl;
        return;
    }
    _obj = obj;
}

void ConveyorBeltPePeNoel::IN()
{
    if (_obj)
    {
        std::cout << CONVEYORBELTPEPENOEL_CANT_PUT << std::endl;
        return;
    }
    if (rand() % 2 == 1)
        _obj = new Box();
    else
        _obj = new GiftPaper();
}

std::string ConveyorBeltPePeNoel::Look()
{
    return (_obj ? _obj->getTitle() : "");
}

void ConveyorBeltPePeNoel::OUT()
{
    if (!_obj)
    {
        std::cout << CONVEYORBELTPEPENOEL_NOTHING_TO_SEND << std::endl;
        return;
    }
    
    if (_MrXML)
        _MrXML->TakeGift(_obj);
    delete _obj;
    _obj = NULL;
    std::cout << CONVEYORBELTPEPENOEL_SEND_TO_PAPANOEL << std::endl;
}

ConveyorBeltPePeNoel& ConveyorBeltPePeNoel::operator<<(Object* obj)
{
    put(obj);
    return *this;
}

Object& ConveyorBeltPePeNoel::operator>>(Object*& obj)
{
    obj = take();
    return *obj;
}
