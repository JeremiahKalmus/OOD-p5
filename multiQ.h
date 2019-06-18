// Author: Jeremiah Kalmus
// File: multiQ.h
// Date: May 27th, 2019
// Version: 2.0

/* 
 * OVERVIEW:
 *  MultiQ.cs takes values in from the client and creates an array of factor
 *  objectsfrom the size gievn by the client. The client can add and remove 
 *  factor values which will result in factor objects being created and removed
 *  from the multiQ object.The client can enter a value into 
 *  Query() and find out how many factor objects are a factor to the queried value.
 *  An example being, if a multiQ object held an array with factor objects of values
 *  2, 3, and 5, and 6 was passes into Query(), the result of that method would return
 *  2. If 11 was passed into Query() it would return 0.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * DESIGN DECISIONS AND ASSUMPTIONS:
 *  1 - Statistics that are kept track of include the largest successful query, the
 *      smallest successful query, the number of times the multiQ object was queried,
 *      the average of amount of factors returned from successful queries, and the
 *      number of times the object has been reset.
 *      
 *  2 - Active status of multiQ objects depend on the active status of the encapsulated
 *      array of factor objects. If any factor object becomes unactive, the entire multiQ
 *      object then becomes inactive until someone resets the multiQ object.
 *      
 *  3 - Can only use unsigned integers for adding a factor value and for Query since factor.cs
 *      can only take in positive integers.
 *      
 *  4 - A choice was to prohibit the user from handling the factor objects themselves, therefore, 
 *      the multiQ class deals with the memory management of the factor objects. The client is only
 *      concerned about the factor values themselves. 
 *      
 *  5 - The constructors will create an array to hold factor objects between the sizes of 10 and 50.
 *      The user will decide the size as long as the size remains within those bounds, if they 
 *      exceed those bounds then the array will be set to a default size of 20.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * INTERFACE INVARIANTS:
 *  1 - MultiQ objects remain active for as long as the client does not Query() the same value twice in succession.
 *  
 *  2 - Reset():
 *  
 *      At any time, the client can Reset() a multiQ object and it will reset the object to the state it was in
 *      immediately after construction.
 *      
 *  3 - isFull:
 *  
 *      At any time, the client can check to see if the array of factors is full using isFull. 
 *      
 *  4 - Factor_Count:
 *  
 *      At any time, the client can check to see how many factor objects are within the multiQ storage array by using Factor_Count.  
 *      
 *  5 - Query:
 *  
 *      When using Query() the client must pass in a positive integer. Query() will only work effectively if the state of the object
 *      is active. It will compare the input value (queried value) with the array of holding factor objects. It will compare to see
 *      how many of the factor values are factors of the queried value. Query() will return the number of values that are factors 
 *      of the queried value.
 *  
 *  6 - Statistics - Max, Min, Mean, Query_Count, Reset_Count:
 *  
 *      The user can access any statistic value they would like to know by the means of its accessor. The stats are kept track only
 *      when the object is active. Stats include the Max which returns the largest number of factors of any single Query(). Min, which
 *      returns the smallest number of factors of any single Query(). Mean, which returns the average number of factors that return from
 *      a Query() call. Query_Count which returns how many times Query() has been called while the object was active. Lastly, there is
 *      Reset_Count which returns the number of times an object has been reset. Stats will be all 0 if there were no queries or if the
 *      queries resulted in the queried values having no factors in the internal factor object array.
 *      
 *  7 - isActive:
 *  
 *      The client can check at any time if an object is active or inactive. They should use the isActive Accessor.
 *      
 *  8 - Add():
 *  
 *      This method allows the client to add a positive factor value to the back of the array held by a multiQ object. When adding 
 *      a factor value to the array, the client must be mindful if they are adding to a full array for Add() will not add a 
 *      value to the array if it is full, it will simply ignore the request. Recommended that 0 is not entered since 0 is a factor
 *      to every other number.
 *      
 *  9 - Delete():
 *  
 *      This method allows the client to delete a factor value from the front of the array held by a multiQ object. 
 *      From this, the client is responsible for checking whether the array is empty. The client cannot Delete() from an empty factor 
 *      array since Delete() will simply ignore the request.
 * ---------------------------------------------------------------------------------------------------------------------------------
 * CLASS INVARIANTS:
 *  1 - The constructor will create an array size between 10 and 50 to hold factor objects. The constructor will recieve a size
 *      of array from the client and create an array filled with empty factor objects. The private data members tracking statistics
 *      will be initialized and the size of the array holding factor objects from that point onward cannot change.
 *      
 *  2 - Object is deemed inactive if any of the factor objects it holds in the array is inactive.
 *
 *  3 - If Min() gets called before any factor value is added into the factor_objArray, then it will give a default value of 1000.
 *
 *  4 - Overloaded Operators:
 *
 *		Arithmetic operators (+, -) addition with multiQ and multiQ objects will result in a new multiQ that
 * 		adds all the values in their factor_objArray element wise (index 2 will be added to index 2. The new 
 *		object factor array size will change to be as large as the size of the object with the largest factor 
 * 		array. Subtraction will subtract element wise like addition does, however, if the multiQ factor array
 * 		that is on the far RHS has more elements than the other multiQ object, the extra factor objects will be
 * 		ignored. Addition for multiQ + int is supported and will add a factor object to the factor_objArray.
 * 		Subtraction with multiQ - int is also supported and will delete the integer number of factor objects
 * 		from factor_objArray.
 *
 *		Relational operators (==, !=) For multiQ compared to multiQ objects, the == will check to match every
 *		element in the factor_objArray. 1 will be returned if any value of one multiQ factor_objArray matches with 
 * 		the value of the same index in the other multiQ object. Only one match is needed to return true, otherwise 
 * 		if there are no matches then it returns false. Comparisons of multiQ and factor, factor and multiQ, int and 
 * 		multiQ, and multiQ and int will check to see if any of the encapsulated factor values int he factor_objArray 
 * 		of the multiQ is == to the singular encapsulated factor or integer it is compared against. != simply checks 
 * 		the respective == operator and inverts the result. Again returning 1 if true and 0 if false. 
 *
 *		Unary operators (++, --) increments or decrements all the encapsulated_factor values in the multiQ factor_objArray.
 *
 *		Assignment operators (+=, -=) are destructive, meaning they will alter the state of an existing multiQ
 *		objects factor_objArray rather than creating and returning a new multiQ object. These operators are 
 *		supported for multiQ objects with other multiQ objects, multiQ objects with integers, and integers with
 *		multiQ objects. These operators perform the same functionality as + and - but instead of returning a new
 * 		object, they are destructing, changing the object on the LHS. Supported for multiQ and multiQ operation 
 * 		and multiQ and integer operation.
 *
 *		Bitwise operator (<<) will output the factor_objArray of a multiQ object when the object is called
 *		upon so there is no need for the dot operator or the -> when using heap allocated objects. 
 * 		Example: cout << m1; will return the factor_objArray value of object m1.
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
	5/20/2019 - min and mean accessors no longer change data members.

*/

#ifndef MULTIQ_H
#define MULTIQ_H

#include "factor.h"

class multiQ
{
	public:
	  multiQ();
	  multiQ(unsigned);
	  ~multiQ();
	  multiQ(const multiQ&);
	  multiQ& operator=(const multiQ&);
	  bool isFull();
	  unsigned Factor_Count();
	  unsigned Max();
	  unsigned Min();
	  unsigned Mean();
	  unsigned Query_Count();
	  unsigned Reset_Count();
	  bool isActive();
	  void Add(unsigned);
	  void Reset();
	  void Delete();
	  unsigned Query(unsigned);
	
	  multiQ operator+(const multiQ&);
	  multiQ operator+(unsigned val);
	  multiQ operator-(const multiQ&);
	  multiQ operator-(unsigned val);
	  
	  bool operator==(const multiQ&);
	  bool operator==(unsigned val);
	  bool operator==(const factor&);
	  friend bool operator==(const factor&, const multiQ&);
	  friend bool operator==(unsigned val, const multiQ&);
	  bool operator!=(const multiQ&);
	  bool operator!=(unsigned val);
	  bool operator!=(const factor&);
	  friend bool operator!=(const factor&, const multiQ&);
	  friend bool operator!=(unsigned val, const multiQ&);
	  
	  multiQ operator++();
	  multiQ operator++(int);
	  multiQ operator--();
	  multiQ operator--(int);
	  
	  multiQ& operator+=(const multiQ&);
	  multiQ& operator+=(unsigned); 
	  multiQ& operator-=(const multiQ&);
	  multiQ& operator-=(unsigned);
	
	  friend ostream& operator<<(ostream&, const multiQ&);
	  
	private:
	  const static unsigned DEFAULT_SIZE = 20;
      const static unsigned DEFAULT_MIN = 1000;
	  const static unsigned ARRAY_SIZE_MIN = 10;
	  const static unsigned ARRAY_SIZE_MAX = 50;
	  const static unsigned MIN_FACTOR_VAL = 1;
      factor* factor_objArray;
      unsigned index;
      unsigned max_array_size;
      bool full;
      bool active;
      unsigned max;
	  unsigned min;
      unsigned mean;
      unsigned sum_of_queries;
      unsigned num_of_queries;
      unsigned num_of_resets;
	  
};
#endif
 
 
 