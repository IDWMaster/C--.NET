/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
/*
 * StreamWriter.cpp
 *
 *  Created on: Oct 4, 2011
 *      Author: webadm
 */

#include "StreamWriter.h"
#include "Array.h"
namespace System {
namespace IO {
void StreamWriter::Initialize() {

}
void StreamWriter::Dispose() {

}
StreamWriter::~StreamWriter() {

}
StreamWriter::StreamWriter(Stream* str) {

internstream = str;

}
void StreamWriter::Write(StdString text) {

Array<byte> data = (byte*)text.cstr();
internstream->Write(data,0,data.Length);
}
void StreamWriter::WriteLine(StdString text) {
	StdString copy = text;
		copy.AppendLineBreak();
		Array<byte> data = (byte*)text.cstr();
		internstream->Write(data,0,data.Length);

}

} /* namespace IO */
} /* namespace System */
