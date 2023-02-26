#include <iostream>
#define MAX_STUDENTS_PER_CLASS 30

int main()
{
	// non-constant
	// their values can be changed at any time (typically through assignment of a new value).
	// For example:
	int x{ 4 };												// x is a non-constant variable
	x = 5;													// change value of x to 5 using assignment operator


	// To make a variable a constant, place the const keyword in the variable’s declaration either before or after the variable type, like so:

	const double gravity{ 9.8 };							// preferred use of const before type
	int const sidesInSquare{ 4 };							// "east const" style, okay but not preferred

	// Const variables must be initialized when you define them, and then that value can not be changed via assignment
	// ----------------------------------------------------------------------------------------------------------------

	// When compiling this program, the preprocessor will replace MAX_STUDENTS_PER_CLASS with the literal value 30
	// which the compiler will then compile into your executable.
	std::cout << "The class has " << MAX_STUDENTS_PER_CLASS << " students\n";


	// Prefer constant variables over object-like macros with substitution text.
	
	return 0;
}