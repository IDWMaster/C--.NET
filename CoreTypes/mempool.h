/*
 * mempool.h
 *
 *  Created on: Jan 10, 2012
 *      Author: webadm
 */


#ifndef MEMPOOL_H
#define MEMPOOL_H
#define platformptr unsigned long long
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#undef byte
#include <windows.h>
struct memsegment {
platformptr mem_begin;
platformptr mem_end;
};
struct memregion {
	platformptr length;
	platformptr offset;
	memsegment* segment;
	bool allocated;
};

class MemAllocator {
private:
	wchar_t* mname;
public:
	std::vector<memsegment*> regions;
	std::vector<memregion> memregions;
	~MemAllocator() {
		for(int i = 0;i<regions.size();i++) {
			delete (char*)regions[i]->mem_begin;
			delete regions[i];
		}
	}
	MemAllocator(size_t dsize) {
		mname = new wchar_t[16];
		for(int i = 0;i<16;i++) {
			mname[i] = rand();
		}
		mname[15] = 0;
		memregion defaultregion;
		defaultregion.allocated = false;
		defaultregion.length = dsize;
		defaultregion.offset = 0;
		memsegment* seg0 = new memsegment();
		seg0->mem_begin = (platformptr)(char*)malloc(dsize);
		seg0->mem_end = seg0->mem_begin+dsize;
		defaultregion.segment = seg0;
		regions.push_back(seg0);
		memregions.push_back(defaultregion);
	};
	void unallocMem(void* ptr) {
		//figure out data position
		HANDLE mdle = CreateMutexW(NULL,TRUE,mname);
		WaitForSingleObject(mdle,INFINITE);
		platformptr data;
		for(int i = 0;i<regions.size();i++) {
			if(((platformptr)ptr)>=regions[i]->mem_begin&&((platformptr)ptr)<regions[i]->mem_end) {
				data = regions[i]->mem_begin;
			break;
			}
		}
	for(int i = 0;i<memregions.size();i++) {
		platformptr calculatedoffset = ((platformptr)data)+memregions[i].offset;
		//platformptr calculatedend = calculatedoffset+memregions[i].length;
		if((platformptr)ptr == calculatedoffset) {
			memregions[i].allocated = false;
			CloseHandle(mdle);
			return;
		}
	}
	CloseHandle(mdle);
	throw "MemoryNotFound";
	}

	void createSegment(platformptr size) {
	memregion defaultregion;
		defaultregion.allocated = false;
		defaultregion.length = size;
		defaultregion.offset = 0;
		memsegment* seg0 = new memsegment();
		seg0->mem_begin = (platformptr)(char*)malloc(size);
		seg0->mem_end = seg0->mem_begin+size;
		defaultregion.segment = seg0;
		regions.push_back(seg0);
		memregions.push_back(defaultregion);
	}
	void* allocMem(size_t size) {
		HANDLE mdle = CreateMutexW(NULL,TRUE,mname);
				WaitForSingleObject(mdle,INFINITE);

mcplr:
int mv = memregions.size();
		for(int i = 0;i<mv;i++) {
			if(!memregions[i].allocated && memregions[i].length>=size) {
				size_t freedmem = memregions[i].length-size;
				char* data = (char*)(void*)memregions[i].segment->mem_begin;
				memregions[i].allocated = true;
				memregions[i].length = size;

				if(freedmem !=0) {
				//Create a new block representing the free memory
				memregion freedregion;
				freedregion.allocated = false;
				freedregion.length = freedmem;
				freedregion.segment = memregions[i].segment;
				freedregion.offset = memregions[i].offset+memregions[i].length;
				memregions.push_back(freedregion);
				}
				CloseHandle(mdle);
				return data+memregions[i].offset;
			}
		}
		createSegment(size*20);
		goto mcplr;
		throw "InsufficientMemory";
	}


};
template <class T>
class FastAllocator {
public:
	MemAllocator* ilock;
	FastAllocator(MemAllocator* internalloc) {
	ilock = internalloc;
	};
	T* allocate(size_t mlen) {
		//Allocate in chunks of 1024 bytes
		//starting at 1024
		size_t count = mlen*sizeof(T);
		int64_t blocksize = 1024;
		while(blocksize<count) {
			blocksize+=1024;
		}
		return (T*)ilock->allocMem(count);
	}
	void deallocate(T* ptr) {
		ilock->unallocMem(ptr);
	}
};
template <class T>
class FastArray {
public:
	FastAllocator<T>* allocator;
	T* data;
	FastArray(FastAllocator<T>* allo) {
		allocator = allo;
		data = allocator->allocate(15);
	}
	~FastArray() {
		allocator->deallocate(data);
	}
	T& operator[](int32_t index) {
		return data[index];
	}

};

#endif
