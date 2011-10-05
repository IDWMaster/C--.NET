/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "stdstring.h"
#ifndef EXCEPTION_H
#define EXCEPTION_H


class Exception
{
    public:

        /** Default constructor */
        StdString Message;
        void* data;
        Exception(StdString msg, void* dat) {
        data = dat;
        Message = msg;
        }

    protected:
    private:
};

#endif // EXCEPTION_H
