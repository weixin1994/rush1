#include "Teddy.h"

Teddy::Teddy() : Toy("bisounours", TYPE_TEDDY)
{
}

void Teddy::isTaken()
{
    Toy::isTaken();
    std::cout << "gra hu" << std::endl;
}
