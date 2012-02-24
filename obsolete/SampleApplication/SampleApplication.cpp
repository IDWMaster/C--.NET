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
using namespace System::Reflection;
int main() {
	StdString sampletext = "Opening file...\0";
Array<byte> mtest = Array<byte>((byte*)sampletext.cstr(),sampletext.Length()*sizeof(UChar));
//mtest.GetArray()[0] = 8;
Console::WriteLine((UChar*)mtest.GetArray());

	FileStream mstr = FileStream("assembly.txt");
	AssemblyParser mparser;
	mparser.Load(&mstr);
	return 0;
}
