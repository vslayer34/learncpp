#include <iostream>
#include <string>														// allows use of std::string
#include <string_view>													// for std::string_view


int main()
{
	// Introducing std::string
	// The easiest way to work with strings and string objects in C++ is via the std::string type, which lives in the <string> header.
	// We can create objects of type std::string just like other objects:

	std::string name{  };												// empty string

	// Just like normal variables, you can initialize or assign values to std::string objects as you would expect:

	std::string name1{ "Alex" };										// initialize name with string literal "Alex"
	name1 = "John";														// change name to "John"


	// Note that strings can hold numbers as well:

	std::string myId{ "45" };											// "45" is not the same as integer 45!

	// In string form, numbers are treated as text, not as numbers, and thus they can not be manipulated as numbers(e.g.you can’t multiply them).
	// C++ will not automatically convert strings to integer or floating point values or vice - versa
	// (though there are ways to do so that we’ll cover in a future lesson).

	//------------------------------------------------------------------------------------------------------------------------------------

	// String output
	// std::string objects can be output as expected using std::cout:

	std::string name3{ "Mohamed" };
	std::cout << "My name is " << name3 << ".\n";
	std::cout << '\n';
	
	// Empty strings will print nothing:
	std::string empty{  };
	std::cout << '[' << empty << "]\n";
	std::cout << '\n';

	//------------------------------------------------------------------------------------------------------------------------------------

	// String input with std::cin
	// Using strings with std::cin may yield some surprises! Consider the following example:

	std::cout << "Enter your full name: ";
	std::string inputName{  };
	std::cin >> inputName;													// this won't work as expected since std::cin breaks on whitespace

	std::cout << "Enter your age: ";
	std::string inputAge{  };
	std::cin >> inputAge;

	std::cout << "Your name is " << inputName << " and your age is " << inputAge << '\n';
	std::cout << '\n';

	// Hmmm, that isn’t right! What happened? It turns out that when using operator>> to extract a string from std::cin.
	// operator>> only returns characters up to the first whitespace it encounters.
	// Any other characters are left inside std::cin, waiting for the next extraction.

	// So when we used operator>> to extract input into variable name, only "John" was extracted, leaving " Doe" inside std::cin.
	// When we then used operator>> to get extract input into variable age, it extracted "Doe" instead of waiting for us to input an age. Then the program ends.

	//------------------------------------------------------------------------------------------------------------------------------------

	// Use std::getline() to input text
	// To read a full line of input into a string, you’re better off using the std::getline() function instead.
	// std::getline() requires two arguments: the first is std::cin, and the second is your string variable.

	// Here’s the same program as above using std::getline():

	std::cout << "Enter your full name: ";
	std::string inputName2{  };
	std::getline(std::cin >> std::ws, inputName2);							// read a full line of text into name

	std::cout << "Enter your age: ";
	std::string inputAge2{  };
	std::getline(std::cin >> std::ws, inputAge2);							// read a full line of text into age

	std::cout << "Your name is " << inputName2 << " and your age is " << inputAge2 << '\n';
	std::cout << '\n';

	//------------------------------------------------------------------------------------------------------------------------------------

	// What the heck is std::ws?
	// The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction.
	// Leading whitespace is any whitespace character (spaces, tabs, newlines) that occur at the start of the string.

	//------------------------------------------------------------------------------------------------------------------------------------

	// String length

	std::string name4{ "Alex" };
	std::cout << name4 << " has " << name4.length() << " characters.\n";
	std::cout << '\n';

	// Also note that std::string::length() returns an unsigned integral value (most likely of type size_t).
	// If you want to assign the length to an int variable, you should static_cast it to avoid compiler warnings about signed/unsigned conversions:
	int length{ static_cast<int>(name4.length()) };

	// In C++20, you can also use the std::ssize() function to get the length of a std::string as a signed integer:
	std::cout << name4 << " has " << std::ssize(name4) << " characters.\n";

	//------------------------------------------------------------------------------------------------------------------------------------

	// Literals for std::string
	// Double-quoted string literals (like “Hello, world!”) are C-style strings by default (and thus, have a strange type).
	// We can create string literals with type std::string by using a s suffix after the double-quoted string literal.

	using namespace std::literals;											// easiest way to access the s and sv suffixes

	std::cout << "foo\n";													// no suffix is a C-style string literal
	std::cout << "goo\n"s;													// s suffix is a std::string literal
	std::cout << "moo\n"sv;													// sv suffix is a std::string_view literal

	//------------------------------------------------------------------------------------------------------------------------------------

	// Constexpr strings 
	// If you try to define a constexpr std::string, your compiler will probably generate an error:
	// This happens because constexpr std::string isn’t supported in C++17 or earlier, and only has minimal support in C++20.
	// If you need constexpr strings, use std::string_view instead (discussed in lesson 4.18 -- Introduction to std::string_view.

	//------------------------------------------------------------------------------------------------------------------------------------

	// Quiz time
	// Question #1
	// Write a program that asks the user to enter their full name and their age.
	// As output, tell the user the sum of their age and the number of letters in their name (use the std::string::length() member function to get the length of the string). 
	// For simplicity, count any spaces in the name as a letter.

	std::cout << "Enter your full name: ";
	std::string quizName{  };
	std::getline(std::cin >> std::ws, quizName);

	std::cout << "Enter your age: ";
	int quizAge{  };
	std::cin >> quizAge;

	int quizNameLength{ static_cast<int>(quizName.length()) };
	std::cout << "Your age + length of name is: " << quizAge + quizNameLength << '\n';
	std::cout << '\n';


	return 0;
}