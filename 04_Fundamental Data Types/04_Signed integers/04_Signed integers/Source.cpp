#include <iostream>

int main()
{
	// Here is the preferred way to define the four types of signed integers:

	short s;
	int i;
	long l;
	long long ll;
	//------------------------------------------------------------------------------------------------------

	// The integer types can also take an optional signed keyword, which by convention is typically placed before the type name:
	signed short ss;
	signed int si;
	signed long sl;
	signed long long sll;


	// However, this keyword should not be used, as it is redundant, since integers are signed by default.
	//------------------------------------------------------------------------------------------------------


	// When dividing two integers, C++ works like you’d expect when the quotient is a whole number:
	
	std::cout << 20 / 4 << "\n";												// This produces the expected result: 5

	// But let’s look at what happens when integer division causes a fractional result:

	std::cout << 8 / 5 << "\n";
	// When doing division with two integers (called integer division), C++ always produces an integer result.
	// Since integers can’t hold fractional values, any fractional portion is simply dropped (not rounded!).




	
	return 0;
}