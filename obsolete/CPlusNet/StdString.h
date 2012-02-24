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
        StdString();
        StdString(UChar* existing);

        StdString(const UChar* existing);
        StdString(char* existing);
        StdString(const char* existing);
        //Why doesn't this work?????
        virtual ~StdString();
        int Length();

        StdString operator +(StdString other);
        StdString operator +(UChar* other);
        StdString operator +(UChar other);
        //The += and the -= operators are perhaps the most useless feature
        //in C++. += and -= should be able to be inferred from +, -, and equal operators
        void operator +=(UChar* other);
        void operator +=(UChar other);
        char* rstr();
        UChar* cstr();
        void AppendLineBreak();
    protected:
    private:
    icu::UnicodeString internstr;
};

#endif // STDSTRING_H
