#ifndef ITABLE_H_
# define ITABLE_H_

#include <string>
#include "Object.h"

class ITable
{
public:
    virtual ~ITable() {}
    virtual Object* take(unsigned int mask) = 0;
    virtual void put(Object* obj) = 0;
    virtual std::string* Look() = 0;
};

#endif /* !ITABLE_H_ */
