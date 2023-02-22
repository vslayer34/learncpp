#include <iostream>

int main()
{
	// A sample program using an if statement
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	/*
	if (x == 0)
		std::cout << "The value is zero\n";
	else
		std::cout << "the value is non-zero\n";
	*/


	// Chaining if statements
	if (x > 0)
		std::cout << "The value is positive\n";
	else if (x < 0)
		std::cout << "The value is negative\n";
	else
		std::cout << "The value is zero\n";
	
	return 0;
}