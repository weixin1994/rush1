#include "Toy.h"

Toy::Toy(std::string const& title, ObjectSubType subType) : Object(TYPE_TOY, subType, title), _taken(false)
{
}

void Toy::isTaken()
{
    _taken = true;
}

