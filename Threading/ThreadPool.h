/*
 * ThreadPool.h
 *
 *  Created on: Feb 9, 2012
 *      Author: webadm
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <Thread.h>
#include <Array.h>
#include <RefcountedObject.h>
namespace System {
class InternalTaskObj {
public:

	void(*callback)(void* sender);
	void* data;
	bool operator ==(InternalTaskObj other) {
			return callback == other.callback && data == other.data;

	};
	bool operator !=(InternalTaskObj other) {
		return !(callback == other.callback && data == other.data);

	}
};
class PoolableThread:public RefcountedObject {
public:
	Thread* nativethread;
	Mutex* waitObj;
	Mutex* syncobj;
	Array<InternalTaskObj>* tasks;
	bool* isrunning;
	static void callback(void* sender) {
		PoolableThread thisptr = *(PoolableThread*)sender;
		while(*isrunning) {
			void* handle = 0;
			if(*(thisptr.tasks->length) == 0) {
			handle = thisptr.waitObj->AcquireMutex(INFINITE);
			thisptr.waitObj->UnacquireMutex(handle);

		}
		//lock(tasks) {
					handle = thisptr.syncobj->AcquireMutex(INFINITE);
					InternalTaskObj task;
					bool hastask = false;
					if(*(thisptr.tasks->length)>0) {
					task = (*tasks)[0];
					hastask = true;
					task.callback(task.data);
					thisptr.tasks->Remove(task);
					}
					thisptr.syncobj->UnacquireMutex(handle);
					//}
					if(hastask) {
						task.callback(task.data);
					}
		}
	}
	void* syncHandle;
	PoolableThread(MemAllocator* allocator):RefcountedObject(allocator) {
		*isrunning = true;
		nativethread = new(allocator->allocMem(sizeof(Thread)))Thread(callback,allocator);
		waitObj = new(allocator->allocMem(sizeof(Mutex)))Mutex(allocator);
		tasks = new(allocator->allocMem(sizeof(Array<InternalTaskObj>)))Array<InternalTaskObj>(0,allocator);
		syncobj = new(allocator->allocMem(sizeof(Mutex)))Mutex(allocator);
		syncHandle = 0;
		nativethread->Start(this);
	}
	void Kill() {
		*isrunning = false;
		if(syncHandle !=0) {
		waitObj->UnacquireMutex(syncHandle);
		}
	}
	void Destroy() {
		nativethread->~Thread();
		waitObj->~Mutex();
		tasks->~Array<InternalTaskObj>();
		syncobj->~Mutex();
	}
};
class ThreadPool:public RefcountedObject {
private:
	Array<PoolableThread>* threads;
public:
	ThreadPool(MemAllocator* allocator, int threadcount):RefcountedObject(allocator) {
		threads = new(allocator->allocMem(sizeof(Array<PoolableThread>)))Array<PoolableThread>(threadcount,allocator);
		Array<PoolableThread> cachedThreadList = *threads;
		for(int i = 0;i<threadcount;i++) {
			cachedThreadList[i] = PoolableThread(allocator);
		}
	}
	void QueueUserWorkItem(void(*target)(void*), void* arg) {
		InternalTaskObj task;
		task.callback = target;
		task.data = arg;
		int leastnum = 9999999;
		PoolableThread* leastval = NULL;
		Array<PoolableThread> cachedThreadList = *threads;
		for(int i = 0;i<*(threads->length);i++) {
			if(*(cachedThreadList[i].tasks->length)<leastval) {
				leastval = &cachedThreadList[i];
			}
		}
		void* mutex = leastval->syncobj->AcquireMutex(INFINITE);
		leastval->tasks->Resize((*(leastval->tasks->length))+1);
		(*leastval->tasks)[(*(leastval->tasks->length))-1] = task;
		leastval->syncobj->UnacquireMutex(mutex);
		if(leastval->syncHandle !=0) {
		leastval->waitObj->UnacquireMutex(leastval->syncHandle);
		}
		leastval->syncHandle = leastval->waitObj->AcquireMutex(INFINITE);

	}
	void Destroy() {
		Array<PoolableThread> cached = *threads;
		for(int i = 0;i<*cached.length;i++) {
			cached[i].Kill();
		}
		threads->~Array<PoolableThread>();
		allocator->unallocMem(threads);
	}
};
};

#endif /* THREADPOOL_H_ */