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
#include <iostream>
void Console::Write(StdString text) {
std::cout<<text.rstr();
}
using namespace std;
void Console::Write(int val) {
	std::cout<<val;
}
StdString Console::ReadLine() {
char recententry;
StdString retval;
while(true) {
recententry = getchar();

if(recententry == '\r' || recententry == '\n') {
break;
}
retval+=recententry;
}
return retval;
}
void Console::WriteLine(StdString text) {
std::cout<<((text+"\n").rstr());
}
