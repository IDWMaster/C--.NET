#include "Stream.h"
#include "include/StdString.h"
#ifndef FILESTREAM_H
#define FILESTREAM_H


class FileStream : public System::IO::Stream
{
    public:
        /** Default constructor */
        FileStream(FILE nativehandle);
        int Read(Array<byte> data, int offset, int count);
        void Write(Array<byte> data, int offset, int count);
        void Flush();
        /** Default destructor */
        virtual ~FileStream();
    protected:
    private:
    FILE fpointer;
};

class File {
public:

static FileStream Open(StdString filename);
};

#endif // FILESTREAM_H
