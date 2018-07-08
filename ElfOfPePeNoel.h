#ifndef ELFOFPEPENOEL_H_
# define ELFOFPEPENOEL_H_

#include <cstdlib>
#include "TablePePeNoel.h"
#include "ConveyorBeltPePeNoel.h"
#include "Object.h"
#include "Toy.h"
#include "Teddy.h"
#include "SexToy.h"
#include "LittlePoney.h"
#include "IElf.h"

class ElfOfPePeNoel : public IElf
{
public:
    explicit ElfOfPePeNoel();
    virtual ~ElfOfPePeNoel();

    void PrepareToWork(TablePePeNoel* table, ConveyorBeltPePeNoel* conveyor);
    Object* TakeNewToy();
    void Work();

private:
    void PutOnTable(Object*& obj);
    bool canWork() const;
    TablePePeNoel* _table;
    ConveyorBeltPePeNoel* _conveyor;
};

#endif /* !ELFOFPEPENOEL_H_ */
