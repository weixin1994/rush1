#ifndef GIFTPAPER_H_
# define GIFTPAPER_H_

#include <iostream>
#include <string>
#include "Wrap.h"
#include "Message.h"

class GiftPaper : public Wrap
{
 public:
    GiftPaper();
    bool isOpen() const;
    void wrapMeThat(Object *);
};

#endif

