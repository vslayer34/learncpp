#include <iostream>

int value{ 5 };																// global variable

void foo()
{
	std::cout << "global variable value (foo()): " << value << '\n';				// value is not shadowed her, so this refers to the global variable
}

int main()
{
	// Each block defines its own scope region. So what happens when we have a variable inside a nested block that has the same name as a variable in an outer block?
	//  When this happens, the nested variable “hides” the outer variable in areas where they are both in scope.
	// This is called name hiding or shadowing.

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------

	// Shadowing of local variables
	{	// outer block

		int apples{ 5 };													// here's the outer block apples

		{	// nested block

			// apples refer to the outer block apples here
			std::cout << "Number of apples: " << apples << '\n';

			int apples{ 0 };												// define apples in the scope of the nested block

			// apples now refer to the nested block apples
			// the outer block apples is temporarily hidden

			apples = 10;													// this assign value of 10 to nested block apples, not outer block apples

			std::cout << "Number of apples: " << apples << '\n';			// print values of nested block apples

		}	// nested block apples destroyed

		std::cout << "Number of apples: " << apples << '\n';				// print value of outer block apples

	}	// outer block apples destroyed
	std::cout << std::string(50, '-') << '\n';

	//----------------------------------------------------------------------------------------------------------------------------------------------------------------

	// Shadowing of global variables
	// Similar to how variables in a nested block can shadow variables in an outer block,
	// local variables with the same name as a global variable will shadow the global variable wherever the local variable is in scope:

	// However, because global variables are part of the global namespace,
	// we can use the scope operator (::) with no prefix to tell the compiler we mean the global variable instead of the local variable.

	{
		int value{ 7 };														// hides the global value untill the end of this block

		++value;															// increments local value, not the global value

		--(::value);														// decrements global value, not local value (parenthesis added for readability)

		std::cout << "local variable value: " << value << '\n';
		std::cout << "global variable value: " << ::value << '\n';

		foo();
	}
	std::cout << std::string(50, '-') << '\n';


	
	return 0;
}