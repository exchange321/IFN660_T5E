#include <RuntimeLib\Type\SpecificationType\ReferenceType\ReferenceTypeFunc.h>

LanguageType* GetValue(LanguageType* V) {
	ReturnIfAbrupt(V);
	if (!dynamic_cast<ReferenceType *>(V))
		return V;
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto base = _V->GetBase();
	if (_V->IsUnresolvableReference()->_getValue()) {
		puts("ReferenceError");
		exit(0);
	}
	if (_V->IsPropertyReference()->_getValue())
		if (_V->HasPrimitiveBase()->_getValue()) {
			if (!dynamic_cast<UndefinedType *>(base) && !!dynamic_cast<NullType *>(base))
				true;//WIP base ToObject(base);
			return base;//[[Get]](GetReferenceName(V),GetThisValue(V))
		}
	else //base must be an Environment Records
		return base;//GetBindingValue(GetRefencedName(V),IsStrictReference(V))
}

LanguageType* PutValue(Type* V, Type* W) {
	ReturnIfAbrupt(V);
	ReturnIfAbrupt(W);
	if (!dynamic_cast<ReferenceType *>(V)) {
		puts("ReferenceError");
		exit(0);
	}
	auto _V = dynamic_cast<ReferenceType *>(V);
	auto base = _V->GetBase();
	if (_V->IsUnresolvableReference()->_getValue()) {
		if (_V->IsStrictReference()->_getValue()) {
			puts("ReferenceError");
			exit(0);
		}
		auto globalObj = GetGlobalObject();
		
		//Set(globalObj, _V->GetReferenceName(),W,false)
		return nullptr;

	}
	else if (_V->IsPropertyReference()->_getValue()) {
		if (_V->HasPrimitiveBase()->_getValue()) {
			if (!dynamic_cast<UndefinedType *>(base) && !!dynamic_cast<NullType *>(base))
				true;//WIP base ToObject(base);
			// auto succeeded base.Set(globalObj, _V->GetReferenceName(),W,false)
			// if succeeded = false and _V->isstrictreference()->_getValue() throw TypeError
		}
		return nullptr;
	}
	else { //Environment Record
		//base.SetMutableBinding(_V->GetReferenceName(), W, _V->IsStrictReference());
		return nullptr;
	}
	
}


//Specification Type methods?
void ReturnIfAbrupt(Type* V) {
	//Will fill
}

Type* GetGlobalObject() {
	return new ObjectType("Dummie");
}

