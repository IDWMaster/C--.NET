/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "Console.h"
#include <stdio.h>
#include "Array.h"
void Console::Write(StdString text) {
printf(text.cstr());
}
using namespace std;
StdString Console::ReadLine() {
char recententry;
StdString retval;
while(true) {
recententry = getchar();

if(recententry == '\r' || recententry == '\n') {
return retval;
}
retval+=recententry;
}

}
void Console::WriteLine(StdString text) {
printf((char*)(text+"\n").cstr());
}
