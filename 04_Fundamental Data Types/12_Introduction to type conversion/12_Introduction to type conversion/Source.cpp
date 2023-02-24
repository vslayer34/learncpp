#include <iostream>


void print(double x)
{
	std::cout << x << '\n';
}


void printInt(int x)
{
	std::cout << x << '\n';
}


int getInt(char x)
{
	return x;
}


int main()
{
	// implicit type conversion
	int y{ 5 };
	print(y);
	
	// In the above example, the conversion does not change variable y from type int to double.
	// Instead, the conversion uses the value of y(5) as input to create a new double value(5.0).
	// This double value is then passed to function print.


	// explicit type conversion via the static_cast operator
	printInt(static_cast<int>(5.5));
	
	std::cout << '\n';


	char ch{ 97 };												//97 is ASCII code for 'a'
	std::cout << ch << '\n';
	std::cout << ch << " has value " << static_cast<int>(ch) << '\n';



	// Question #1

	// Write a short program where the user is asked to enter a single character.Print the value of the characterand its ASCII code, using static_cast.

	std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	std::cout << "You entered '" << c << "', which has ASCII code " << static_cast<int>(c) << '\n';
	std::cout << '\n';

	// Modify the program you wrote for quiz #1 to use implicit type conversion instead of static_cast. How many different ways can you think of to do this?
	// using printInt() and getInt()
	std::cout << "You entered '" << c << "', which has ASCII code " << getInt(c) << '\n';



	return 0;
}