#include <iostream>
#include <cmath>
#include <cstdint>																	// for std::int64_t
#include <cassert>																	// for assert


// note: exp must be non-negative
std::int64_t powInt(std::int64_t base, int exp)
{
	assert(exp >= 0 && "powInt: exp parameter has negative value");

	std::int64_t result{ 1 };

	while (exp)
	{
		if (exp && 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}


	return result;
}


int enterInteger()
{
	std::cout << "Enter an integer: ";
	int number{};
	std::cin >> number;

	return number;
}

void isEven(int number)
{
	if (number % 2 == 0)
		std::cout << number << " is even.\n";
	else
		std::cout << number << " is odd.\n";
}

void questionTwo()
{
	int inputNumber{ enterInteger() };

	isEven(inputNumber);
}

int main()
{
	// The modulus operator
	
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;


	std::cout << "The reminder is: " << x % y << '\n';

	if (x % y == 0)
		std::cout << x << " is evenly divided by " << y << '\n';
	else
		std::cout << x << " is not evenly divided by " << y << '\n';
	std::cout << '\n';

	//------------------------------------------------------------------------------------

	// Where’s the exponent operator?

	double num{ std::pow(3.0, 4.0) };											// 3 to the 4th power

	// Note that the parameters (and return value) of function pow() are of type double.
	// Due to rounding errors in floating point numbers, the results of pow() may not be precise (even if you pass it integers or whole numbers).

	// If you want to do integer exponentiation, you’re best off using your own function to do so.
	// The following function implements integer exponentiation (using the non-intuitive “exponentiation by squaring” algorithm for efficiency):

	std::cout << powInt(5, 2) << '\n';
	std::cout << powInt(7, 12) << '\n';									// 7 to the 12th power
	std::cout << '\n';

	//------------------------------------------------------------------------------------

	// Question #2
	// Write a program that asks the user to input an integer, and tells the user whether the number is even or odd.
	// Write a function called isEven() that returns true if an integer passed to it is even, and false otherwise.
	// Use the modulus operator to test whether the integer parameter is even.

	questionTwo();
	
	return 0;
}