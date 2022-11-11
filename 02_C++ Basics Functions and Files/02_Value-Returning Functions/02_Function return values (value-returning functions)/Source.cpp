#include <iostream>

int returnFive()
{
	return 5;
}

int getValueFromUser()
{
	int input{  };
	std::cout << "Enter a number: ";
	std::cin >> input;

	return input;
}

int main()
{
	/*
	std::cout << returnFive() << "\n";
	std::cout << returnFive() + 2 << "\n";

	returnFive();
	*/

	/*
	int num{ getValueFromUser() };

	std::cout << num << " doubled is: " << num * 2 << "\n";
	*/

	int num1{ getValueFromUser() };
	int num2{ getValueFromUser() };

	std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";

	return 0;
}