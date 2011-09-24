/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "FileStream.h"
#include "include/StdString.h"
#include <stdio.h>
FileStream::FileStream(FILE* nativehandle)
{
    //ctor
    fpointer = nativehandle;
    ipos = 0;
    GetLen();

}
long FileStream::GetLen() {
fseek(fpointer,0,SEEK_END);
flen = (long)ftell(fpointer);
fseek(fpointer,ipos,SEEK_SET);
return flen;
}
FileStream::~FileStream() {
fclose(fpointer);
}
void FileStream::SetLen(long value) {
//TODO: Currently not implemented

}
long FileStream::GetPos() {
return ipos;
}
void FileStream::SetPos(long value) {
ipos = value;
fseek(fpointer,value,SEEK_SET);
}
int FileStream::Read(Array<byte> data, int offset, int count) {
int available;
if(flen<count) {
available = flen;
} else {
available = count;
}
int retval = (int)fread(data.internarray+offset,1,(size_t)available,fpointer);
ipos = ftell(fpointer);
return retval;
}
void FileStream::Write(Array<byte> data, int offset, int count) {

fwrite(data.internarray+offset,1,(size_t)count,fpointer);

ipos = ftell(fpointer);
if(ipos>flen) {
flen = ipos;
}
return;
}
void FileStream::Flush() {
fflush(fpointer);
return;
}
FileStream::FileStream(StdString filename) {
    ipos = 0;
 fpointer = fopen(filename.cstr(),"r+b");
    GetLen();
}
