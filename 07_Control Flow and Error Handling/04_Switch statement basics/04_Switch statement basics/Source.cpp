#include <iostream>

// Although it is possible to chain many if-else statements together, this is both difficult to read and inefficient. 
// Consider the following program:
void printDigitNumber(int num)
{
	if (num == 1)
		std::cout << "One" << '\n';
	else if (num == 2)
		std::cout << "Two" << '\n';
	else if (num == 3)
		std::cout << "Three" << '\n';
	else
		std::cout << "Unknow" << '\n';
}

// Because testing a variable or expression for equality against a set of different values is common, 
// C++ provides an alternative conditional statement called a switch statement that is specialized for this purpose. 
// Here is the same program as above using a switch:
void printDigitNumberSwitch(int num)
{
	switch (num)
	{
		case 1:
			std::cout << "One" << '\n';
			break;
		case 2:
			std::cout << "Two" << '\n';
			break;
		case 3:
			std::cout << "Three" << '\n';
			break;
		default:
			std::cout << "Unknow" << '\n';
			break;
	}
}

int main()
{
	{
		printDigitNumber(2);
	}
	std::cout << std::string(50, '-') << '\n';

	{
		printDigitNumberSwitch(3);
	}
	std::cout << std::string(50, '-') << '\n';

	
	return 0;
}