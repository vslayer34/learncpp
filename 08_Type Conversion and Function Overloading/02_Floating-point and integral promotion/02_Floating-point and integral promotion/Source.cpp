#include <iostream>

void printDouble(double d)
{
	std::cout << d << '\n';
}

void printInt(int x)
{
	std::cout << x << '\n';
}

int main()
{
	// Floating point promotions
	// Using the floating point promotion rules, a value of type float can be converted to a value of type double.
	// This means we can write a function that takes a double and then call it with either a double or a float value:
	{
		printDouble(5.0);				// no conversion necessary
		printDouble(4.0f);				// numeric promotion of float to double
	}
	std::cout << std::string(100, '-') << '\n';

	//---------------------------------------------------------------------------------------------------------------------------

	// Integral promotions
	// The integral promotion rules are more complicated.
	// Using the integral promotion rules, the following conversions can be made:
	// signed char or signed short can be converted to int.
	// unsigned char, char8_t, and unsigned short can be converted to int if int can hold the entire range of the type, or unsigned int otherwise.
	// If char is signed by default, it follows the signed char conversion rules above. 
	// If it is unsigned by default, it follows the unsigned char conversion rules above.
	// bool can be converted to int, with false becoming 0 and true becoming 1.

	// In most cases, this lets us write a function taking an int parameter, and then use it with a wide variety of other integral types. For example:
	{
		printInt(2);

		short s{ 3 };					// there is no short literal suffix, so we'll use a variable for this one
		printInt(s);					// numeric promotion of short to int
		
		printInt('a');					 // numeric promotion of char to int
		printInt(true);					 // numeric promotion of char to int
	}
	std::cout << std::string(100, '-') << '\n';
	
	return 0;
}