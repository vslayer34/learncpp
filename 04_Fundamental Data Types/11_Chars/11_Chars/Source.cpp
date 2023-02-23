#include <iostream>

int main()
{
	// You can initialize char variables using character literals:
	char ch2{ 'a' };														// initialize with code point for 'a' (stored as integer 97) (preferred)

	// You can initialize chars with integers as well, but this should be avoided if possible
	char ch1{ 97 };															// initialize with integer 97 ('a') (not preferred)



	// When using std::cout to print a char, std::cout outputs the char variable as an ASCII character:
	char ch3{ 'a' };														// prefered
	std::cout << ch3 << "\n";

	char ch4{ 98 };															// code point for 'b' (not preferred)
	std::cout << ch4 << "\n";

	// We can also output char literals directly:
	std::cout << 'c' << "\n";
	std::cout << "\n";


	// Inputting chars
	// The following program asks the user to input a character, then prints out the character:
	std::cout << "Input a keyboard character: ";

	char ch{};
	std::cin >> ch;

	std::cout << "You entered (" << ch << ")\n";
	std::cout << "\n";


	/*
	Alert				\a					Makes an alert, such as a beep
	Backspace			\b					Moves the cursor back one space
	Formfeed			\f					Moves the cursor to next logical page
	Newline				\n					Moves cursor to next line
	Carriage return		\r					Moves cursor to beginning of line
	Horizontal tab		\t					Prints a horizontal tab
	Vertical tab		\v					Prints a vertical tab
	Single quote		\’					Prints a single quote
	Double quote		\”					Prints a double quote
	Backslash			\\					Prints a backslash.
	Question mark		\?					Prints a question mark. No longer relevant.You can use question marks unescaped.
	Octal number		\(number)			Translates into char represented by octal
	Hex number			\x(number)			Translates into char represented by hex number
	*/


	// Here are some examples:
	std::cout << "\"This is a quoted text\"\n";
	std::cout << "This string contains a single backslash\\n";
	std::cout << "6F in hex is char '\x6F'\n";
	
	return 0;
}