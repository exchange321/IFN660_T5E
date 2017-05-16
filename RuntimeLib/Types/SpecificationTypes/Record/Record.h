#pragma once
#include <map>
#include <RuntimeLib/Types/SpecificationTypes/SpecificationType.h>
#include <RuntimeLib/Types/LanguageTypes/StringType/StringType.h>
#include <RuntimeLib/Types/LanguageTypes/BooleanType/BooleanType.h>

using namespace std;

struct RECORD_VALUE_COMP {
	bool operator()(StringType *, StringType *) const;
};

class Record : public SpecificationType {
	map<StringType *, Type *, RECORD_VALUE_COMP> value;
public:
	Record() { };
	void _insertValue(StringType *, Type *);
	map<StringType *, Type *, RECORD_VALUE_COMP> _getValue() const;
	Type *_findValue(StringType *);
	BooleanType *_hasValue(StringType *);
	BooleanType *_hasInitialized(StringType *);
	void _setValue(StringType *, Type *);
	BooleanType *_deleteValue(StringType *);
};