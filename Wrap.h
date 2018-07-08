#ifndef WRAP_H_
# define WRAP_H_

#include <iostream>
#include <string>
#include "Object.h"

class Wrap : public Object {
    public:
	explicit Wrap(ObjectSubType subtype, const std::string &title);
	explicit Wrap(const Wrap &other);
	virtual ~Wrap();

	void wrapMeThat(Object*);
	virtual bool isOpen() const;
	void openMe();
	void closeMe();
	const Object* takeObject() const;

	Wrap& operator=(const Wrap &other);

    protected:
	Object* _obj ;
	bool _open;
};

#endif /* !WRAP_H_ */
