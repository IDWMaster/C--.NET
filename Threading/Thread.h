/*
 * Thread.h
 *
 *  Created on: Jan 13, 2012
 *      Author: webadm
 */

#ifndef THREAD_H_
#define THREAD_H_
#include <defs.h>
#include <RefcountedObject.h>
#undef byte
#include <windows.h>
namespace System {
#ifdef platform_win32
class Mutex:public RefcountedObject {
private:
	WCHAR* name;
public:

	Mutex(MemAllocator* allocator):RefcountedObject(allocator) {
		name = (WCHAR*)allocator->allocMem(sizeof(WCHAR)*16);
		for(int i = 0;i<16;i++) {
			name[i] = rand();
		}
		name[15] = 0;
	}
	void Destroy() {

		allocator->unallocMem(name);
	}
	///Allows the active thread to acquire control of a mutex
	void* AcquireMutex(int timeout) {

			void* handle = CreateMutexW(NULL,true,name);
			WaitForSingleObject(handle,timeout);
	return handle;
	}
	void UnacquireMutex(void* mutex) {
		CloseHandle(mutex);

	}
};
typedef void(*MThreadProc)(void*);
struct InternaltPassDat {
	MThreadProc proc;
	void* xmitData;
};

class Thread:public RefcountedObject {
private:
	MThreadProc callback;
	static DWORD WINAPI nativecallback(void* data) {
		InternaltPassDat* lthread = (InternaltPassDat*)data;
		lthread->proc(lthread->xmitData);
		return 0;
	}
	HANDLE hnd;
public:
	Thread(MThreadProc sndtar, MemAllocator* allocator):RefcountedObject(allocator) {
		callback = sndtar;
	}
	void Destroy() {
		CloseHandle(hnd);
	}
	void Start(void* sender) {

		InternaltPassDat* mdat = new(allocator->allocMem(sizeof(InternaltPassDat)))InternaltPassDat();
		mdat->proc = callback;
		mdat->xmitData = sender;
		hnd = CreateThread(NULL,0,&nativecallback,mdat,0,NULL);

	}
};
#endif
} /* namespace System */
#endif /* THREAD_H_ */
