#include <iostream>

int main()
{
	std::cout << "Chapter 1 summary and quiz" << "\n";
	std::cout << "**************************" << "\n";

	int num1{ }, num2{ };										// variables for input

	// Getteing the two input numbers
	std::cout << "Enter an integer: ";
	std::cin >> num1;
	std::cout << "Enter another integer: ";
	std::cin >> num2;

	// Display the addition(+) and sumition(-) of the two numbers
	std::cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
	std::cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";
	
	return 0;
}