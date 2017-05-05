#include <RuntimeLib\Type\LanguageType\LanguageTypeFunc.h>

//=================Language Type Functions===================================
LanguageType* ToPrimative(LanguageType* input, LanguageType* preferredType) {
	if (dynamic_cast<UndefinedType *>(input))
		return input;
	if (dynamic_cast<NullType *>(input))
		return input;
	if (dynamic_cast<BooleanType *>(input))
		return input;
	if (dynamic_cast<NumberType *>(input))
		return input;
	if (dynamic_cast<StringType *>(input))
		return input;
	if (dynamic_cast<SymbolType *>(input))
		return input;
	/*if (auto _input = dynamic_cast<ObjectType *>(input))
	???
	*/
}

StringType* ToString(LanguageType* V) {
	if (auto _V = dynamic_cast<UndefinedType *>(V))
		return new StringType("Nan");
	if (auto _V = dynamic_cast<NullType *>(V))
		return new StringType("null");
	if (auto _V = dynamic_cast<BooleanType *>(V))
		if (_V->_getValue() == true)
			return new StringType("true");
		else
			return new StringType("false");
	if (auto _V = dynamic_cast<NumberType *>(V))
		if (isnan(_V->_getValue()))
			return  new StringType("Nan");
		else
			return new StringType(to_string(_V->_getValue()));
	if (auto _V = dynamic_cast<StringType *>(V))
		return _V;
	if (auto _V = dynamic_cast<SymbolType *>(V)) {
		std::puts("TypeError");
		exit(0);
	}
	if (auto _V = dynamic_cast<ObjectType *>(V)){
		auto primValue = ToPrimative(_V, new StringType(""));
		return ToString(primValue);
	}
}

NumberType* ToNumber(LanguageType* V) {
	if (auto _V = dynamic_cast<UndefinedType *>(V))
		return new NumberType(NAN);
	if (auto _V = dynamic_cast<NullType *>(V))
		return new NumberType(0);
	if (auto _V = dynamic_cast<BooleanType *>(V))
		if (_V->_getValue() == true)
			return new NumberType(1);
		else
			return new NumberType(0);
	if (auto _V = dynamic_cast<NumberType *>(V))
		return _V;
	if (auto _V = dynamic_cast<StringType *>(V))
		try {
		return new NumberType(stod(_V->_getValue()));
	}
	catch (const invalid_argument) {
		return new NumberType(NAN);
	}
	if (auto _V = dynamic_cast<SymbolType *>(V)) {
		std::puts("TypeError");
		exit(0);
	}
	if (auto _V = dynamic_cast<ObjectType *>(V)) {
		auto primValue = ToPrimative(_V, new NumberType(0));
		return ToNumber(primValue);
	}
}


BooleanType* ToBoolean(LanguageType* V) {
	if (auto _V = dynamic_cast<UndefinedType *>(V))
		return new BooleanType(false);
	if (auto _V = dynamic_cast<NullType *>(V))
		return new BooleanType(false);
	if (auto _V = dynamic_cast<BooleanType *>(V))
		return _V;
	if (auto _V = dynamic_cast<NumberType *>(V))
		if (_V->_getValue() == 0 || _V->_getValue() == NAN)
			return new BooleanType(false);
		else
			return new BooleanType(true);
	if (auto _V = dynamic_cast<StringType *>(V))
		if (empty(_V->_getValue()))
			return new BooleanType(false);
		else
			return new BooleanType(true);
	if (auto _V = dynamic_cast<SymbolType *>(V)) {
		std::puts("TypeError");
		exit(0);
	}
	if (auto _V = dynamic_cast<ObjectType *>(V))
		return new BooleanType(true);
}