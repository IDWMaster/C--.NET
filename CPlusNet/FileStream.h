/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
#include "Stream.h"
#include "include/StdString.h"
#include <stdlib.h>
#ifndef FILESTREAM_H
#define FILESTREAM_H


class FileStream : public System::IO::Stream
{
    public:
        /** Default constructor */

        FileStream(StdString filename);
        ///Reads data from the input strema
        int Read(Array<byte> data, int offset, int count);
        ///Writes data to the output stream
        void Write(Array<byte> data, int offset, int count);
        ///Clears any buffers and flushes its contents to the underlying device
        void Flush();
        ///Gets the length of the stream
        long GetLen();
        ///Sets the length of the stream
        void SetLen(long value);
        ///Gets the position of the stream
        long GetPos();
        ///Sets the position of the stream
        void SetPos(long value);
        /** Default destructor */
        ~FileStream();
    protected:
    private:
    FILE* fpointer;
    int flen;
    void updatelen();
    long ipos;
};

#endif // FILESTREAM_H
