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
	UChar* chars = StdString("Hello world!").cstr();
	Console::WriteLine(StdString(chars));
	FileStream* mstr = new FileStream("hi.txt");
	BinaryWriter* mwriter = new BinaryWriter(mstr);
	mwriter->Write("Hello world!");
	mstr->Flush();
	BinaryReader* mreader = new BinaryReader(mstr);
	mstr->SetPos(0);
	//TODO: Get ReadString to work
	Console::WriteLine(mreader->ReadString());

	return 0;
}
