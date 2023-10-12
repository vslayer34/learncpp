#include <iostream>

int main()
{
	// There are five basic types of numeric conversions.

	// 1. Converting an integral type to any other integral type (excluding integral promotions):
	{
		short s = 3;					// convert int to short
		long l = 3;						// convert int to long
		char ch = 5;					// convert short to char
		unsigned int ui = 3;			// convert int to unsigned int
	}

	// 2. Converting a floating point type to any other floating point type (excluding floating point promotions):
	{
		float f = 3.0f;					// convert double to float
		long double ld = 3.0;			// convert double to long double
	}

	// 3. Converting a floating point type to any integral type:
	{
		int i = 3.5;					// convert double to int
	}

	// 4. Converting an integral type to any floating point type:
	{
		double d = 3;					// convert int to double
	}

	// 5. Converting an integral type or a floating point type to a bool:
	{
		bool b1 = 3;					// convert int to bool
		bool b2 = 3.0;					// convert double to bool
	}

	//---------------------------------------------------------------------------------------------------------------------------

	// Safe and potentially unsafe conversions
	// Unlike a numeric promotion (which is always value-preserving and thus “safe”), some numeric conversions are not value-preserving in certain cases.
	// Such conversions are said to be “unsafe” (even though “potentially unsafe” is more accurate, as these conversions are value-preserving in other cases).

	// Numeric conversions fall into one of three safety categories:
	// 1. Value-preserving conversions are safe numeric conversions where the destination type can precisely represent all the values in the source type.
	// For example, int to long and short to double are safe conversions,
	// as the source value can always be converted to an equivalent value of the destination type.
	{
		int n{ 5 };
		long l = n;							// okay, produces long value 5

		short s{ 5 };
		double d = s;						// okay, produces double value 5.0
	}
	// Compilers will typically not issue warnings for implicit value-preserving conversions.

	// A value converted using a value-preserving conversion can always be converted back to the source type.
	// resulting in a value that is equivalent to the original value:
	{
		int n = static_cast<int>(static_cast<long>(3));			// convert int 3 to long and back
		std::cout << n << '\n';									// prints 3

		char c = static_cast<char>(static_cast<double>('c'));	// convert 'c' to double and back
		std::cout << c << '\n';									// prints 'c'
	}
	std::cout << std::string(100, '-') << '\n';

	
	// 2.Reinterpretive conversions are potentially unsafe numeric conversions where the result may be outside the range of the source type. 
	// Signed/unsigned conversions fall into this category.
	// For example, when converting a signed int to an unsigned int:
	{
		int n1{ 5 };
		//unsigned int u1{ n1 };									// okay: will be converted to unsigned int 5 (value preserved)

		int n2{ -5 };
		//unsigned int u2{ n2 };									// bad: will result in large integer outside range of signed int
	}

	// Values converted using a reinterpretive conversion can be converted back to the source type.
	// resulting in a value equivalent to the original value (even if the initial conversion produced a value out of range of the destination type).
	{
		int u = static_cast<int>(static_cast<unsigned int>(-5));		// convert '-5' to unsigned and back
		std::cout << u << '\n';											// prints -5
	}
	std::cout << std::string(100, '-') << '\n';

	
	// 3. Lossy conversions are potentially unsafe numeric conversions where some data may be lost during the conversion.
	// For example, double to int is a conversion that may result in data loss:
	{
		int i = 3.0;												// okay: will be converted to int value 3 (value preserved)
		int j = 3.5;												// data lost: will be converted to int value 3 (fractional value 0.5 lost)
	}

	// Conversion from double to float can also result in data loss:
	{
		float f = 1.2;												// okay: will be converted to float value 1.2 (value preserved)
		float g = 1.23456789;										// data lost: will be converted to float 1.23457 (precision lost)
	}

	// Converting a value that has lost data back to the source type will result in a value that is different than the original value:
	{
		double d = static_cast<int>(3.5);							// convert double 3.5 to int and back
		std::wcout << d << '\n';									// prints 3

		double d2 = static_cast<float>(1.23456789);					// convert double 1.23456789 to float and back
		std::wcout << d2 << '\n';									// prints 1.23457
	}
	std::cout << std::string(100, '-') << '\n';

	return 0;
}