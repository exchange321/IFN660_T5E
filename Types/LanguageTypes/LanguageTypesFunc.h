#pragma once
#include <Types/LanguageTypes/LanguageTypes.h>
#include <Types/LanguageTypes/UndefinedType/UndefinedType.h>
#include <Types/LanguageTypes/NullType/NullType.h>
#include <Types/LanguageTypes/BooleanType/BooleanType.h>
#include <Types/LanguageTypes/StringType/StringType.h>
#include <Types/LanguageTypes/SymbolType/SymbolType.h>
#include <Types/LanguageTypes/NumberType/NumberType.h>
#include <Types/LanguageTypes/ObjectType/ObjectType.h>

LanguageType *ToPrimitive(LanguageType *, LanguageType * = nullptr);
BooleanType *ToBoolean(LanguageType *);
NumberType *ToNumber(LanguageType *);
NumberType *ToInteger(LanguageType *);
StringType *ToString(LanguageType *);
ObjectType *ToObject(LanguageType *);

string _GetType(LanguageType *);
LanguageType *_ToLanguageType(Type *, bool = true);
