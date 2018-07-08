#ifndef TEDDY_H_
# define TEDDY_H_

#include <iostream>
#include <string>
#include "Toy.h"

class Teddy : public Toy
{
    public:
	explicit Teddy();
	virtual ~Teddy() {}
    void isTaken();

    protected:

    private:
};

#endif /* !TEDDY_H_ */
