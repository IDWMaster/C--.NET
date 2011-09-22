#include <iostream>
#include <StdString.h>
#include "wincore.h"
#include <Array.h>
#if WIN32

#endif
using namespace std;
//TODO: I know there's some way to dynamically link
//user32.dll and kernel32.dll for WINDOWS ONLY using a pre-processor directive here
//The question is what that directive is
int main()
{


    StdString mystr = (char*)"hello";
    mystr +=(char*)" world";
    cout<<mystr.cstr()<<endl;
    Array<char> myray(1024);

    cout<<"Unit test(s) completed with no errors";
    Sleep(2000);
    return 0;
}
