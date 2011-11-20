#ifndef THREAD_H
#define THREAD_H
#if win32
/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include <windows.h>
#endif
namespace System {
    namespace Threading{
class NativeThread
{
    public:
        /** Default constructor */
        NativeThread(void (*target)(void* data));
        void Start(void* args);
        /** Default destructor */
        virtual ~NativeThread();
    protected:
    private:
    void (*internalcallback)(void* data);
    void* targ;
    #if win32

    HANDLE threadhandle;
    static DWORD WINAPI CallbackThread(void* sender);
    #endif

};
    }
}
#endif // THREAD_H
