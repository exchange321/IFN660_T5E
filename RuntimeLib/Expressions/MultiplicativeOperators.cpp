#include <RuntimeLib\Expressions\MultiplicativeOperators.h>
#include <string>

//Evaluation Functions

LanguageType * Multiplicative(Type * left, Type * right, string _operator){
	auto leftValue = GetValue(left);
	auto rightValue = GetValue(right);
	auto lnum = ToNumber(leftValue)->_getValue();
	auto rnum = ToNumber(rightValue)->_getValue();
	if (_operator == "*") {
		if (lnum == NAN || rnum == NAN)
			return new NumberType(NAN);
		if (lnum == 0 && (rnum == INFINITY || rnum == -INFINITY) || (lnum == INFINITY || lnum == -INFINITY) && rnum == 0)
			return new NumberType(NAN);
		if (lnum == INFINITY && rnum == INFINITY)
			return new NumberType(INFINITY);
		if (lnum == -INFINITY && rnum == INFINITY || lnum == INFINITY && rnum == -INFINITY)
			return new NumberType(-INFINITY);
		return  new NumberType(lnum * rnum);
	}
	return  new NumberType(0);
}