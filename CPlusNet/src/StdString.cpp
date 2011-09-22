#include "../Include/StdString.h"

StdString::StdString()
{
    //ctor
    internstr = std::string();

}
StdString::StdString(char* other) {

internstr = other;
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
char* StdString::cstr() {
return (char*)internstr.c_str();
}
StdString StdString::operator+(char* other) {
//TODO: Implement this
StdString mstr;
mstr.internstr = internstr+other;
return mstr;
}
void StdString::operator +=(char* other) {
internstr+=other;
}