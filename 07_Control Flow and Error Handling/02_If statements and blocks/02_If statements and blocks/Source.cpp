#include <iostream>

int main()
{
	// Quick if-statement recap
	// Here is a simple program that uses an if statement with the optional else statement:
	{
		std::cout << "Enter a number: ";
		int x{};
		std::cin >> x;

		if (x > 10)
			std::cout << x << " is greater than 10" << '\n';
		else
			std::cout << x << " is less than 10" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------------

	// If or else with multiple conditional statements
	// New programmers often try something like this:
	{
		std::cout << "Enter your height (in cm): ";
		int height{};
		std::cin >> height;

		if (height > 140)
			std::cout << "You're tall enough to ride." << '\n';
		else
			std::cout << "You're not tall enough to ride." << '\n';
			std::cout << "Too bad!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// This program doesn’t work as expected because the true_statementand false_statement can only be a single statement.
	// The indentation is deceiving us here -- the above program executes as if it had been written as follows :

	{
		std::cout << "Enter your height (in cm): ";
		int height{};
		std::cin >> height;

		if (height > 140)
			std::cout << "You're tall enough to ride." << '\n';
		else
			std::cout << "You're not tall enough to ride." << '\n';

		std::cout << "Too bad!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// However, it’s common to want to execute multiple statements based on some condition.
	// To do so, we can use a compound statement (block):
	{
		std::cout << "Enter your height (in cm): ";
		int height{};
		std::cin >> height;

		if (height > 140)
			std::cout << "You're tall enough to ride." << '\n';
		else
		{	// note: addition of block here
			std::cout << "You're not tall enough to ride." << '\n';
			std::cout << "Too bad!" << '\n';
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------------


	
	return 0;
}