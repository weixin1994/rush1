#include "LittlePoney.h"

LittlePoney::LittlePoney() : Toy("gay pony", TYPE_LITTLEPONEY)
{
}

void LittlePoney::isTaken()
{
    Toy::isTaken();
    std::cout << "yo man" << std::endl;
}
