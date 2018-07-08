#ifndef LITTLEPONEY_H_
# define LITTLEPONEY_H_

#include <iostream>
#include <string>
#include "Toy.h"

class LittlePoney : public Toy
{
    public:
	explicit LittlePoney();
	virtual ~LittlePoney() {}
        void isTaken();

    protected:

    private:
};

#endif /* !LITTLEPONEY_H_ */
