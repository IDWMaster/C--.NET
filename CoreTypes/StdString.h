/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivatives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef STDSTRING_H
#define STDSTRING_H
#include <string>
#include <unicode/unistr.h>

class StdString
{
    public:
        StdString() {
        	internstr = UnicodeString();
        }
        StdString(UChar* existing) {
        	internstr = existing;
        }

        StdString(const UChar* existing) {
        	internstr = (const UChar*)existing;
        }
        StdString(char* existing) {
        	internstr = UnicodeString::fromUTF8(StringPiece(existing));

        }
        StdString(const char* existing) {
        	internstr = UnicodeString::fromUTF8(StringPiece(existing));

        }
        //Why doesn't this work?????
        virtual ~StdString() {

        }
        int Length() {
        	return internstr.length();
        }

        StdString operator +(StdString other) {
        	StdString newstr = StdString();
        	newstr.internstr = internstr+other.internstr;
        	return newstr;
        }
        StdString operator +(UChar* other) {
        	StdString mstr;
        	mstr.internstr = internstr+other;
        	return mstr;
        }
        StdString operator +(UChar other) {
        	StdString newstr = StdString();
        	newstr.internstr = internstr+other;
        	return newstr;
        }
        //The += and the -= operators are perhaps the most useless feature
        //in C++. += and -= should be able to be inferred from +, -, and equal operators
        void operator +=(UChar* other) {
        	internstr+=other;
        }
        void operator +=(UChar other) {
        	internstr+=other;

        }

        char* rstr() {
        	char* ibuff = new char[internstr.length()];
        		internstr.extract(0,internstr.length(),ibuff,(const char*)NULL);
        		return ibuff;
        }
        UChar* cstr() {
        	return (UChar*)internstr.getTerminatedBuffer();
        }
        void AppendLineBreak() {
        	internstr+="\n";
        }
    protected:
    private:
    icu::UnicodeString internstr;
};

#endif // STDSTRING_H
