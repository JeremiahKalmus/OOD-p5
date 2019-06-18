// Author: Jeremiah Kalmus
// File: factor.cpp
// Date: May 27th, 2019
// Version: 3.0

/* OVERVIEW:
 *  factor.cs is to create an object which contains a factor value and to have the
 *  client compare other values to it to see if the value entered is a multiple of 
 *  the factor objects factor value. 
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - The factor class will only work with positive integers since the 
 *  
 *  2 - accessor isActive is given so that the client can check whether the
 *      object is active or not. Factor_Comparison() will do nothing but return -1
 *      if the object is inactive so it is up to the client to check to ensure the
 *      state is active.
 * ---------------------------------------------------------------------------------------------------------------------------------     
 * IMPLEMENTATION INVARIANTS:
 *  1 - factor.cs is only supported to handle factor values and comparison values that are
 *      unsigned integers.
 *    
 *  2 - The Factor_Comparison() method will return 1 if the value compared to the factor value
 *      is a multiple, it will return 0 if the value compared is not a multiple of the factor
 *      value, and it will return -1 if the object is inactive.
 * 
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - After every construction, a factor value is set in the object, the status of the object
 *      is set to active and all data members associated are intialized.
 *      The client can pass in a positive integer for the factor value
 *      or they can choose to not pass in any factor value and a default factor
 *      value will be set for them. The factor value cannot be changed once set.
 *      
 *  2 - Factor object is set to inactive if the same value is passed in twice to the 
 *      Factor_Comparison() method.
 *
 *	3 - Encapsulated factor value is not allowed to be 0 or 1. If 0 or 1 is entered as the factor
 * 		value upon construction, the encapsulated factor will be reassigned to the deafult factor
 * 		value.
 *
 *	4 - Overloaded Operators:
 *
 *		Arithmetic operators (+, -) add and subtract from the encapsulated_factor value within a factor
 *		object. you can add or subtract factors with factors, ints with factors as well as factors with 
 *		ints. They are non-destructive so factors with factors and ints with factors will return a new
 *		factor object where int with factor will return an integer value.
 *
 *		Relational operators (==, !=, <, <=, >, >=) are implemented and will compare the encapsulated_factor
 *		value within the factor object. Factor objects can be compared to other factor objects, factor objects
 *		can be compared to integers, and integers can be compared to factor objects. Each will return a boolean
 *		from the comparison.
 *
 *		Unary operators (++, --) increments or decrements the encapsulated_factor value of an object by one.
 *		Pre and post increment and decrement are supported. These operators are destructive.
 *
 *		Assignment operators (+=, -=) are destructive, meaning they will alter the state of an existing factor
 *		objects encapsulated_factor rather than creating and returning a new factor object. These operators are 
 *		supported for factor objects with other factor objects, factor objects with integers, and integers with
 *		factor objects. The former two will return the altered object, while the latter will return an integer.
 *		The encapsulated_factor values are what is used for addition and subtraction and += adds a value on the 
 * 		RHS and assigns it to the LHS and the -= does the same but with subtraction instead.
 *
 *		Bitwise operator (<<) will output the encapsulated_factor of a factor object when the object is called
 *		upon so there is no need for the dot operator or the -> when using heap allocated objects. 
 * 		Example: cout << f1; will return the encapsulated_factor value of object f1.
 *
 * 		ATTENTION:
 *
 *		For all operators that use subtraction, (-, --, -=) the encapsulated values will not subtract a value if the
 *		resulting encapsulated factor values will be less than 1. In this case, the operator will reject the request.
 *		This does not apply for overloaded operators that return an integer (int - factor and int -= factor).
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 */
 
#include <iostream>
 
#include "factor.h"
 
using namespace std;
 
factor::factor()
{
    encapsulated_factor = DEFAULTFACTOR;
    active = true;
    multiple_counter = 0;
    previous_input = 0;
}
factor::factor(unsigned factor_number)
{
		if (factor_number <= 1)
		{
			encapsulated_factor = DEFAULTFACTOR;
		}
		else
		{
			encapsulated_factor = factor_number;
		}
        active = true;
        multiple_counter = 0;
        previous_input = 0;
}
unsigned factor::Counter()
{
	return multiple_counter;
}
bool factor::isActive()
{
	return active;
}
// PRE: To operate effectively, the object must be in an active state.
// POST: The previous_input may change and the state of the object may become inactive.
int factor::Factor_Comparison(unsigned comparison_value)
{
    if (active)
    {
        if ((comparison_value % encapsulated_factor == 0) && (previous_input != comparison_value))
        {
            multiple_counter++;
            previous_input = comparison_value;
            return 1;
        }
        else if ((comparison_value % encapsulated_factor != 0) && (previous_input != comparison_value))
        {
            previous_input = comparison_value;
            return 0;
        }
        else
        {
            active = false;
        }
    }
    return -1;
}
// POST: Multiple_Counter and previous_input are returned to their default state
//       upon intialization and the state of the object is set to active.
void factor::Reset()
{
	multiple_counter = 0;
    previous_input = 0;
    active = true;
}
factor factor::operator+(const factor& obj)
{
	unsigned temp_factor = encapsulated_factor + obj.encapsulated_factor;
	factor sum(temp_factor);
	return sum;
}
factor factor::operator-(const factor& obj)
{
	unsigned temp_factor = 0;
	if (obj.encapsulated_factor < encapsulated_factor)
	{
		temp_factor = encapsulated_factor - obj.encapsulated_factor;
	}
	factor diff(temp_factor);
	return diff;
}
// POST: encapsulated_factor will change.
factor factor::operator++()
{
	encapsulated_factor = encapsulated_factor + 1;
	return *this;
}
// POST: encapsulated_factor will change.
factor factor::operator++(int x)
{
	factor oldFactor = *this;
	++encapsulated_factor;
	return oldFactor;
}

// POST: encapsulated_factor will change.
factor factor::operator--()
{
	if (encapsulated_factor > MIN_DECREMENT)
	{
		encapsulated_factor = encapsulated_factor - 1;
	}
	return *this;
}

// POST: encapsulated_factor will change.
factor factor::operator--(int x)
{
	if (encapsulated_factor > MIN_DECREMENT)
	{
		factor oldFactor = *this;
		--encapsulated_factor;
		return oldFactor;
	}
		return *this;
}
bool factor::operator==(const factor& obj)
{
	if (encapsulated_factor == obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator!=(const factor& obj)
{
	if (encapsulated_factor != obj.encapsulated_factor)
	{
		return true;
	}
	return false;

}
bool factor::operator<(const factor& obj)
{
	if (encapsulated_factor < obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator<=(const factor& obj)
{
	if (encapsulated_factor <= obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator>(const factor& obj)
{
	if (encapsulated_factor > obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator>=(const factor& obj)
{
	if (encapsulated_factor >= obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
// PRE: Needs a factor object to compare to.
// POST: encapsulated_factor will change.
factor& factor::operator+=(const factor& obj)
{
	this->encapsulated_factor += obj.encapsulated_factor;
	return *this;
}
// PRE: Needs a factor object to compare to.
// POST: encapsulated_factor will change.
factor& factor::operator-=(const factor& obj)
{
	if (encapsulated_factor > obj.encapsulated_factor)
	{
		this->encapsulated_factor -= obj.encapsulated_factor;
	}
	return *this;
}
factor factor::operator+(const unsigned val)
{
	unsigned temp_factor = encapsulated_factor + val;
	factor sum(temp_factor);
	return sum;
}
int operator+(const unsigned val, const factor& obj)
{
	int result = val + obj.encapsulated_factor;
	return result;
}
factor factor::operator-(const unsigned val)
{
	int temp_factor = 0;
	if (val < encapsulated_factor)
	{
		temp_factor = encapsulated_factor - val;
	}
	factor diff(temp_factor);
	return diff;
}
int operator-(const unsigned val, const factor& obj)
{
	int result_value = 0;
	result_value = val - obj.encapsulated_factor;
	return result_value;
}
bool factor::operator==(const unsigned val)
{
	if (encapsulated_factor == val)
	{
		return true;
	}
	return false;
}
bool operator==(const unsigned val, const factor& obj)
{
	if (val == obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator!=(const unsigned val)
{
	if (encapsulated_factor != val)
	{
		return true;
	}
	return false;
}
bool operator!=(const unsigned val, const factor& obj)
{
	if (val != obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator<(const unsigned val)
{
	if (encapsulated_factor < val)
	{
		return true;
	}
	return false;
}
bool operator<(const unsigned val, const factor& obj)
{
	if (val < obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator<=(const unsigned val)
{
	if (encapsulated_factor <= val)
	{
		return true;
	}
	return false;
}
bool operator<=(const unsigned val, const factor& obj)
{
	if (val <= obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator>(const unsigned val)
{
	if (encapsulated_factor > val)
	{
		return true;
	}
	return false;
}
bool operator>(const unsigned val, const factor& obj)
{
	if (val > obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
bool factor::operator>=(const unsigned val)
{
	if (encapsulated_factor >= val)
	{
		return true;
	}
	return false;
}
bool operator>=(const unsigned val, const factor& obj)
{
	if (val >= obj.encapsulated_factor)
	{
		return true;
	}
	return false;
}
// PRE: Needs an unsigned int to compare to.
// POST: encapsulated_factor will change.
factor& factor::operator+=(const unsigned val)
{
	this->encapsulated_factor += val;
	return *this;
}
// PRE: Needs an unsigned int and factor object to compare to.
// POST: encapsulated_factor will change.
int operator+=(unsigned val, const factor& obj)
{
	val += obj.encapsulated_factor;
	return val;
}
// PRE: Needs an unsigned int to compare to.
// POST: encapsulated_factor will change.
factor& factor::operator-=(const unsigned val)
{
	if (encapsulated_factor > val)
	{
		this->encapsulated_factor -= val;
	}
	return *this;
}
// PRE: Needs an unsigned int and a factor object to compare to.
// POST: encapsulated_factor will change.
int operator-=(unsigned val, const factor& obj)
{
	val -= obj.encapsulated_factor;
	return val;
}
ostream& operator<<(ostream &out, const factor& obj)
{
	out << obj.encapsulated_factor;
	return out;
}