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
BinaryReader::BinaryReader(Stream* stream)
{
    //ctor
    underlyingstream = stream;
}
int BinaryReader::ReadInt32() {
Array<byte> data = Array<byte>(new byte[sizeof(int)],sizeof(int));
underlyingstream->Read(data,0,data.Length);
int retval = *(int*)(void*)data.internarray.data();
return retval;
}
long BinaryReader::ReadInt64() {
Array<byte> data = Array<byte>(new byte[sizeof(long)],sizeof(long));
underlyingstream->Read(data,0,data.Length);
long retval = *(long*)data.internarray.data();
return retval;
}
float BinaryReader::ReadFloat() {
Array<byte> data = Array<byte>(new byte[sizeof(float)],sizeof(float));
underlyingstream->Read(data,0,data.Length);
float retval = *(float*)data.internarray.data();
return retval;
}
double BinaryReader::ReadDouble() {
Array<byte> data = Array<byte>(new byte[sizeof(double)],sizeof(double));
underlyingstream->Read(data,0,data.Length);
double retval = *(double*)data.internarray.data();
return retval;
}
StdString BinaryReader::ReadString() {

	Array<byte> data = Array<byte>(new byte[sizeof(int)],sizeof(int));
	underlyingstream->Read(data,0,sizeof(int));
int32_t len = *(int32_t*)(data.internarray.data());
data.Resize(sizeof(UChar)*len);

underlyingstream->Read(data,0,data.Length);
StdString retval = (UChar*)data.internarray.data();

return retval;
}
}
}
