/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#pragma once
#include <stdlib.h>
typedef unsigned char byte;
#pragma once
#include "Exception.h"
#include "Array.h"
#include "CProperty.h"
#ifndef STREAM_H
#define STREAM_H
namespace System {
    namespace IO {
class Stream
{
    public:
        Stream();
        virtual ~Stream();
        //= 0 to declare pure virtual function (similar to abstract keyword in C#)

        //Reads data from the underlying device
        virtual int Read(Array<byte> data, int offset, int len) =0;
        //Writes data to the underlying device, buffering if necessary
        virtual void Write(Array<byte> data, int offset, int len) =0;
        //Clears all buffers and flushes data to the underlying device
        virtual void Flush() =0;
        virtual long GetLen() = 0;
        virtual void SetLen(long value) =0;
        virtual long GetPos() = 0;
        virtual void SetPos(long value)= 0;
    protected:
    private:
};
    }
}
#endif // STREAM_H
