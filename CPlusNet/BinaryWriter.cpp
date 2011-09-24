/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "BinaryWriter.h"
namespace System {
    namespace IO {
BinaryWriter::BinaryWriter(Stream* stream)
{
    underlyingstream = stream;

}
void BinaryWriter::Write(StdString text) {
int len = text.Length();
//Take the pointer to the int with sizeof(int)
byte* header = (byte*)&len;
byte* data = (byte*)(void*)text.cstr();
underlyingstream->Write(header,0,sizeof(int));
underlyingstream->Write(data,0,sizeof(char)*len);

}
void BinaryWriter::Write(int value) {
byte* data = (byte*)&value;
underlyingstream->Write(data,0,sizeof(int));
}
void BinaryWriter::Write(long value) {
byte* data = (byte*)&value;
underlyingstream->Write(data,0,sizeof(long));

}
void BinaryWriter::Write(float value) {
byte* data = (byte*)&value;
underlyingstream->Write(data,0,sizeof(float));

}
void BinaryWriter::Write(double value) {
byte* data = (byte*)&value;
underlyingstream->Write(data,0,sizeof(double));

}
void BinaryWriter::Write(Array<byte> value) {
underlyingstream->Write(value.internarray,0,value.Length);
}
BinaryWriter::~BinaryWriter()
{
    //dtor
}
    }
}
