#include "Wrap.h"

Wrap::Wrap(ObjectSubType subtype, const std::string &title) : Object(TYPE_WRAP, subtype, title),
    _obj(NULL), _open(true)
{
}

Wrap::Wrap(const Wrap &other) : Object(TYPE_WRAP, other.getSubType(), other.getTitle()), _obj(new Object(*other.takeObject())), _open(other.isOpen())
{
}

Wrap::~Wrap() {
    delete _obj;
}

bool Wrap::isOpen() const {
    return _open;
}

void Wrap::openMe() {
    _open = true;
}

void Wrap::closeMe() {
    _open = false;
}

void Wrap::wrapMeThat( Object* b) {
    _obj = b;
}

const Object* Wrap::takeObject() const {
    return _obj;
}

Wrap& Wrap::operator=(const Wrap &other)
{
    _obj = new Object(*other.takeObject());
    _open = other.isOpen();

    return *this;
}
