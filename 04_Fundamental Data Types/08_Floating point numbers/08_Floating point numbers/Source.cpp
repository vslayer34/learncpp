#include <iostream>
#include <iomanip>

int main()
{
	float fValue;
	double dValue;
	long double ldValue;


	int x{ 5 };															// means 5 integer
	double y{ 5.0 };													// no suffix means double type by default
	float z{ 5.0f };													// f suffix means float type


	// Printing floating point numbers
	std::cout << 5.0 << "\n";
	std::cout << 6.7f << "\n";
	std::cout << 9876543.21 << "\n";
	std::cout << "\n";


	// The following program shows std::cout truncating to 6 digits:
	std::cout << 9.87654321f << '\n';
	std::cout << 987.654321f << '\n';
	std::cout << 987654.321f << '\n';
	std::cout << 9876543.21f << '\n';
	std::cout << 0.0000987654321f << '\n';
	std::cout << "\n";


	// Output manipulators alter how data is output, and are defined in the iomanip header.
	std::cout << std::setprecision(16);									// show 16 digits of precision
	std::cout << 3.33333333333333333333333333333333333333f << '\n';		// f suffix means float
	std::cout << 3.33333333333333333333333333333333333333 << '\n';		// no suffix means double
	std::cout << "\n";


	// Float values typically have 7 digits of precision (and the result of 123456792 is precise only to 7 significant digits).
	// We lost some precision! When precision is lost because a number can’t be stored precisely, this is called a rounding error.


	double d{ 0.1 };
	std::cout << d << "\n";												// use default cout precision of 6
	std::cout << std::setprecision(17);
	std::cout << d << "\n";
	std::cout << "\n";


	std::cout << std::setprecision(17);

	// Rounding errors can have unexpected consequences:
	double d1{ 1.0 };
	std::cout << d1 << "\n";

	double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };
	std::cout << d2 << "\n";											// should be 1.0
	std::cout << "\n";


	// NaN and Inf
	// Inf are only available if the compiler uses a specific format (IEEE 754) for floating point numbers.
	// If another format is used, the following code produces undefined behavior.
	std::cout << std::setprecision(6);

	double zero{ 0.0 };
	
	double positiveInf{ 5.0 / zero };
	std::cout << positiveInf << "\n";


	double negativeInf{ -5.0 / zero };
	std::cout << negativeInf << "\n";


	double nan{ zero / zero };
	std::cout << nan << "\n";

	
	return 0;
}