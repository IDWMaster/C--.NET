#pragma once
#include <stdlib.h>
typedef unsigned char byte;
#include "Array.h"
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
        virtual int Read(Array<byte> data, int offset, int len) = 0;
        //Writes data to the underlying device, buffering if necessary
        virtual void Write(Array<byte> data, int offset, int len) = 0;
        //Clears all buffers and flushes data to the underlying device
        virtual void Flush() = 0;
    protected:
    private:
};
    }
}
#endif // STREAM_H
