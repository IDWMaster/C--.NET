/*
 * RefcountedObject.h
 *
 *  Created on: Jan 11, 2012
 *      Author: webadm
 */

#ifndef REFCOUNTEDOBJECT_H_
#define REFCOUNTEDOBJECT_H_
//TODO: Look up placement "new" and use it in the memory allocator
#include "mempool.h"
#include <stdint.h>
class RefcountedObject {
private:
	int* refcount;
protected:
	MemAllocator* allocator;
public:
	virtual void Destroy() {

	}
	RefcountedObject(MemAllocator* loc) {
		// TODO Auto-generated constructor stub
			allocator = loc;
			refcount = (int32_t*)loc->allocMem(sizeof(int32_t));
			*refcount = 0;
			*refcount = *refcount+1;
	}
	RefcountedObject& operator =(const RefcountedObject& copy) {
		allocator = copy.allocator;
		refcount = copy.refcount;
		*refcount = *refcount+1;
		return *this;
	}
	RefcountedObject(const RefcountedObject& copy) {
		allocator = copy.allocator;
					refcount = copy.refcount;
					*refcount = *refcount+1;
	}
	virtual ~RefcountedObject() {
		*refcount = *refcount-1;
			if(*refcount == 0) {
				this->Destroy();
				allocator->unallocMem(refcount);
			}
	}
};

#endif /* REFCOUNTEDOBJECT_H_ */
