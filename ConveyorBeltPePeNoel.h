#ifndef CONVEYORBELTPEPENOEL_H_
# define CONVEYORBELTPEPENOEL_H_

#include <iostream>
#include "Object.h"
#include "IConveyorBelt.h"
#include "Message.h"
#include "Box.h"
#include "GiftPaper.h"
#include "PaPaXML.h"

class ConveyorBeltPePeNoel : public IConveyorBelt {
    public:
	explicit ConveyorBeltPePeNoel(PaPaXML* papa = NULL);
	virtual ~ConveyorBeltPePeNoel();
	Object* take();
	void put(Object*);
	std::string Look();
	void IN();
	void OUT();

    ConveyorBeltPePeNoel& operator<<(Object* obj);
    Object& operator>>(Object*& obj);

    private:

    Object* _obj;
    PaPaXML* _MrXML;
};

#endif /* !CONVEYORBELTPEPENOEL_H_ */
