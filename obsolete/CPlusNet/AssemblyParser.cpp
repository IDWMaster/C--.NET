/*
 * AssemblyParser.cpp
 *
 *  Created on: Nov 30, 2011
 *      Author: Brian Bosak
 */

#include "AssemblyParser.h"

namespace System {
namespace Reflection {
using namespace System::IO;
AssemblyParser::AssemblyParser() {


};

AssemblyParser::~AssemblyParser() {

};

void AssemblyParser::Load(Stream* stream) {
BinaryReader mreader = BinaryReader(stream);
int count = mreader.ReadInt32();
Types = Array<ManagedType>(count);
for(int i = 0;i<Types.Length;i++) {
	ManagedType ctype;
	ctype.Name = mreader.ReadString();
	ctype.embeddedTypes = Array<ManagedType>(mreader.ReadInt32());

}
};

} /* namespace Reflection */
} /* namespace System */
