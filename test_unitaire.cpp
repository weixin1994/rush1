#include <cstdlib>
#include <sys/time.h>
#include "Object.h"
#include "Toy.h"
#include "LittlePoney.h"
#include "Teddy.h"
#include "Wrap.h"
#include "GiftPaper.h"
#include "Box.h"
#include "TablePePeNoel.h"
#include "PaPaXML.h"
#include "ConveyorBeltPePeNoel.h"
#include "ElfOfPePeNoel.h"

Object **MyUnitTests()
{
    Object **toy;

    toy = new Object*[2];
    toy[0] = new Teddy;
    toy[1] = new LittlePoney;

    return toy;
}

ITable *createTable()
{
    return new TablePePeNoel();
}

IConveyorBelt *createConveyorBelt()
{
    return new ConveyorBeltPePeNoel();
}

Object *MyUnitTests(Object **obj)
{
    Box *b = NULL;
    GiftPaper *gift = NULL;
    Teddy *teddy = NULL;

    for (int i = 0; i < 3; ++i) {
	if (obj[i]) {
	    if (obj[i]->getSubType() == TYPE_GIFTPAPER) {
		gift = obj[i]->ToGiftPaper();
	    } else if (obj[i]->getSubType() == TYPE_BOX) {
		b = obj[i]->ToBox();
	    } else if (obj[i]->getSubType() == TYPE_TEDDY) {
		teddy = obj[i]->ToTeddy();
	    }
	}
    }

    if (!b || !gift || !teddy) {
	return NULL;
    }

    b->wrapMeThat(teddy);
    gift->wrapMeThat(b);

    return gift;
}

int main()
{
    Object **toy = MyUnitTests();
    Object *tt[3];

    tt[0] = new GiftPaper;
    tt[1] = new Teddy;
    tt[2] = new Box;

    Object *gift = MyUnitTests(tt);

    (void)toy;
    (void)gift;

    struct timeval tm;
    gettimeofday(&tm, NULL);
    srand(tm.tv_usec);
    PaPaXML papa("output.xml");
    papa.WakeUp();
    TablePePeNoel table;
    ConveyorBeltPePeNoel conveyor(&papa);
    ElfOfPePeNoel elf;
    elf.PrepareToWork(&table, &conveyor);
    elf.Work();
    papa.GoSleep();
    return 0;
}
