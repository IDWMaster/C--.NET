//CONTRIBUTION REQUESTED! URGENT: See line 24


/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef ARRAY_H
#define ARRAY_H
#include <malloc.h>
#pragma once
#include <stdlib.h>
template <class T>
class Array
{
    public:
    ~Array() {
        //Delete all elements in the underlying array (especially important if this instance was created with the 'new' keyword)
	if(*refcount == 0) {
    delete[] internarray;
	//TODO: Need feedback here. Should I use delete[], or delete? Since this was allocated with new[]?
	//I know it's usually recommended, but this has been cast to int*, so is it still necessary?
	delete refcount;
	} else {
	*refcount-=1;
	}
    }
        /** Default constructor */
        Array<T>(int elements) {
            internarray = (T*)malloc(elements*sizeof(T));
            Length = elements;
			refcount = (int*)new byte[sizeof(int)];
			*refcount = 0;
        }
		//Create shallow copy (increment reference)
		Array<T>(const Array<T>& copy) {
			Length = copy.Length;
			internarray = copy.internarray;
			refcount = copy.refcount;
			*refcount+=1;
		}
        //**The length of the array (in elements) */
        long Length;
        /** Creates a wrapper around an existing array, and memcpys it into this new array!*/
        Array<T>(T* existingarray) {
            Length = sizeof(existingarray);
            internarray = new T[sizeof(existingarray)/sizeof(T)];
			memcpy(internarray,existingarray,sizeof(internarray));
			refcount = (int*)new byte[sizeof(int)];
			*refcount = 0;
        }
        T operator[] (int index) {
            return internarray[index];
        }
        void Resize(int elements) {
            internarray = (T*)realloc(internarray,elements*sizeof(T));
            Length = elements;
        }
        //The internal data buffer
        T* internarray;

    protected:
    private:
		int* refcount;

};

#endif // ARRAY_H
