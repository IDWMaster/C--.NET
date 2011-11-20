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
Array<byte> data = new byte[sizeof(int)];
underlyingstream->Read(data,0,data.Length);
int retval = *(int*)(void*)data.internarray;
return retval;
}
long BinaryReader::ReadInt64() {
Array<byte> data = new byte[sizeof(long)];
underlyingstream->Read(data,0,data.Length);
long retval = *(long*)data.internarray;
return retval;
}
float BinaryReader::ReadFloat() {
Array<byte> data = new byte[sizeof(float)];
underlyingstream->Read(data,0,data.Length);
float retval = *(float*)data.internarray;
return retval;
}
double BinaryReader::ReadDouble() {
Array<byte> data = new byte[sizeof(double)];
underlyingstream->Read(data,0,data.Length);
double retval = *(double*)data.internarray;
return retval;
}
StdString BinaryReader::ReadString() {

	Array<byte> data = new byte[sizeof(int)];
	underlyingstream->Read(data,0,sizeof(int));
int len = *(int*)(data.internarray);
data.Resize(sizeof(char)*len);

underlyingstream->Read(data,0,data.Length);
return "NULL";
StdString retval = (char*)data.internarray;

return retval;
}
}
}
