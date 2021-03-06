#include "StdString.h"

using namespace icu;
StdString::StdString()
{
    //ctor
    internstr = UnicodeString();
}
StdString::StdString(UChar* other) {

internstr = other;
}
StdString StdString::operator+(UChar other) {
StdString newstr = StdString();
newstr.internstr = internstr+other;
return newstr;
}
StdString::StdString(const UChar* other) {

internstr = (const UChar*)other;
}
StdString::StdString(char* existing) {
	internstr = UnicodeString::fromUTF8(StringPiece(existing));
}
StdString::StdString(const char* existing) {
	internstr = UnicodeString::fromUTF8(StringPiece(existing));
}
StdString StdString::operator+(StdString other) {
StdString newstr = StdString();
newstr.internstr = internstr+other.internstr;
return newstr;
}
StdString::~StdString()
{
    //dtor
}
int32_t StdString::Length() {
return internstr.length();
}
UChar* StdString::cstr() {
return (UChar*)internstr.getTerminatedBuffer();
}
StdString StdString::operator+(UChar* other) {
//TODO: Implement this
StdString mstr;
mstr.internstr = internstr+other;
return mstr;
}
void StdString::operator +=(UChar* other) {
internstr+=other;
}
void StdString::operator +=(UChar other) {
internstr+=other;
}
void StdString::AppendLineBreak() {
internstr+="\n";
}
char* StdString::rstr() {
	char* ibuff = new char[internstr.length()];
	internstr.extract(0,internstr.length(),ibuff,(const char*)NULL);
	return ibuff;

}

