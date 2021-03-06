/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "FileStream.h"
#include "StdString.h"
#include <stdio.h>
#include "Console.h"
FileStream::~FileStream() {
	fclose(fpointer);
}
long FileStream::GetLen() {
fseek(fpointer,0,SEEK_END);
flen = long(ftell(fpointer));
fseek(fpointer,ipos,SEEK_SET);
return flen;
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
size_t available;
if(flen-ipos<count) {

available = flen-ipos;
} else {
available = count;
}

int retval = (int)fread(data.GetArray()+(size_t)offset,(size_t)1,available,fpointer);
ipos = ftell(fpointer);

return retval;
}
void FileStream::Write(Array<byte> data, int offset, int count) {

int dbg = fwrite(data.GetArray()+(size_t)offset,(size_t)1,(size_t)count,fpointer);
ipos +=count;
if(ipos>flen) {
flen = ipos;
}
}
void FileStream::Flush() {
fflush(fpointer);
}
FileStream::FileStream(StdString filename) {
    ipos = 0;

Console::WriteLine(StdString("Opening ")+filename);
 fpointer = fopen(filename.rstr(),"r+b");
    GetLen();
}
