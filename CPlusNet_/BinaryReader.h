/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef BINARYREADER_H
#define BINARYREADER_H
#include "Stream.h"
#include "stdstring.h"
namespace System {
namespace IO {
class BinaryReader
{
    public:
        /** Default constructor */
        BinaryReader(Stream* input);
        Stream* underlyingstream;
        ///Reads a 32-bit signed integer from the input stream
        int ReadInt32();
        ///Reads a 64-bit signed integer from the input stream
        long ReadInt64();
        ///Reads a single-precision floating point number from the input stream
        float ReadFloat();
        ///Reads a double-precision floating point number from the input stream
        double ReadDouble();
        ///Reads an StdString from the input stream (prefixed with a 32-bit signed integer)
        StdString ReadString();
    protected:
    private:
};
}
}
#endif // BINARYREADER_H
