#include <iostream>


// Error case 2: Extraction succeeds but with extraneous input
void ignorLine()
{
	// To ignore everything up to and including the next ‘\n’ character, we call
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Error case 3: Extraction fails
double getDouble()
{
	while (true)		// loop until the user enters a valid input
	{
		std::cout << "Enter a double value: ";
		double num{};
		std::cin >> num;
		if (std::cin.fail())	// has the previouse extraction failed
		{
			// handle the failure
			std::cerr << "Invalid input, please try again." << '\n';
			std::cout << "--------------------------------" << '\n';
			std::cin.clear();	// put the program in "normal" operation mode
			ignorLine();		// remove all the bad input
		}
		else
		{
			ignorLine();
			return num;
		}
	}
}

// Error case 1: Extraction succeeds but input is meaningless
char getOperator()
{
	while (true)				// loops untill user enters a valid input
	{
		std::cout << "Enter one of the following operators (+, -, * or /): ";
		char operation{};
		std::cin >> operation;
		ignorLine();

		// check whether the user entered a meaningfull input
		switch (operation)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return operation;			// return it to the caller
		default:						// otherwise tell the user what went wrong
			std::cerr << "Oops, The operator you enterd (" << operation << ") is invalid, please make sure and try again." << '\n';
		}
		
	}
}


void printResult(double x, char operation, double y)
{
	std::cout << std::string(10, '-') << '\n';
	switch (operation)
	{
	case '+':
		std::cout << x << " + " << y << " is: " << x + y << '\n';
		break;
	case '-':
		std::cout << x << " - " << y << " is: " << x - y << '\n';
		break;
	case '*':
		std::cout << x << " * " << y << " is: " << x * y << '\n';
		break;
	case '/':
		std::cout << x << " / " << y << " is: " << x / y << '\n';
		break;
	}
}

int main()
{
	// A sample program
	// Consider the following calculator program that has no error handling:
	{
		double num1{ getDouble() };
		char operation{ getOperator() };
		double num2{ getDouble() };

		printResult(num1, operation, num2);
	}
	std::cout << std::string(50, '-') << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------------------



	return 0;
}