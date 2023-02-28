#include <iostream>

int main()
{
	// Literals are unnamed values inserted directly into the code. For example:

	bool myNameIsAlex{ true };										// true is a boolean literal
	std::cout << 3.4 << '\n';										// 3.4 is a double literal

	// You generally won’t need to use suffixes for integral literals, but here are examples:
	std::cout << 5 << '\n';											// 5 (no suffix) is type int (by default)
	std::cout << 5L << '\n';										// 5L is type long


	// One exception is the u(or ‘U’) suffix, which is used to denote an unsigned integer literal:
	unsigned int x{ 5u };											// 5u is type unsigned int
	std::cout << x << '\n';


	// Floating point literals
	// By default, floating point literals have a type of double.
	// To make them float literals instead, the f (or F) suffix should be used:

	std::cout << 5.0 << '\n';										// 5.0 (no suffix) is type double (by default)
	std::cout << 5.0f << '\n';										// 5.0f is type float

	// Scientific notation for floating point literals
	double pi{ 3.14159 };											// 3.14159 is a double literal in standard notation
	double avogadro{ 6.02e23 };										// 6.02 x 10^23 is a double literal in scientific notation

	// In the second form, the number after the exponent can be negative:
	double electronCharge{ 1.6e-19 };								// charge on an electron is 1.6 x 10^-19



	
	return 0;														// 0 is an integer literal
}