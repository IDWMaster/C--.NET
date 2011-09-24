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
    delete[] internarray;
    }
        /** Default constructor */
        Array<T>(int elements) {
            internarray = (T*)malloc(elements*sizeof(T));
            Length = elements;
        }

        //**The length of the array (in elements) */
        long Length;
        /** Creates a wrapper around an existing array. Does NOT memcpy it!*/
        Array<T>(T* existingarray) {
            Length = sizeof(existingarray)/sizeof(T);
            internarray = existingarray;
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



};

#endif // ARRAY_H
