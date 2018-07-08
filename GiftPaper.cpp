#include "GiftPaper.h"

GiftPaper::GiftPaper() : Wrap(TYPE_GIFTPAPER, "Un gift paper un")
{
}

bool GiftPaper::isOpen() const
{
    return true;
}

void GiftPaper::wrapMeThat(Object *obj)
{
    if (obj == NULL)
    {
        std::cout << GIFTPAPER_OBJ_EMPTY << std::endl;
        return ;
    }
    if (_obj != NULL)
    {
        std::cout << GIFTPAPER_FULL << std::endl;
        return ;
    }
    _obj = obj;
}
