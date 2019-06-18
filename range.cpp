// Author: Jeremiah Kalmus
// File: range.cpp
// Date: May 27th, 2019
// Version: 2.0


/* 
 * IMPLEMENTATION INVARIANTS:
 *  1 - All objects are kept active internally by calling reset after every pinged value comparison.
 *  
 *  2 - The factor objects are initialized either through client input, or through the default values already assigned.
 *  
 *  3 - The Ping() method calls methods Compare_Factor1, Compare_Factor2, and isPing to determine if the input value was a ping.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - Constructor initializes two factor objects with factor values as well as all other data members to keep track
 *      of statistics.
 *
 *	2 - Overloaded Operators:
 *
 *		Arithmetic operators (+, -) add and subtract from the encapsulated_factor value within the encapsulated_factor
 *		values located in the range object. Support of mixed mode with integers is implemented (range + int). range and a 
 * 		range will result in the operator performing on encapsulated_factor value 1 of one range with the encapsulated_factor 
 * 		value 1 of the other. The same goes for the second encapsulated_factor values. In mixed mode, the integer is added or
 * 		subtracted both encapsulated_factor values in the range object.
 *
 *		Relational operators (==, !=, <, <=, >, >=) are implemented and will compare the encapsulated_factor
 *		values within the range object. Range objects can be compared to other range objects, range objects
 *		can be compared to integers, and integers can be compared to range objects. Each will return a boolean
 *		from the comparison. The comparison is only true is both encapsulated_factor values in the range object
 *		pass the raltional check with what it is compared against.
 *
 *		Unary operators (++, --) increments or decrements both encapsulated_factor values of a range object by one.
 *		Pre and post increment and decrement are supported. These operators are destructive.
 *
 *		Assignment operators (+=, -=) are destructive, meaning they will alter the state of an existing factor
 *		objects encapsulated_factor rather than creating and returning a new factor object. These operators are 
 *		supported for factor objects with other factor objects, factor objects with integers, and integers with
 *		factor objects. The encapsulated_factor values are what is used for addition and subtraction and += adds 
 * 		a value on the RHS and assigns it to the LHS and the -= does the same but with subtraction instead. Same 
 * 		as (+, -) but destructive. Supported for range and range operation 
 * 		and range and integer operation.
 *
 *		Bitwise operator (<<) will output the encapsulated_factors of a range object when the object is called
 *		upon so there is no need for the dot operator or the -> when using heap allocated objects. 
 * 		Example: cout << r1; will return both encapsulated_factor values of object r1 seperated by a comma and a space.
 *
 *		ATTENTION:
 *
 *		For all operators that use subtraction, (-, --, -=) the encapsulated values will not subtract a value if the
 *		resulting encapsulated factor values will be less than 1. In this case, the operator will reject the request.
 *		
 * ---------------------------------------------------------------------------------------------------------------------------------
 */
 
 #include "range.h"
 
 range::range()
 {
	factorObj1 = factor(DEFAULTOBJ1);
	factorObj2 = factor(DEFAULTOBJ2);
	max = 0;
    min = DEFAULTMIN;
    mean = 0;
    sum_of_pings = 0;
    num_of_pings = 0;
 }
 range::range(unsigned initial_val1 = DEFAULTOBJ1, unsigned initial_val2 = DEFAULTOBJ2)
 {
	factorObj1 = factor(initial_val1);
    factorObj2 = factor(initial_val2);
    max = 0;
    min = DEFAULTMIN;
    mean = 0;
    sum_of_pings = 0;
    num_of_pings = 0;
 }
 unsigned range::Max()
 {
	 return max;
 }
 unsigned range::Min()
 {
	 return min;
 }
 unsigned range::Ping_Num()
 {
	 return num_of_pings;
 }
 unsigned range::Mean()
 {
	 return mean;
 }
 //PRE: Ping must be provided with a non-negative input.
 //POST: max, min, mean, sum_of_pings, and num_of_pings may change.
 bool range::Ping(unsigned ping_value)
 {
	 int result1 = Compare_Factor1(ping_value);
	 int result2 = Compare_Factor2(ping_value);
	 
    if (result1 == 1 && result2 == 1)
    {
        if (ping_value > max)
        {
            max = ping_value;
        }
        if (ping_value < min)
        {
            min = ping_value;
        }
        sum_of_pings = sum_of_pings + ping_value;
        num_of_pings++;
		mean = sum_of_pings / num_of_pings;
        return true;
    }
    else
    {
		if (min == DEFAULTMIN)
		{
			min = 0;
		}
        return false;
	}
 }
//PRE: Input must be non-negative integer
int range::Compare_Factor1(unsigned ping_value)
{
	int comparison_result = factorObj1.Factor_Comparison(ping_value);
    factorObj1.Reset();
    return comparison_result;
}
//PRE: Input must be non-negative integer
int range::Compare_Factor2(unsigned ping_value)
{
	int comparison_result = factorObj2.Factor_Comparison(ping_value);
    factorObj2.Reset();
    return comparison_result;
}
range range::operator+(const range& obj)
{
	range newObj(*this);
	newObj.factorObj1 += obj.factorObj1;
	newObj.factorObj2 += obj.factorObj2;
	
	return newObj;
}
range range::operator+(unsigned val)
{
	range newObj(*this);
	newObj.factorObj1 += val;
	newObj.factorObj2 += val;
	
	return newObj;
}
range range::operator-(const range& obj)
{
	range newObj(*this);
	newObj.factorObj1 -= obj.factorObj1;
	newObj.factorObj2 -= obj.factorObj2;
	
	return newObj;
}
range range::operator-(unsigned val)
{
	range newObj(*this);
	newObj.factorObj1 -= val;
	newObj.factorObj2 -= val;
	
	return newObj;
}
bool range::operator==(const range& obj) 
{ 
	return factorObj1 == obj.factorObj1 && factorObj2 == obj.factorObj2;
}
bool range::operator==(unsigned val)
{ 
	return (factorObj1 == val && factorObj2 == val);
}
bool operator==(unsigned val, const range& obj) 
{ 
	return (val == obj.factorObj1 && val == obj.factorObj2);
}
bool range::operator<(const range& obj) 
{ 
	return (factorObj1 < obj.factorObj1 && factorObj2 < obj.factorObj2); 
}
bool range::operator<(unsigned val) 
{
	return (factorObj1 < val && factorObj2 < val);
}
bool operator<(unsigned val, const range& obj) 
{ 
	return (val < obj.factorObj1 && val < obj.factorObj2); 
}
bool range::operator>(const range& obj) 
{ 
	return (factorObj1 > obj.factorObj1 && factorObj2 > obj.factorObj2); 
}
bool range::operator>(unsigned val) 
{ 
	return (factorObj1 > val && factorObj2 > val); 
}
bool operator>(unsigned val, const range& obj) 
{ 
	return (val > obj.factorObj1 && val > obj.factorObj2); 
}
bool range::operator!=(const range& obj)
{
	return (factorObj1 != obj.factorObj1 || factorObj2 != obj.factorObj2);
}
bool range::operator!=(unsigned val) 
{ 
	return (factorObj1 != val || factorObj2 != val); 
}
bool operator!=(unsigned val, const range& obj) 
{ 
	return (val != obj.factorObj1 || val != obj.factorObj2); 
}
bool range::operator<=(const range& obj)
{
	return (factorObj1 <= obj.factorObj1 && factorObj2 <= obj.factorObj2);
}
bool range::operator<=(unsigned val) 
{ 
	return (factorObj1 <= val && factorObj2 <= val); 
}
bool operator<=(unsigned val, const range& obj) 
{ 
	return (val <= obj.factorObj1 && val <= obj.factorObj2); 
}
bool range::operator>=(const range& obj)
{
	return (factorObj1 >= obj.factorObj1 && factorObj2 >= obj.factorObj2);
}
bool range::operator>=(unsigned val) 
{ 
	return (factorObj1 >= val && factorObj2 >= val); 
}
bool operator>=(unsigned val, const range& obj) 
{ 
	return (val >= obj.factorObj1 && val >= obj.factorObj2); 
}
// POST: encapsulated_factors will change.
range range::operator++()
{
	++factorObj1;
	++factorObj2;
	return *this;
}
// POST: encapsulated_factors will change.
range range::operator++(int x)
{
	range oldFactor(*this);
	++factorObj1;
	++factorObj2;
	return oldFactor;
}
// POST: encapsulated_factors will change.
range range::operator--()
{

	if (factorObj1 >= MIN_VALUE && factorObj2 >= MIN_VALUE)
	{
		--factorObj1;
		--factorObj2;
	}
	return *this;
}
// POST: encapsulated_factors will change.
range range::operator--(int x)
{
	range oldFactor(*this);
	if (factorObj1 >= MIN_VALUE && factorObj2 >= MIN_VALUE)
	{
		--factorObj1;
		--factorObj2;
	}
	return oldFactor;
}
// PRE: Needs a factor object to compare to.
// POST: encapsulated_factor will change.
range& range::operator+=(const range& obj)
{
	factorObj1 += obj.factorObj1;
	factorObj2 += obj.factorObj2;
	return *this;
}
// PRE: Needs an unsigned int to compare to.
// POST: encapsulated_factor will change.
range& range::operator+=(unsigned val)
{
	factorObj1 += val;
	factorObj2 += val;
	return *this;
}
// PRE: Needs a factor object to compare to.
// POST: encapsulated_factor will change.
range& range::operator-=(const range& obj)
{
	factorObj1 -= obj.factorObj1;
	factorObj2 -= obj.factorObj2;
	return *this;
}// PRE: Needs an unsigned int to compare to.
// POST: encapsulated_factor will change.
range& range::operator-=(unsigned val)
{
	factorObj1 -= val;
	factorObj2 -= val;
	return *this;
}
ostream& operator<<(ostream& out, const range& obj)
{
	out << obj.factorObj1 << ", " << obj.factorObj2;
	return out;
}