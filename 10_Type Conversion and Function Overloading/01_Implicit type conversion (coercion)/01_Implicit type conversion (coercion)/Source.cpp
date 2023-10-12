#include <iostream>

float doSomething()
{
	return 3.0;						// double value 3.0 implicitly converted to type float
}

void doSomethingV2(long l)
{

}

int main()
{
	// Implicit type conversion
	// Implicit type conversion (also called automatic type conversion or coercion) is performed automatically by the compiler when one data type is required,
	// but a different data type is supplied. 
	// The vast majority of type conversions in C++ are implicit type conversions.
	//  For example, implicit type conversion happens in all of the following cases:

	{
		double d{ 3 };				// int value 3 implicitly converted to type double
		d = 6;						// int value 6 implicitly converted to type double
	}

	// When the type of a return value is different from the function’s declared return type:
	{
		// see doSomething function
	}

	// When using certain binary operators with operands of different types:
	{
		double division{ 4.0 / 3 };	// int value 3 implicitly converted to type double
	}

	// When using a non-Boolean value in an if-statement:
	{
		if (5)
		{
			// int value 5 implicitly converted to type bool
		}
	}

	// When an argument passed to a function is a different type than the function parameter:
	{
		doSomethingV2(3);			// int value 3 implicitly converted to type long
	}

	//--------------------------------------------------------------------------------------------------------------------


	
	return 0;
}