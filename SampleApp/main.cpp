/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/

#include <iostream>
#include <windows.h>
#include <clrheader.h>
using namespace std;
using namespace System::IO;
void athread(void* args) {
FileStream mstr = FileStream("test.txt");
    BinaryWriter mwriter (&mstr);
    mwriter.Write("Hello world! Welcome to the NEW C++");
    mstr.Flush();

    BinaryReader mreader (&mstr);
    mstr.SetPos(0);
    Console::WriteLine(mreader.ReadString());
    Console::WriteLine("Hello world!");

}
using namespace System::Threading;
int main()
{

    Thread mthread (&athread);
    mthread.Start(NULL);
    while(true) {
    StdString tstr = Console::ReadLine();
    Console::WriteLine((StdString)"You typed: "+tstr);
    }
    return 0;
}
