#include "RuntimeLib.h"
void main() {
	auto LE1 = NewGlobalEnvironment(new ObjectType(), new ObjectType());
	auto R1 = new StringType("x");
	auto R2 = LE1->_getEnvRec()->CreateMutableBinding(R1, new BooleanType(false));
	auto R3 = new NumberType(42);
	auto R4 = new StringType("x");
	auto R5 = ResolveBinding(R4, LE1);
	auto R6 = InitializeReferencedBinding(R5, R3);
	auto R7 = new StringType("x");
	auto R8 = ResolveBinding(R7, LE1);
	auto R9 = _log(R8);
}
