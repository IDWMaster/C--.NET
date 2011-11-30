/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "BinaryWriter.h"
#include <iostream>
namespace System {
    namespace IO {
BinaryWriter::BinaryWriter(Stream* stream)
{
    underlyingstream = stream;

}
void BinaryWriter::Write(StdString text) {
int32_t len = text.Length();
//Take the pointer to the int with sizeof(int)
byte* header = (byte*)&len;
byte* data = (byte*)text.cstr();
underlyingstream->Write(Array<byte>(header,sizeof(int32_t)),0,sizeof(int32_t));
underlyingstream->Write(Array<byte>(data,sizeof(UChar)*len),0,sizeof(UChar)*len);

}
void BinaryWriter::Write(int value) {
byte* data = (byte*)(void*)&value;
underlyingstream->Write(Array<byte>(data,sizeof(int)),0,sizeof(int));
}
void BinaryWriter::Write(long value) {
byte* data = (byte*)&value;
underlyingstream->Write(Array<byte>(data,sizeof(long)),0,sizeof(long));

}
void BinaryWriter::Write(float value) {
byte* data = (byte*)&value;
underlyingstream->Write(Array<byte>(data,sizeof(float)),0,sizeof(float));

}
void BinaryWriter::Write(double value) {
byte* data = (byte*)&value;
underlyingstream->Write(Array<byte>(data,sizeof(double)),0,sizeof(double));

}
void BinaryWriter::Write(Array<byte> value) {
underlyingstream->Write(value,0,value.Length);
}
BinaryWriter::~BinaryWriter()
{
    //dtor
}
    }
}
