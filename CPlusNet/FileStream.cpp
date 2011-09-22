#include "FileStream.h"
#include "include/StdString.h"
FileStream::FileStream(FILE nativehandle)
{
    //ctor
    fpointer = nativehandle;
}

FileStream::~FileStream()
{
    //dtor
}
int FileStream::Read(Array<byte> data, int offset, int count) {
return NULL;
}
void FileStream::Write(Array<byte> data, int offset, int count) {
}
void FileStream::Flush() {

}
