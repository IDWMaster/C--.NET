#include "StdString.h"

StdString::StdString()
{
    //ctor
    internstr = std::string();

}
StdString::StdString(char* other) {

internstr = other;
}
StdString StdString::operator+(char other) {
StdString newstr = StdString();
newstr.internstr = internstr+other;
return newstr;
}
StdString::StdString(const char* other) {

internstr = (const char*)other;
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
int StdString::Length() {
return (int)internstr.length();
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
void StdString::operator +=(char other) {
internstr+=other;
}
void StdString::AppendLineBreak() {
internstr+="\n";
}

