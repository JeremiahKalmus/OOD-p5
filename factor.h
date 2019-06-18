// Author: Jeremiah Kalmus
// File: factor.h
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
 *
 *	3 - Overloaded operators are not allowed to decrement to a resulting value of 
 *		less than 2 unless the operator returns type int.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - Construction:
 *  
 *      The client can pass in a positive integer for the factor value
 *      or they can choose to not pass in any factor value and a default factor
 *      value will be set for them.
 *  
 *  2 - Factor_Comparison():
 *  
 *      Factor objects will only operate as intended if they are in an active state.
 *      If the client passes in 2 of the same values into the Factor_Comparison()
 *      method, then the object will become inactive. If the client wishes to restore
 *      the object to an active state, they must call the Reset() method. The only
 *      values that can be passed into Factor_Comparison() are positive integers.
 *      Factor_Comparison() will take in a positive integer and determine if the 
 *      input value from the client is a multiple of the factor stored in the object.
 *      If the object is inactive, the Factor_Comparison() will not operate and merely
 *      return -1.
 *      
 *  3 - Reset():
 *      
 *      Reset() can be called when the object is active or inactive and it will return
 *      the object back to its original state immediately after construction. All private
 *      data members will be reset except for the factor number. Once set, the factor
 *      number can not be changed.
 * 
 *  4 - Accessors - isActive & Counter:
 *  
 *      Counter, when called, will provide the client with the amount of multiples the
 *      factor object has processed. The isActive accessor will allow the client to check
 *      if the object is currently active or not.
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
 * ---------------------------------------------------------------------------------------------------------------------------------
 */
 
/*
	UPDATES:
	5/19/2019 - Changed factor_number data member to encapsulated_factor.
				
				Additionally, changed input constructor value name from user_input
				to factor_number.
				
				Factor value not allowed to be 0 or 1.

*/
#ifndef FACTOR_H
#define FACTOR_H

#include <iostream>

using namespace std;

class factor
{
	public:
	  factor();
	  factor(unsigned);	  
	  unsigned Counter();
	  bool isActive();
	  int Factor_Comparison(unsigned);
	  void Reset();
	  factor operator+(const factor&);
	  factor operator-(const factor&);
	  factor operator++();
	  factor operator++(int);
	  factor operator--();
	  factor operator--(int);
	  bool operator==(const factor&);
	  bool operator!=(const factor&);
	  bool operator<(const factor&);
	  bool operator<=(const factor&);
	  bool operator>(const factor&);
	  bool operator>=(const factor&);
	  factor& operator+=(const factor&);
	  factor& operator-=(const factor&);
	  
	  factor operator+(const unsigned);
	  friend int operator+(const unsigned, const factor&);
	  factor operator-(const unsigned);
	  friend int operator-(const unsigned, const factor&);
	  bool operator==(const unsigned);
	  friend bool operator==(const unsigned, const factor&);
	  bool operator!=(const unsigned);
	  friend bool operator!=(const unsigned, const factor&);
	  bool operator<(const unsigned);
	  friend bool operator<(const unsigned, const factor&);
	  bool operator<=(const unsigned);
	  friend bool operator<=(const unsigned, const factor&);
	  bool operator>(const unsigned);
	  friend bool operator>(const unsigned, const factor&);
	  bool operator>=(const unsigned);
	  friend bool operator>=(const unsigned, const factor&);
	  factor& operator+=(const unsigned);
	  friend int operator+=(unsigned, const factor&);
	  factor& operator-=(const unsigned);
	  friend int operator-=(unsigned, const factor&);
	  
	  friend ostream &operator<<(ostream &out, const factor&);

	  
	private:
	  const static unsigned DEFAULTFACTOR = 4;
	  const static unsigned MIN_DECREMENT = 2;
      unsigned encapsulated_factor;
      bool active;
      unsigned multiple_counter;
      unsigned previous_input;
	
};
#endif
 