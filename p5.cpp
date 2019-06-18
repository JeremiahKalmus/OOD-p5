// Author: Jeremiah Kalmus
// File: p5.cpp
// Date: May 27th, 2019
// Version: 1.0

/*
	OVERVIEW:
	
	This driver file will test the overloaded operators of factor, range, and multiQ classes.
	Distinct arrays will be created and initialized. A function will be dedicated to testing each array.
	See the class invariant section for each class to see the operators that have been supported. 
	Please remember when testing of the behavior of subtraction operators.
*/


#include "factor.h"
#include "range.h"
#include "multiQ.h"

#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#include <iostream>

using namespace std;

unsigned const ARRAY_SIZE = 3;
unsigned const OBJ_ONE = 0;
unsigned const RANDOM_INT_SIZE = 15;
unsigned const RANDOM_SMALLER_INT = 3;
const string ASTERISK = "************************************************************";

void Initialize_Arrays(factor*, range*, multiQ*);
void Test_Factor_Overloading(factor*);
void Test_Range_Overloading(range*);
void Test_MultiQ_Overloading(multiQ*);

int main()
{
	factor factor_objArray[ARRAY_SIZE];
	range range_objArray[ARRAY_SIZE];
	multiQ multiQ_objArray[ARRAY_SIZE];
	Initialize_Arrays(factor_objArray, range_objArray, multiQ_objArray);
	Test_Factor_Overloading(factor_objArray);
	Test_Range_Overloading(range_objArray);
	Test_MultiQ_Overloading(multiQ_objArray);
	
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO END PROGRAM...";
	cin.get();
	cout << ASTERISK << endl;
	return 0;
}
void Initialize_Arrays(factor* factor_objArray, range* range_objArray,  multiQ* multiQ_objArray)
{
	cout << "Welcome to p5 test program." << endl << endl;
	srand(time(NULL));
	unsigned const RANDOM_INT_SIZE = 9;
	unsigned const MIN_FACTOR_VAL = 1;
	unsigned const DEFAULT_FACTOR_VAL = 4;
	unsigned random_integer1;
	unsigned random_integer2;
	
	cout << "Initializing array of factor objects." << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer1 = rand() % RANDOM_INT_SIZE + 1;
		factor_objArray[i] = factor(random_integer1);
		if (random_integer1 <= MIN_FACTOR_VAL)
			cout << "Encapsulated factor value is: " << DEFAULT_FACTOR_VAL << endl;
		else
			cout << "Encapsulated factor value is: " << random_integer1 << endl;
	}
	cout << endl;
	cout << "Initializing array of range objects." << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer1 = rand() % RANDOM_INT_SIZE + 1;
		random_integer2 = rand() % RANDOM_INT_SIZE + 1;
		range_objArray[i] = range(random_integer1, random_integer2);
		if (random_integer1 <= MIN_FACTOR_VAL)
			random_integer1 = DEFAULT_FACTOR_VAL;
		if (random_integer2 <= MIN_FACTOR_VAL)
			random_integer2 = DEFAULT_FACTOR_VAL;
		cout << "Encapsulated values are: " << random_integer1 << " and " << random_integer2 << endl;
	}
	cout << endl;
	cout << "Initializing array of multiQ objects." << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer1 = rand() % RANDOM_INT_SIZE + 1;
		random_integer2 = rand() % RANDOM_INT_SIZE + 1;
		multiQ_objArray[i] = multiQ(random_integer1 + random_integer2);
		cout << "Array size of multiQ object " << i+1 << " is: " << random_integer1 + random_integer2 
			 << endl;
	}
	cout << endl;
	cout << "Filling multiQ objects with random number of encapsulated values of random value." 
		 << endl << endl;\
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "Loading multiQ object " << i+1 << ": " << endl << endl;
		
		for (unsigned i = 0; i < random_integer1; i++)
		{
			random_integer1 = rand() % RANDOM_INT_SIZE + 1;
			random_integer2 = rand() % RANDOM_INT_SIZE + 1;
			if (!multiQ_objArray[i].isFull())
			{
				multiQ_objArray[i].Add(random_integer1 + random_integer2);
				cout << "MultiQ encapsulated factor value added is: " << random_integer1 + random_integer2 
					 << endl;
			}
		}
		cout << endl;
	}
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl << endl;
	cout << "Testing object arrays. The << operator is supported for every object\n" 
		 << "and will be tested throughout, along with every other test." << endl << endl;
}
void Test_Factor_Overloading(factor* factor_objArray)
{
	srand(time(NULL));
	unsigned random_integer;
	
	cout << "Testing overloaded operators for factor objects." << endl << endl;
	cout << "Testing arithmetic operators:" << endl << endl;
	cout << "(+)" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 + factor object1 is (" << factor_objArray[i] << " + " 
				 << factor_objArray[OBJ_ONE] << "): " << factor_objArray[i] + factor_objArray[OBJ_ONE]
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") + factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< factor_objArray[i] + factor_objArray[i+1] 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing + mixed mode operators int + factor and factor + int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") + " << random_integer << " is: "
		<< factor_objArray[i] + random_integer << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " + factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< factor_objArray[i] + random_integer << endl;
	}
	cout << endl;
	cout << "(-)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 - factor object1 is (" << factor_objArray[i] << " - " 
				 << factor_objArray[OBJ_ONE] << "): " << factor_objArray[i] - factor_objArray[OBJ_ONE]
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") - factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< factor_objArray[i] - factor_objArray[i+1] 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing - mixed mode operators int - factor and factor - int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") - " << random_integer << " is: "
		<< factor_objArray[i] - random_integer << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " - factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< random_integer - factor_objArray[i] << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	cout << "Testing relational operators:" << endl << endl;
	cout << "(>)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 > factor object1 is (" << factor_objArray[i] << " > " 
				 << factor_objArray[OBJ_ONE] << "): " << (factor_objArray[i] > factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") > factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< (factor_objArray[i] > factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing > mixed mode operators int > factor and factor > int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") > " << random_integer << " is: "
		<< (factor_objArray[i] > random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " > factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< (random_integer > factor_objArray[i]) << endl;
	}
	cout << endl;
	cout << "(>=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 >= factor object1 is (" << factor_objArray[i] << " >= " 
				 << factor_objArray[OBJ_ONE] << "): " << (factor_objArray[i] >= factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") >= factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< (factor_objArray[i] >= factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing >= mixed mode operators int >= factor and factor >= int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") >= " << random_integer << " is: "
		<< (factor_objArray[i] >= random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " >= factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< (random_integer >= factor_objArray[i]) << endl;
	}
	
	cout << endl;
	cout << "(<)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 < factor object1 is (" << factor_objArray[i] << " < " 
				 << factor_objArray[OBJ_ONE] << "): " << (factor_objArray[i] < factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") < factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< (factor_objArray[i] < factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing < mixed mode operators int < factor and factor < int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") < " << random_integer << " is: "
		<< (factor_objArray[i] < random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " < factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< (random_integer < factor_objArray[i]) << endl;
	}
	
	cout << endl;
	cout << "(<=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 <= factor object1 is (" << factor_objArray[i] << " <= " 
				 << factor_objArray[OBJ_ONE] << "): " << (factor_objArray[i] <= factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") <= factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< (factor_objArray[i] <= factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing <= mixed mode operators int <= factor and factor <= int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") <= " << random_integer << " is: "
		<< (factor_objArray[i] <= random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " <= factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< (random_integer <= factor_objArray[i]) << endl;
	}
	
	cout << endl;
	cout << "(==)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 == factor object1 is (" << factor_objArray[i] << " == " 
				 << factor_objArray[OBJ_ONE] << "): " << (factor_objArray[i] == factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") == factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< (factor_objArray[i] == factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing == mixed mode operators int == factor and factor == int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") == " << random_integer << " is: "
		<< (factor_objArray[i] == random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " == factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< (random_integer == factor_objArray[i]) << endl;
	}
	
	cout << endl;
	cout << "(!=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 != factor object1 is (" << factor_objArray[i] << " != " 
				 << factor_objArray[OBJ_ONE] << "): " << (factor_objArray[i] != factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") != factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: "<< (factor_objArray[i] != factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing != mixed mode operators int != factor and factor != int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") != " << random_integer << " is: "
		<< (factor_objArray[i] != random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " != factor object" << i+1 << " (" << factor_objArray[i] << ") is: "
		<< (random_integer != factor_objArray[i]) << endl;
	}
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing unary operators:" << endl << endl;
	cout << "(post ++)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ")++ returns: ";
			cout << (factor_objArray[i]++) << endl;
			cout << "Object" << i+1 << " called after post increment is: " << factor_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(++ pre)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Factor object" << i+1 << " ++(" << factor_objArray[i] << ") returns: ";
			cout << (++factor_objArray[i]) << endl;
			cout << "Object" << i+1 << " called after pre increment is: " << factor_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(post --)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ")-- returns: ";
			cout << (factor_objArray[i]--) << endl;
			cout << "Object" << i+1 << " called after post decrement is: " << factor_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(-- pre)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Factor object" << i+1 << " --(" << factor_objArray[i] << ") returns: ";
			cout << (--factor_objArray[i]) << endl;
			cout << "Object" << i+1 << " called after pre decrement is: " << factor_objArray[i] << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing assignment operators:" << endl << endl;
	cout << "(+=)" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 += factor object1 is (" << factor_objArray[i] << " += " 
				 << factor_objArray[OBJ_ONE] << "): " ;
			cout << (factor_objArray[i] += factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") += factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: ";
			cout << (factor_objArray[i] += factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing += mixed mode operators int += factor and factor += int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") += " << random_integer << " is: ";
		cout << (factor_objArray[i] += random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " += factor object" << i+1 << " (" << factor_objArray[i] << ") is: ";
		cout << (factor_objArray[i] += random_integer) << endl;
	}
	cout << endl << endl;
	cout << "(-=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Factor object3 -= factor object1 is (" << factor_objArray[i] << " -= " 
				 << factor_objArray[OBJ_ONE] << "): ";
			cout << (factor_objArray[i] -= factor_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") -=factor object" 
				 << i+2 << " (" << factor_objArray[i+1] << ") is: ";
			cout << (factor_objArray[i] -= factor_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing -= mixed mode operators int -= factor and factor -= int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Factor object" << i+1 << " (" << factor_objArray[i] << ") -= " << random_integer << " is: ";
		cout << (factor_objArray[i] -= random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " -= factor object" << i+1 << " (" << factor_objArray[i] << ") is: ";
		cout << (random_integer -= factor_objArray[i]) << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
}
void Test_Range_Overloading(range* range_objArray)
{

	srand(time(NULL));
	unsigned random_integer;
	
	cout << "Testing overloaded operators for range objects." << endl << endl;
	cout << "Testing arithmetic operators:" << endl << endl;
	cout << "(+)" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 + range object1 is (" << range_objArray[i] << " + " 
				 << range_objArray[OBJ_ONE] << "): " << range_objArray[i] + range_objArray[OBJ_ONE]
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") + range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< range_objArray[i] + range_objArray[i+1] 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing + mixed mode operators range + int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") + " << random_integer << " is: "
		<< range_objArray[i] + random_integer << endl;
	}
	cout << endl;
	
	cout << "(-)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 - range object1 is (" << range_objArray[i] << " - " 
				 << range_objArray[OBJ_ONE] << "): " << range_objArray[i] - range_objArray[OBJ_ONE]
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") - range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< range_objArray[i] - range_objArray[i+1] 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing - mixed mode operators range - int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") - " << random_integer << " is: "
		<< range_objArray[i] - random_integer << endl;
	}

	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing relational operators:" << endl << endl;
	cout << "(<)" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 < range object1 is (" << range_objArray[i] << " < " 
				 << range_objArray[OBJ_ONE] << "): " << (range_objArray[i] < range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") < range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< (range_objArray[i] < range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing < mixed mode operators range < int and int < range:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") < " << random_integer << " is: "
		<< (range_objArray[i] < random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " < range object" << i+1 << " (" << range_objArray[i] << ") is: "
			 << (random_integer < range_objArray[i]) << endl;
	}
	cout << endl;
	
	cout << "(<=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 <= range object1 is (" << range_objArray[i] << " <= " 
				 << range_objArray[OBJ_ONE] << "): " << (range_objArray[i] <= range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") <= range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< (range_objArray[i] <= range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing <= mixed mode operators range <= int and int <= range:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") <= " << random_integer << " is: "
		<< (range_objArray[i] <= random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " <= range object" << i+1 << " (" << range_objArray[i] << ") is: "
			 << (random_integer <= range_objArray[i]) << endl;
	}
	cout << endl;
	
	cout << "(>)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 > range object1 is (" << range_objArray[i] << " > " 
				 << range_objArray[OBJ_ONE] << "): " << (range_objArray[i] > range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") > range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< (range_objArray[i] > range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing > mixed mode operators range > int and int > range:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") > " << random_integer << " is: "
		<< (range_objArray[i] > random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " > range object" << i+1 << " (" << range_objArray[i] << ") is: "
			 << (random_integer > range_objArray[i]) << endl;
	}
	cout << endl;
	
	cout << "(>=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 >= range object1 is (" << range_objArray[i] << " >= " 
				 << range_objArray[OBJ_ONE] << "): " << (range_objArray[i] >= range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") >= range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< (range_objArray[i] >= range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing >= mixed mode operators range >= int and int >= range:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") >= " << random_integer << " is: "
		<< (range_objArray[i] >= random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " >= range object" << i+1 << " (" << range_objArray[i] << ") is: "
			 << (random_integer >= range_objArray[i]) << endl;
	}
	cout << endl;
	
	cout << "(==)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 == range object1 is (" << range_objArray[i] << " == " 
				 << range_objArray[OBJ_ONE] << "): " << (range_objArray[i] == range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") == range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< (range_objArray[i] == range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing == mixed mode operators range == int and int == range:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") == " << random_integer << " is: "
		<< (range_objArray[i] == random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " == range object" << i+1 << " (" << range_objArray[i] << ") is: "
			 << (random_integer == range_objArray[i]) << endl;
	}
	cout << endl;
	
	cout << "(!=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 != range object1 is (" << range_objArray[i] << " != " 
				 << range_objArray[OBJ_ONE] << "): " << (range_objArray[i] != range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") != range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: "<< (range_objArray[i] != range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing != mixed mode operators range != int and int != range:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") != " << random_integer << " is: "
		<< (range_objArray[i] != random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " != range object" << i+1 << " (" << range_objArray[i] << ") is: "
			 << (random_integer != range_objArray[i]) << endl;
	}
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing unary operators:" << endl << endl;
	cout << "(post ++)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ")++ returns: ";
			cout << (range_objArray[i]++) << endl;
			cout << "Object" << i+1 << " called after post increment is: " << range_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(++ pre)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Range object" << i+1 << " ++(" << range_objArray[i] << ") returns: ";
			cout << (++range_objArray[i]) << endl;
			cout << "Object" << i+1 << " called after pre increment is: " << range_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(post --)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ")-- returns: ";
			cout << (range_objArray[i]--) << endl;
			cout << "Object" << i+1 << " called after post decrement is: " << range_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(-- pre)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "Range object" << i+1 << " --(" << range_objArray[i] << ") returns: ";
			cout << (--range_objArray[i]) << endl;
			cout << "Object" << i+1 << " called after pre decrement is: " << range_objArray[i] << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing assignment operators: " << endl << endl;
	cout << "(+=)" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 += range object1 is (" << range_objArray[i] << " += " 
				 << range_objArray[OBJ_ONE] << "): ";
			cout << (range_objArray[i] += range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") += range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: ";
			cout << (range_objArray[i] += range_objArray[i+1])
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing += mixed mode operators range += int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") += " << random_integer << " is: ";
		cout << (range_objArray[i] += random_integer) << endl;
	}
	cout << endl;
	
	cout << "(-=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "Range object3 -= range object1 is (" << range_objArray[i] << " -= " 
				 << range_objArray[OBJ_ONE] << "): ";
			cout << (range_objArray[i] -= range_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "Range object" << i+1 << " (" << range_objArray[i] << ") -= range object" 
				 << i+2 << " (" << range_objArray[i+1] << ") is: ";
			cout << (range_objArray[i] -= range_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing -= mixed mode operators range -= int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "Range object" << i+1 << " (" << range_objArray[i] << ") -= " << random_integer << " is: ";
		cout << (range_objArray[i] -= random_integer) << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
}
void Test_MultiQ_Overloading(multiQ* multiQ_objArray)
{
	factor test_factor;
	srand(time(NULL));
	unsigned random_integer;
	
	cout << "Testing overloaded operators for multiQ objects." << endl << endl;
	cout << "Testing arithmetic operators:" << endl << endl;
	cout << "(+)" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "MultiQ object3 + multiQ object1 is (" << multiQ_objArray[i] << " + " 
				 << multiQ_objArray[OBJ_ONE] << "): " << multiQ_objArray[i] + multiQ_objArray[OBJ_ONE]
				 << endl;
		}
		else
		{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") + multiQ object" 
				 << i+2 << " (" << multiQ_objArray[i+1] << ") is: "<< multiQ_objArray[i] + multiQ_objArray[i+1] 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing + mixed mode operators multiQ + int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") + " << random_integer << " is: "
		<< multiQ_objArray[i] + random_integer << endl;
	}
	cout << endl;
	
	cout << "(-)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "MultiQ object3 - multiQ object1 is (" << multiQ_objArray[i] << " - " 
				 << multiQ_objArray[OBJ_ONE] << "): " << multiQ_objArray[i] - multiQ_objArray[OBJ_ONE]
				 << endl;
		}
		else
		{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") - multiQ object" 
				 << i+2 << " (" << multiQ_objArray[i+1] << ") is: "<< multiQ_objArray[i] - multiQ_objArray[i+1] 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing - mixed mode operators multiQ - int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_SMALLER_INT + 1;
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") - " << random_integer << " is: "
		<< multiQ_objArray[i] - random_integer << endl;
	}

	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing relational operators:" << endl << endl;
	cout << "(==)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "MultiQ object3 == multiQ object1 is (" << multiQ_objArray[i] << " == " 
				 << multiQ_objArray[OBJ_ONE] << "): " << (multiQ_objArray[i] == multiQ_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") == multiQ object" 
				 << i+2 << " (" << multiQ_objArray[i+1] << ") is: "<< (multiQ_objArray[i] == multiQ_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing == mixed mode operators multiQ == int and int == multiQ:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") == " << random_integer << " is: "
		<< (multiQ_objArray[i] == random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " == multiQ object" << i+1 << " (" << multiQ_objArray[i] << ") is: "
			 << (random_integer == multiQ_objArray[i]) << endl;
	}
	cout << endl;
	cout << "Testing == mixed mode operators multiQ == factor and factor == multiQ:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") == factor object (" 
		<< test_factor << ") is: " << (multiQ_objArray[i] == test_factor) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "Test factor (" << test_factor << ") == multiQ object" << i+1 << " (" 
			 << multiQ_objArray[i] << ") is: " << (test_factor == multiQ_objArray[i]) << endl;
	}
	cout << endl;
	
	cout << "(!=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "MultiQ object3 != multiQ object1 is (" << multiQ_objArray[i] << " != " 
				 << multiQ_objArray[OBJ_ONE] << "): " << (multiQ_objArray[i] != multiQ_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") != multiQ object" 
				 << i+2 << " (" << multiQ_objArray[i+1] << ") is: "<< (multiQ_objArray[i] != multiQ_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing != mixed mode operators multiQ != int and int != multiQ:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") != " << random_integer << " is: "
		<< (multiQ_objArray[i] != random_integer) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << random_integer << " != multiQ object" << i+1 << " (" << multiQ_objArray[i] << ") is: "
			 << (random_integer != multiQ_objArray[i]) << endl;
	}
	cout << endl;
	cout << "Testing != mixed mode operators multiQ != factor and factor != multiQ:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") != factor object (" 
		<< test_factor << ") is: " << (multiQ_objArray[i] != test_factor) << endl;
	}
	cout << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "Test factor (" << test_factor << ") != multiQ object" << i+1 << " (" 
			 << multiQ_objArray[i] << ") is: " << (test_factor != multiQ_objArray[i]) << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing unary operators:" << endl << endl;
	cout << "(post ++)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ")++ returns: ";
			cout << (multiQ_objArray[i]++) << endl;
			cout << "Object" << i+1 << " called after post increment is: " << multiQ_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(++ pre)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "MultiQ object" << i+1 << " ++(" << multiQ_objArray[i] << ") returns: ";
			cout << (++multiQ_objArray[i]) << endl;
			cout << "Object" << i+1 << " called after pre increment is: " << multiQ_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(post --)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ")-- returns: ";
			cout << (multiQ_objArray[i]--) << endl;
			cout << "Object" << i+1 << " called after post decrement is: " << multiQ_objArray[i] << endl;
	}
	cout << endl;
	
	cout << "(-- pre)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
			cout << "MultiQ object" << i+1 << " --(" << multiQ_objArray[i] << ") returns: ";
			cout << (--multiQ_objArray[i]) << endl;
			cout << "Object" << i+1 << " called after pre decrement is: " << multiQ_objArray[i] << endl;
	}
	
	cout << endl;
	cout << ASTERISK << endl;
	cout << "PRESS ENTER TO CONTINUE...";
	cin.get();
	cout << ASTERISK << endl;
	
	cout << "Testing assignment operators: " << endl << endl;
	cout << "(+=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "MultiQ object3 += multiQ object1 is (" << multiQ_objArray[i] << " += " 
				 << multiQ_objArray[OBJ_ONE] << "): ";
			cout << (multiQ_objArray[i] += multiQ_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") += multiQ object" 
				 << i+2 << " (" << multiQ_objArray[i+1] << ") is: ";
			cout << (multiQ_objArray[i] += multiQ_objArray[i+1])
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing += mixed mode operators multiQ += int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_INT_SIZE + 1;
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") += " << random_integer << " is: ";
		cout << (multiQ_objArray[i] += random_integer) << endl;
	}
	cout << endl;
	
	cout << "(-=)" << endl << endl;
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		if (i == ARRAY_SIZE - 1)
		{
			cout << "MultiQ object3 -= multiQ object1 is (" << multiQ_objArray[i] << " -= " 
				 << multiQ_objArray[OBJ_ONE] << "): ";
			cout << (multiQ_objArray[i] -= multiQ_objArray[OBJ_ONE])
				 << endl;
		}
		else
		{
			cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") -= multiQ object" 
				 << i+2 << " (" << multiQ_objArray[i+1] << ") is: ";
			cout << (multiQ_objArray[i] -= multiQ_objArray[i+1]) 
				 << endl;
		}
	}
	cout << endl;
	cout << "Testing -= mixed mode operators multiQ -= int:" << endl << endl;
	
	for (unsigned i = 0; i < ARRAY_SIZE; i++)
	{
		random_integer = rand() % RANDOM_SMALLER_INT + 1;
		cout << "MultiQ object" << i+1 << " (" << multiQ_objArray[i] << ") -= " << random_integer << " is: ";
		cout << (multiQ_objArray[i] -= random_integer) << endl;
	}
	cout << endl;
}