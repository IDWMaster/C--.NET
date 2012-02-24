/*
 * Array.h
 *
 *  Created on: Jan 11, 2012
 *      Author: webadm
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "RefcountedObject.h"
#include <string.h>
#include <stdio.h>
namespace System {
template<class T>
class Array: public RefcountedObject {
public:
	T* data;
	int32_t* length;

	Array(int32_t len,MemAllocator* cator):RefcountedObject(cator) {
	length = new(allocator->allocMem(sizeof(int32_t)))int32_t();

		if(len>0){
		data = (T*)allocator->allocMem(sizeof(T)*len);
	}else {
		data = (T*)allocator->allocMem(sizeof(T));
	}
	*length = len;
	}
	T& operator[](int32_t index) {
		return data[index];
	}
	void Remove(T& element) {
		int32_t x = 0;
		T* newdata = (T*)allocator->allocMem(sizeof(T)*(*length)-1);
		for(int32_t i = 0;i<*length;i++) {
			if(data[i] != element) {
				newdata[x] = data[i];
			x++;
			}
			data[i].~T();
		}
		allocator->unallocMem(data);
		data = newdata;
		*length = *length-1;
	}
	void Destroy() {
		for(int32_t i = 0;i<*length;i++) {
			data[i].~T();
		}
		allocator->unallocMem(data);
	}
	void Resize(int32_t len) {
		//Allocate a new array
		T* newdata = (T*)allocator->allocMem(sizeof(T)*len);
		memcpy(newdata,data,*length);
		allocator->unallocMem(data);
		data = newdata;
		*length = len;

	}
};

} /* namespace System */
#endif /* ARRAY_H_ */
