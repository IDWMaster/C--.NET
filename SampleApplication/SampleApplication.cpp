//============================================================================
// Name        : SampleApplication.cpp
// Author      : Brian Bosak
// Version     : 0.1
// Copyright   : Copyleft 2011 Brian Bosak - Some rights reserved
//============================================================================


#include <CLRHeader.h>
#include <FileStream.h>
using namespace System;
using namespace System::IO;
int main() {


	FileStream* mstr = new FileStream("hi.txt");



	StdString testring = StdString("Hello world!").cstr();
	UChar* mt = testring.cstr();
	mstr->Write(Array<byte>((byte*)mt,testring.Length()*sizeof(UChar)),0,testring.Length()*sizeof(UChar));
	return 0;
}
