/**
Copyleft 2011 Brian Bosak - Some rights reserved
Please take the courtesy of placing this notice on all reproductions/derivitives of this
code. This may perhaps be the world's biggest C++ abstraction library
Contributions are welcome. Place your name and your contribution below this line
to indicate your contribution to the project.
*/
/*
 * StreamWriter.h
 *
 *  Created on: Oct 4, 2011
 *      Author: webadm
 */

#ifndef STREAMWRITER_H_
#define STREAMWRITER_H_
#include "Stream.h"
#include "StdString.h"
namespace System {
namespace IO {

class StreamWriter {
public:
	~StreamWriter();
	StreamWriter(Stream* istr);
	void Write(StdString text);
	void WriteLine(StdString text);
private:
	void Initialize();
	void Dispose();
	Stream* internstream;
};

} /* namespace IO */
} /* namespace System */
#endif /* STREAMWRITER_H_ */
