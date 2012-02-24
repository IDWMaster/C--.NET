//============================================================================
// Name        : TestApp.cpp
// Author      : Brian Bosak
// Version     :
// Copyright   : Copyleft 2012 Brian Bosak -- Some rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <ThreadPool.h>

static void target(void* sender) {
printf("Hello world!\n");
}
using namespace System;
int main() {

	MemAllocator mlocator (1024);
	ThreadPool pool(&mlocator,5);
	for(int i = 0;i<1;i++) {
		printf("Item queued\n");
	pool.QueueUserWorkItem(&target,NULL);

	}
	Sleep(50000);
	return 0;
}
