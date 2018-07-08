#include "PaPaXML.h"

PaPaXML::PaPaXML(std::string const& filename) :
    _filename(filename)
{
}

bool PaPaXML::WakeUp()
{
    if (_stream.is_open())
    {
        std::cout << PAPAXML_FILE_ALREADY_OPEN << std::endl;
        return false;
    }

    _stream.open(_filename.c_str());
    if (_stream.is_open())
        _stream << "<0x42>" << std::endl;
    return _stream.is_open();
}

void PaPaXML::TakeGift(Object const* obj)
{
    if (!obj)
        return;
    if (obj->getType() == TYPE_TOY)
    {
        _stream << "<Toy>" << obj->getTitle() << "</Toy>";
    }
    else
    {
        if (obj->getSubType() == TYPE_GIFTPAPER)
        {
            _stream << "<GiftPaper>";
            TakeGift(obj->ToWrap()->takeObject());
            _stream << "</GiftPaper>" << std::endl;
            std::cout << PAPAXML_NEW_GIFT << std::endl;
        }
        else if (obj->getSubType() == TYPE_BOX)
        {
            _stream << "<Box>";
            TakeGift(obj->ToWrap()->takeObject());
            _stream << "</Box>";
        }
    }
}

void PaPaXML::GoSleep()
{
    if (!_stream.is_open())
        return;

    std::cout << PAPAXML_GO_SLEEP << std::endl;
    _stream << "</0x42>" << std::endl;
    _stream.close();
}
