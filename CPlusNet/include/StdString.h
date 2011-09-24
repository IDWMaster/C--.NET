#include <string>
#ifndef STDSTRING_H
#define STDSTRING_H


class StdString
{
    public:
        StdString();
        StdString(char* existing);
        StdString(const char* existing);
        //Why doesn't this work?????
        virtual ~StdString();
        int Length();

        StdString operator +(StdString other);
        StdString operator +(char* other);
        StdString operator +(char other);
        //The += and the -= operators are perhaps the most useless feature
        //in C++. += and -= should be able to be inferred from +, -, and equal operators
        void operator +=(char* other);
        void operator +=(char other);
        char* cstr();
    protected:
    private:
    std::string internstr;
};

#endif // STDSTRING_H
