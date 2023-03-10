#include <iostream>

// Although function parameters are not defined inside the function body, 
// for typical functions they can be considered to be part of the scope of the function body block.
int max(int x, int y)													// x and y enter scoop here
{
	// assign the greater of y or x to max
	int max{ (y > x) ? y : x };											// max enters scoop here

	return max;
}																		// max, y and x leave scoop here


int main()
{
	// Local variables have block scope
	int i1{ 5 };														// i1 enters scoop here
	double d1{ 4.0 };													// d1 enters scoop here

	//--------------------------------------------------------------------------------------------------------------
	
	// All variable names within a scope must be unique
	// Variable names must be unique within a given scope, otherwise any reference to the name will be ambiguous.
	// Consider the following program:
	int x{};
	//int x{};															// compilation failure due to name collision with function parameter

	//--------------------------------------------------------------------------------------------------------------

	// Local variables have automatic storage duration
	// A variable’s storage duration (usually just called duration) determines what rules govern when and how a variable will be created and destroyed.
	// In most cases, a variable’s storage duration directly determines its lifetime.

	// For example, local variables have automatic storage duration,
	// which means they are created at the point of definition and destroyed at the end of the block they are defined in. 
	// For example:
	int a1{ 5 };														// a1 is created and initialized here
	double b1{ 4.0 };													// b1 is created and initialized here

	//--------------------------------------------------------------------------------------------------------------

	// Local variables in nested blocks
	// Local variables can be defined inside nested blocks. This works identically to local variables in function body blocks:
	{																	// outer block
		
		int x{ 5 };														// x entered the scoop and is created here

		{																// nested block

			int y{ 7 };													// y enterd the scoop and is created here
			std::cout << x << " + " << y << " = " << x + y << '\n';		// x and y are both in scope here
			std::cout << '\n';
		
		}																// y goes out of scope and is destroyed here

		// y can't be used here because it is out of scope in this block

	}																	// x goes out of the scoop and destroyed here

	//--------------------------------------------------------------------------------------------------------------

	// Local variables have no linkage
	// Identifiers have another property named linkage. 
	// An identifier’s linkage determines whether other declarations of that name refer to the same object or not.
	// Local variables have no linkage, which means that each declaration refers to a unique object. 
	// For example:
	{
		int x{ 2 };														// local variable, no linkage

		{
			int x{ 3 };													// this identifier x refers to a different object than the previous x
		}
	}

	//--------------------------------------------------------------------------------------------------------------

	// Variables should be defined in the most limited scope
	// If a variable is only used within a nested block, it should be defined inside that nested block:
	{
		// do not define y here

		{
			// y is only used inside this block, so define it here
			int y{ 5 };
			std::cout << y << '\n';
			std::cout << '\n';
		}
	}

	// By limiting the scope of a variable, you reduce the complexity of the program because the number of active variables is reduced.
	//  Further, it makes it easier to see where variables are used (or aren’t used). 
	// A variable defined inside a block can only be used within that block (or nested blocks). 
	// This can make the program easier to understand.
	
	// If a variable is needed in an outer block, it needs to be declared in the outer block:
	{
		int y{ 5 };														// we're declaring y here because we need it in the outer block later.

		{
			int x{};
			std::cin >> x;

			// if we declared y here, immediately before its actual first use...
			if (x == 4)
				y = 4;

		}	// ... it would be destroyed here

		std::cout << y << '\n';											// and we need y to exist here
		std::cout << '\n';
	}

	//--------------------------------------------------------------------------------------------------------------

	// Quiz time
	// question #1

	// Write a program that asks the user to enter two integers, one named smaller, the other named larger. 
	// If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. 
	// Then print the values of the smaller and larger variables.
	//  Add comments to your code indicating where each variable dies.
	//  Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.
	
	{
		// first user input
		std::cout << "Enter an integer: ";
		int smaller{};
		std::cin >> smaller;

		// second user input
		std::cout << "Enter a larger integer: ";
		int larger;
		std::cin >> larger;

		// if user enterd the numbers wrong
		if (larger < smaller)
		{
			std::cout << "Swapping the values...." << '\n';

			int temp{ larger };
			larger = smaller;
			smaller = temp;
		}	// temp is destroyed here

		
		// display results
		std::cout << "The smaller value is: " << smaller << '\n';
		std::cout << "The larger value is: " << larger << '\n';
	}
	
	return 0;
}																		// d1 and i1 out of scoop here
// a1 and b1 ared destroyed here