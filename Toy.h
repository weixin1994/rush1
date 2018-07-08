#ifndef TOY
# define TOY

#include <iostream>
#include <string>
#include "Object.h"

class Toy : public Object
{
    public:
	explicit Toy(std::string const& title, ObjectSubType subType);
	virtual ~Toy() {}

	virtual void isTaken();
 
    private:
	bool _taken;

};

#endif
