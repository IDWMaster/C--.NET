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
#include <vector>
//Why on Earth is memcpy declared in string.h?
#include <string.h>
template <class T>
class Array
{
    public:
	//Gets the internal data buffer
	T* GetArray() {
	return &(*internarray)[0];
	}
    ~Array() {
        //Delete all elements in the underlying array (especially important if this instance was created with the 'new' keyword)
	if(*refcount == 0) {

	//TODO: Need feedback here. Should I use delete[], or delete? Since this was allocated with new[]?
	//I know it's usually recommended, but this has been cast to int*, so is it still necessary?
	//See also; BaseObject (same problem there)
    delete refcount;
	} else {
	*refcount-=1;
	}
    }
        /** Default constructor */
        Array<T>(int elements) {
        	T* elems = new T[elements];

        	//Initialize array from memory
            internarray = new std::vector<T>(elems,elems+(elements*sizeof(T)));
            memset(&(*internarray)[0],0,elements*sizeof(T));
            Length = elements;
			refcount = (int*)malloc(sizeof(int));
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
        Array<T>(T* existingarray, long elems) {
            Length = elems;
            internarray = new std::vector<T>(existingarray,existingarray+(elems*sizeof(T)));

			refcount = (int*)malloc(sizeof(int));
			*refcount = 0;
        }
        T operator[] (int index) {
            return internarray[index];
        }
        void Resize(long elements) {
        	Length = elements;
        	internarray->reserve(elements);

        }
        //The internal data buffer

    protected:
    private:
		int* refcount;
		std::vector<T>* internarray;
};

#endif // ARRAY_H
