#pragma once
#include <RuntimeLib\Type\LanguageType\LanguageTypeFunc.h>
#include <RuntimeLib\Type\SpecificationType\Reference\ReferenceFunc.h>
#include <string>

LanguageType* Assignment(Type* lref, Type* rref);
bool IsAnonymousFunctionDefinition();
bool HasOwnProperty(LanguageType * O, string P);