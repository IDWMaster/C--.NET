
#ifndef STRING_H
#define STRING_H


class String
{
    public:
        String();
        virtual ~String();
        String& operator=(const String& other);
        String operator+(const String other);
    protected:
    private:



};

#endif // STRING_H
