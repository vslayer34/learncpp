#include <iostream>
#include <bitset>															// for std::bitset

int main()
{
	// By default, numbers in C++ programs are assumed to be decimal:
	int decimalNumber{ 12 };												// 12 is assumed to be a decimal number
	std::cout << "12 in decimal: " << decimalNumber << '\n';
	std::cout << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------

	// To use an octal literal, prefix your literal with a 0 (zero):
	int octalNumber{ 012 };													// 0 before the number means this is octal
	std::cout << "10 in octal: " << octalNumber << '\n';
	std::cout << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------

	// To use a hexadecimal literal, prefix your literal with 0x.
	int hexadecimalNumber{ 0xF };											// 0x before the number means this is hexadecimal
	std::cout << "F in octal: " << hexadecimalNumber << '\n';
	std::cout << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------

	// Prior to C++14, there is no support for binary literals.
	// However, hexadecimal literals provide us with a useful workaround (that you may still see in existing code bases):
	int bin{};																// assume 16-bit ints
	bin = 0x0001;															// assign binary 0000 0000 0000 0001 to the variable
	bin = 0x0002;															// assign binary 0000 0000 0000 0010 to the variable
	bin = 0x0004;															// assign binary 0000 0000 0000 0100 to the variable
	bin = 0x0008;															// assign binary 0000 0000 0000 1000 to the variable
	bin = 0x0010;															// assign binary 0000 0000 0001 0000 to the variable
	bin = 0x0020;															// assign binary 0000 0000 0010 0000 to the variable
	bin = 0x0040;															// assign binary 0000 0000 0100 0000 to the variable
	bin = 0x0080;															// assign binary 0000 0000 1000 0000 to the variable
	bin = 0x00FF;															// assign binary 0000 0000 1111 1111 to the variable
	bin = 0x00B3;															// assign binary 0000 0000 1011 0011 to the variable
	bin = 0xF770;															// assign binary 1111 0111 0111 0000 to the variable

	//-----------------------------------------------------------------------------------------------------------------------------

	// In C++14, we can use binary literals by using the 0b prefix:
	int bin2{};																// assume 16-bit ints
	bin2 = 0b1;																// assign binary 0000 0000 0000 0001 to the variable
	std::cout << bin2 << '\n';
	bin2 = 0b11;																// assign binary 0000 0000 0000 0011 to the variable
	std::cout << bin2 << '\n';
	bin2 = 0b1010;															// assign binary 0000 0000 0000 1010 to the variable
	std::cout << bin2 << '\n';
	bin2 = 0b11110000;														// assign binary 0000 0000 1111 0000 to the variable
	std::cout << bin2 << '\n';
	std::cout << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------

	// Because long literals can be hard to read, C++14 also adds the ability to use a quotation mark (‘) as a digit separator.
	int bin3{ 0b1011'0010 };												// assign binary 1011 0010 to the variable
	long value{ 2'132'673'462 };											// much easier to read than 2132673462

	// Also note that the separator can not occur before the first digit of the value
	//int bin{ 0b'1011'0010 };												// error: ' used before first digit of value

	// Digit separators are purely visual and do not impact the literal value in any way.

	//-----------------------------------------------------------------------------------------------------------------------------

	// By default, C++ outputs values in decimal.
	// However, you can change the output format via use of the std::dec, std::oct, and std::hex I/O manipulators:

	int decimalNumber2{ 12 };

	std::cout << decimalNumber2 << '\n';									// decimal (by default)
	std::cout << std::hex << decimalNumber2 << '\n';						// hexadecimal
	std::cout << decimalNumber2 << '\n';									// now hexadecimal

	std::cout << std::oct << decimalNumber2 << '\n';						// octal
	std::cout << std::dec << decimalNumber2 << '\n';						// return to decimal
	std::cout << decimalNumber2 << '\n';									// decimal
	std::cout << '\n';

	// Note that once applied, the I/O manipulator remains set for future output until it is changed again.

	//-----------------------------------------------------------------------------------------------------------------------------

	// Outputting values in binary
	// The C++ standard library includes a type called std::bitset that will do this for us (in the <bitset> header).

	// std::bitset<8> means we want to store 8 bits

	std::bitset<8> binNumber1{ 0b1100'0101 };								// binary literal for binary 1100 0101
	std::bitset<8> binNumber2{ 0xC5 };										// hexadecimal literal for binary 1100 0101

	std::cout << binNumber1 << '\n' << binNumber2 << '\n';
	std::cout << std::bitset<4>{ 0b1010 } << '\n';							// create a temporary std::bitset and print it
	
	return 0;
}