#ifndef IELF_H_
# define IELF_H_

#include "TablePePeNoel.h"
#include "ConveyorBeltPePeNoel.h"

class IElf
{
public:
    virtual ~IElf() {}
    virtual void PrepareToWork(TablePePeNoel* table, ConveyorBeltPePeNoel* conveyor) = 0;
    virtual Object* TakeNewToy() = 0;
    virtual void Work() = 0;
};

#endif /* !IELF_H_ */
