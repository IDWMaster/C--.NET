/*
 * AssemblyParser.h
 *
 *  Created on: Nov 30, 2011
 *      Author: Brian Bosak
 */

#ifndef ASSEMBLYPARSER_H_
#define ASSEMBLYPARSER_H_
#include "StdString.h"
#include "Array.h"
#include "Stream.h"
#include "BinaryReader.h"
#include "BaseObject.h"
namespace System {
namespace Reflection {

class ManagedType {
public:
	StdString Name;
	Array<ManagedType>* embeddedTypes;
	int64_t TypeID;
	int64_t BaseType;
	//TODO: Implement this
   ~ManagedType();

};
class AssemblyParser {
public:
	Array<ManagedType>* Types;
	void Load(System::IO::Stream* stream);
	AssemblyParser();
	~AssemblyParser();
};

} /* namespace Reflection */
} /* namespace System */
#endif /* ASSEMBLYPARSER_H_ */
