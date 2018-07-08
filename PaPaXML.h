#ifndef PAPAXML_H_
# define PAPAXML_H_

#include <iostream>
#include <fstream>
#include "Message.h"
#include "Object.h"
#include "Wrap.h"

class PaPaXML
{
public:
    PaPaXML(std::string const& filename);

    bool WakeUp();
    void TakeGift(Object const* obj);
    void GoSleep();

private:
    std::string _filename;
    std::ofstream _stream;
};

#endif /* !PAPAXML_H_ */
