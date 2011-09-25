
/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#ifndef BINARYWRITER_H
#define BINARYWRITER_H
#include <string>
#include "Stream.h"
#include "include/StdString.h"
#include "Array.h"
namespace System {
    namespace IO {
class BinaryWriter
{
    public:
        /** Default constructor */
        BinaryWriter(Stream* stream);
        /** Default destructor */
        virtual ~BinaryWriter();
        void Write(StdString text);
        void Write(int value);
        void Write(long value);
        void Write(float value);
        void Write(double value);
        void Write(Array<byte> value);
        Stream* underlyingstream;

    protected:
    private:

};
    }
}
#endif // BINARYWRITER_H
