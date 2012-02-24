/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "RThread.h"
namespace System {
    namespace Threading {
Thread::Thread(void (*target)(void* data))
{
underlyingthread = new NativeThread(target);
hascreated = false;

}
void Thread::Start(void* args) {
    hascreated = true;
underlyingthread->Start(args);
}
Thread::~Thread()
{
    ///If the thread is not running, it is safe to delete it on DTOR
    ///Otherwise; the thread should have deleted itself when it finished running
if(!hascreated) {
delete underlyingthread;
}
}
}
}
