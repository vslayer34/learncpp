#include <iostream>

int getValueFromUser()
{
	int input{};
	std::cout << "Enter an inteager: ";
	std::cin >> input;

	return input;
}

void printDouble(int value)
{
	std::cout << value << " doubled is: " << value * 2 << "\n";
}

int add(int x, int y)
{
	return x + y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	int num{ getValueFromUser() };
	printDouble(num);

	std::cout << add(3, 4) << "\n";					// return 3 + 4 = 7
	std::cout << add(1 + 2, 3 * 4) << "\n";			// returns (1 + 2) + (3 * 4) = 15

	int a{ 5 };
	std::cout << add(5, 5) << "\n";					// returns a(5) + a(5) = 10

	std::cout << add(1, multiply(2, 3)) << "\n";	// returns 1 + (2 * 3) = 7
	std::cout << add(1, add(2, 3)) << "\n";		// returns 1 + (2 + 3) = 6

	
	return 0;
}