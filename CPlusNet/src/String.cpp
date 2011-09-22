#include "String.h"

String::String()
{
    //ctor
}

String::~String()
{
    //dtor
}
String String::operator+(String other) {

}
String& String::operator=(const String& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
