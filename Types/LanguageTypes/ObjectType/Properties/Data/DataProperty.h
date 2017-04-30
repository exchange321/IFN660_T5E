#pragma once
#include <Types/LanguageTypes/LanguageTypes.h>
#include "Types/LanguageTypes/UndefinedType/UndefinedType.h"
#include <Types/LanguageTypes/ObjectType/Properties/Properties.h>

class DataProperty : public Property {
	LanguageType *Value;
	bool Writable;
	bool Enumerable;
	bool Configurable;
public:
	explicit DataProperty(LanguageType *_Value = new UndefinedType(), bool _Writable = false, bool _Emumerable = false, bool _Configurable = false) : Value(_Value),
	                                                                                                                                                  Writable(_Writable),
	                                                                                                                                                  Enumerable(_Emumerable),
	                                                                                                                                                  Configurable(_Configurable) { };
};
