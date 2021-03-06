/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "BinaryReader.h"
#include <iostream>
namespace System {
namespace IO {
Array<byte> BinaryReader::ReadBytes(int count) {
	Array<byte> mray = Array<byte>(count);
	underlyingstream->Read(mray,0,mray.Length);
}
BinaryReader::BinaryReader(Stream* stream)
{
    //ctor
    underlyingstream = stream;
}
int32_t BinaryReader::ReadInt32() {
Array<byte> data = Array<byte>(new byte[sizeof(int)],sizeof(int));
underlyingstream->Read(data,0,data.Length);
int retval = *(int*)(void*)data.GetArray();
return retval;
}
int64_t BinaryReader::ReadInt64() {
Array<byte> data = Array<byte>(new byte[sizeof(long)],sizeof(long));
underlyingstream->Read(data,0,data.Length);
long retval = *(long*)data.GetArray();
return retval;
}
float BinaryReader::ReadFloat() {
Array<byte> data = Array<byte>(new byte[sizeof(float)],sizeof(float));
underlyingstream->Read(data,0,data.Length);
float retval = *(float*)data.GetArray();
return retval;
}
double BinaryReader::ReadDouble() {
Array<byte> data = Array<byte>(new byte[sizeof(double)],sizeof(double));
underlyingstream->Read(data,0,data.Length);
double retval = *(double*)data.GetArray();
return retval;
}
StdString BinaryReader::ReadString() {

	int32_t len = ReadInt32();
Array<byte> data = Array<byte>((sizeof(UChar)*len));

underlyingstream->Read(data,0,data.Length);
StdString retval = (UChar*)data.GetArray();

return retval;
}
}
}
