/*
 * DiagnosticRunner.cpp
 *
 *  Created on: Jan 11, 2012
 *      Author: webadm
 */

#include "DiagnosticRunner.h"
#include "Dictionary.h"
#include <stdlib.h>
namespace System {

DiagnosticRunner::DiagnosticRunner() {
	//Stack-allocated allocator (destroyed when tests are finished running)
	MemAllocator allocator(1024);
	Dictionary<int,int> mdict(&allocator);
	mdict.Add(0,1);
	mdict.Add(3,5);
	int firstint = mdict[0];
	int secondint = mdict[3];

}

DiagnosticRunner::~DiagnosticRunner() {
	// TODO Auto-generated destructor stub
}

} /* namespace System */
;
