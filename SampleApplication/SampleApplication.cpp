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
	StdString testring = StdString("Hello world!").cstr();
	Console::WriteLine(testring);
	FileStream* mstr = new FileStream("hi.txt");


	//This doesn't work
	//Array<byte> mray = Array<byte>((byte*)testring.cstr(),testring.Length()*sizeof(UChar));
//	mstr->Write(mray,0,testring.Length()*sizeof(UChar));
	//This works; but it's politically incorrect
	char* mt = (char*)"Hello world!";
	mstr->Write(Array<byte>((byte*)mt,sizeof(char)*12),0,sizeof(char)*12);

	return 0;
}
