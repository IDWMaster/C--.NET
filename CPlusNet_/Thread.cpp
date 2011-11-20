/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "Thread.h"
#include <stdio.h>
namespace System {
    namespace Threading {
NativeThread::NativeThread(void (*target)(void* data))
{
    //ctor
    internalcallback = target;
}
#if win32
DWORD WINAPI NativeThread::CallbackThread(void* sender) {
    NativeThread* ithread = (NativeThread*)sender;

ithread->internalcallback(ithread->targ);
delete ithread;
return 0;
}
#endif
NativeThread::~NativeThread()
{
    //dtor
printf("Thread object has gone out of scope.\n");
}
void NativeThread::Start(void* args) {
    targ = args;

#if win32
threadhandle = CreateThread(0,0,&CallbackThread,this,0,NULL);

#endif
}
    }
}
