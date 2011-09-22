#ifndef WINCORE_H
#define WINCORE_H
#if WIN32
#include <stdlib.h>
//Yeah. Deprecated. That's Windows for you.
void Sleep(int milliseconds) {
_sleep(milliseconds);
}
#endif
#endif // WINCORE_H
