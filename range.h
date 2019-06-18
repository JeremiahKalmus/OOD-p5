// Author: Jeremiah Kalmus
// File: range.h
// Date: May 27th, 2019
// Version: 2.0


/* 
 * OVERVIEW:
 *  The range class initializes with two factor objects. Zero, one, or two of these can be passed in by the client. These factors are 
 *  then compared to a pinged value that the client enters into Ping(). This pinged value will be compared to the two factor objects
 *  and checked to see if it is a ping. A Ping only occurs when both factor objects are factors of the pinged value entered by the
 *  client. For example, the two factor objects have factor values of 2 and 3 and the client passes in a pinged value of 3. This is
 *  not a ping, however, the pinged value of 6 is a ping.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - Client must enter non-negative numbers for the factor objects upon construction, and for the pinged value.
 *  
 *  2 - Reset() is called during every Ping() the client does to ensure all range objects remain active indefinitely.
 *
 *	3 - Overloaded operators are not allowed to decrement to a resulting value of 
 *		less than 2.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - range objects are always active.
 *  
 *  2 - Client should not pass in more than 2 factor values into the constructor. These values are to be positive numbers and 
 *      preferably not zero since zero is a factor to all other numbers.
 *  
 *  3 - Ping():
 *  
 *      The client can input a non-negative number and it will compare that input value to the factor object values. This will return
 *      whether or not the value was a ping. An input value is a ping if it is a multiple of both factor values.
 *      
 *  4 - Statistics - Max, Min, Mean, & Ping_Num:
 *  
 *      The statistics have been implemented such that the client can access the information via an accessor at any point. They may use
 *      Max to determine the largest value that was a ping. Min will determine the smallest value that was a ping. Mean will return the
 *      average of all the values that were succefful pings. Ping_Num will return the number of pings that have occured. All the stats
 *      will be 0 if the object never receives a ping value from the client or if there are no successful pings.
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
 /*
	UPDATES:
	5/19/2019 - Removed isPing() helper method and added the functionality of isPing() into Ping() method.

*/
 
#ifndef RANGE_H
#define RANGE_H

#include "factor.h"

class range
{
	public:
	  range();
	  range(unsigned, unsigned);
	  unsigned Max();
	  unsigned Min();
	  unsigned Ping_Num();
	  unsigned Mean();
	  bool Ping(unsigned);
	  int Compare_Factor1(unsigned);
	  int Compare_Factor2(unsigned);
	  
	  range operator+(const range&);
	  range operator+(unsigned);
	  range operator-(const range&);
	  range operator-(unsigned);
	  
	  bool operator==(const range&); 
	  bool operator==(unsigned); 
	  friend bool operator==(unsigned, const range&); 
	  bool operator<(const range&); 
	  bool operator<(unsigned);  
  	  friend bool operator<(unsigned, const range&); 
	  bool operator>(const range&);
	  bool operator>(unsigned);
	  friend bool operator>(unsigned, const range&);
	  bool operator!=(const range&);
	  bool operator!=(unsigned);
	  friend bool operator!=(unsigned, const range&);
	  bool operator<=(const range&);
	  bool operator<=(unsigned);
	  friend bool operator<=(unsigned, const range&);
	  bool operator>=(const range &); 
	  bool operator>=(unsigned);
	  friend bool operator>=(unsigned, const range&);
	
	  range operator++();
	  range operator++(int);
	  range operator--();
	  range operator--(int);
	  
	  range& operator+=(const range&);
	  range& operator+=(unsigned);
	  range& operator-=(const range&);
	  range& operator-=(unsigned);
	
	  friend ostream& operator<<(ostream&, const range&);


	
	private:
	  const static unsigned DEFAULTMIN = 1000;
	  const static unsigned DEFAULTOBJ1 = 2;
	  const static unsigned DEFAULTOBJ2 = 3;
	  const static unsigned MIN_VALUE = 2;
      factor factorObj1;
      factor factorObj2;
      unsigned max;
      unsigned min;
      unsigned mean;
      unsigned sum_of_pings;
      unsigned num_of_pings;
	
};
#endif