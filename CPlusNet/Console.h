/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef CONSOLE_H
#define CONSOLE_H

#include "include/stdstring.h"
class Console
{
    public:
        /** Default constructor */
       static void Write(StdString text);
       static void WriteLine(StdString text);
       static StdString ReadLine();
    protected:
    private:
};

#endif // CONSOLE_H
