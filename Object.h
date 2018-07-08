#ifndef OBJECT
# define OBJECT

#include <string>

class GiftPaper;
class Wrap;
class Box;
class Toy;
class Teddy;
class LittlePoney;
class SexToy;

enum ObjectType
{
    TYPE_WRAP   = 0,
    TYPE_TOY    = 1
};

enum ObjectSubType
{
    TYPE_TEDDY          = 0,
    TYPE_LITTLEPONEY    = 1,
    TYPE_SEXTOY         = 2,
#define SUB_TOY_COUNT 3
    TYPE_GIFTPAPER      = 3,
    TYPE_BOX            = 4

};

#define SUB_TYPE_TOY (1 << TYPE_TEDDY | 1 << TYPE_LITTLEPONEY | 1 << TYPE_SEXTOY)

class Object
{
public:
    explicit Object(ObjectType type, ObjectSubType subtype, const std::string &title);
    virtual ~Object() {}
    void Hello() const;

    ObjectType getType() const;
    ObjectSubType getSubType() const;
    const std::string& getTitle() const;

    GiftPaper* ToGiftPaper();
    Wrap* ToWrap();
    const Wrap* ToWrap() const;
    Box* ToBox();
    Toy* ToToy();
    Teddy* ToTeddy();
    LittlePoney* ToLittlePoney();
    SexToy* ToSexToy();
private:
    ObjectType _type;
    ObjectSubType _subType;
    std::string _title;
};

#endif
