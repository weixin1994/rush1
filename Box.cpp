#include "Box.h"

Box::Box()
    : Wrap(TYPE_BOX, "Box de la mort qui tue")
{
}

void Box::wrapMeThat(Object *obj)
{
    if (obj == NULL)
    {
        std::cout << BOX_OBJ_EMPTY << std::endl;
        return ;
    }
    if (_obj != NULL)
    {
        std::cout << BOX_FULL << std::endl;
        return ;
    }
    if (!isOpen())
    {
        std::cout << BOX_CLOSE << std::endl;
        return ;
    }
    _obj = obj;
}
