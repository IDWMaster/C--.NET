/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef RTHREAD_H
#define RTHREAD_H
#include "Thread.h"
namespace System {
    namespace Threading {
class Thread
{
    public:
        /** Default constructor */
        Thread(void (*target)(void* data));
        /** Default destructor */
        virtual ~Thread();
        void Start(void* args);
    protected:
    private:
    ///Whether or not the underlying NativeThread has been created, and initialized
    BOOL hascreated;
    NativeThread* underlyingthread;

};
    }
}
#endif // RTHREAD_H
