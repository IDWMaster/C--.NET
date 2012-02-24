/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivatives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include <string.h>
template <class T> class BaseObject {
public:
	~BaseObject() {
		if(&refcount == 0) {
			//TODO: Same issue here as in Array class
			delete refcount;

		}else {
			*refcount-=1;
		}
	}

	BaseObject<T>(T* underlyingobject) {
		refcount = new int;
		*refcount = 0;
		nativeobject = underlyingobject;

	}
	T* GetObject() {
	return nativeobject;
	}
	T *operator->() {
		return nativeobject;
	}
	T &operator*() {
return *nativeobject;
	}
	///Copy constructor
	BaseObject<T>(const BaseObject<T>& copy) {
		refcount = copy.refcount;
		*refcount+=1;


	}
private:
	T* nativeobject;
	int* refcount;
};
#endif
