//============================================================================
// Name        : SampleApplication.cpp
// Author      : Brian Bosak
// Version     : 0.1
// Copyright   : Copyleft 2011 Brian Bosak - Some rights reserved
//============================================================================


#include <CLRHeader.h>
#include <FileStream.h>
#include <stdio.h>
using namespace System;
using namespace System::IO;
int main() {
	StdString sampletext = "Opening file...\0";
Array<byte> mtest = Array<byte>((byte*)sampletext.cstr(),sampletext.Length()*sizeof(UChar));
//mtest.GetArray()[0] = 8;
Console::WriteLine((UChar*)mtest.GetArray());

	FileStream mstr = FileStream("hi.txt");
	//Array<byte> mray = Array<byte>(sizeof(UChar)*4);
	//mstr->Read(mray,0,mray.Length);
BaseObject<Array<byte> > myray = new Array<byte>(mstr.GetLen());
mstr.Read(*myray.GetObject(),0,myray->Length);
//fread(myray.GetArray()+(size_t)0,(size_t)1,(size_t)4*sizeof(UChar),mstr.fpointer);
Console::WriteLine((UChar*)myray->GetArray());
	return 0;
}
