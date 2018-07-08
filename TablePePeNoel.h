#ifndef TABLEPEPENOEL_H_
# define TABLEPEPENOEL_H_

#include "Message.h"
#include "ITable.h"

class TablePePeNoel : public ITable
{
public:
    explicit TablePePeNoel();
    virtual ~TablePePeNoel();
    Object* take(unsigned int mask);
    void put(Object* obj);
    std::string* Look();
    bool isBroken() const;
    TablePePeNoel& operator<<(Object* obj);

private:
    size_t _getObjCount() const;
    Object* _objects[10];
    bool _broken;
};

#endif /* !TABLEPEPENOEL_H_ */
