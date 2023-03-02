#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view str)
{
	std::cout << str << '\n';
}

void printString(std::string str)
{
	std::cout << str << '\n';
}

int main()
{
	// std::string_view C++17
	// To address the issue with std::string being expensive to initialize(or copy), C++17 introduced std::string_view(which lives in the <string_view> header).
	// std::string_view provides read - only access to an existing string(a C - style string literal, a std::string, or a char array) without making a copy.

	std::string_view s{ "Hello, World!" };
	printSV(s);
	std::cout << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------

	// constexpr std::string_view
	// Unlike std::string, std::string_view has full support for constexpr:

	constexpr std::string_view s1{ "Hello World!!" };
	std::cout << s1 << '\n';
	std::cout << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------

	std::string s2{ "Hello World!!!" };
	std::string_view sv{ s2 };															 // Initialize a std::string_view from a std::string
	std::cout << sv << '\n';
	std::cout << '\n';

	printSV(s2);																		// implicitly convert a std::string to std::string_view
	std::cout << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------

	// Converting a std::string_view to a std::string
	// Because std::string makes a copy of its initializer (which is expensive), C++ won’t allow implicit conversion of a std::string_view to a std::string.
	// However, we can explicitly create a std::string with a std::string_view initializer.
	// or we can convert an existing std::string_view to a std::string using static_cast:

	std::string_view sv1{ "Balloon" };
	
	std::string s3{ sv1 };																// okay, we can create std::string using std::string_view initializer
	//printString(sv1);																	// compile error: won't implicitly convert std::string_view to a std::string

	printString(static_cast<std::string>(sv1));											// okay, we can explicitly cast a std::string_view to a std::string
	std::cout << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------

	// Literals for std::string_view
	// Double-quoted string literals are C-style string literals by default.
	// We can create string literals with type std::string_view by using a sv suffix after the double-quoted string literal.

	using namespace std::literals;														// easiest way to access the s and sv suffixes
	
	std::cout << "foo\n";																// no suffix is a C-style string literal
	std::cout << "goo\n";																// s suffix is a std::string literal
	std::cout << "moo\n";																// sv suffix is a std::string_view literal

	//--------------------------------------------------------------------------------------------------------------------------------------

	//*********************************\\
	// Do not return a std::string_view||
	//*********************************//

	return 0;
}