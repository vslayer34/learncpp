#include <iostream>

int main()
{
	// To define an unsigned integer, we use the unsigned keyword. By convention, this is placed before the type:
	unsigned short us;
	unsigned int ui;
	unsigned long ul;
	unsigned long long ull;


	// --------------------------------------------------------------------------------------------------------------------
	// --------------------------------------------------------------------------------------------------------------------
	// Let’s take a look at this using 2-byte shorts:
	unsigned short x{ 65535 };
	std::cout << "x is now: " << x << "\n";


	x = 65536;												// 65536 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << "\n";


	x = 65537;												// 65537 is out of our range, so we get wrap-around
	std::cout << "x is now: " << x << "\n";


	// --------------------------------------------------------------------------------------------------------------------
	// --------------------------------------------------------------------------------------------------------------------


	// It’s possible to wrap around the other direction as well. 0 is representable in a 2-byte unsigned integer, so that’s fine.
	// -1 is not representable, so it wraps around to the top of the range, producing the value 65535. -2 wraps around to 65534. And so forth.

	unsigned short y{ 0 };
	std::cout << "y is now: " << y << "\n";

	y = -1;													// -1 is out of our range, so we get wrap-around
	std::cout << "y is now: " << y << '\n';

	y = -2;													// -2 is out of our range, so we get wrap-around
	std::cout << "y is now: " << y << '\n';



	
	return 0;
}