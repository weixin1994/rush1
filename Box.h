#ifndef BOX_H_
# define BOX_H_

#include <iostream>
#include <string>
#include "Message.h"
#include "Wrap.h"

class Box : public Wrap
{
 public:
    Box();
    void wrapMeThat(Object *);
};

#endif
