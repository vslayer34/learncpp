#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: " << "\n";
	int input{ };
	std::cin >> input;
	return input;
}
void writeAnswer(int answer)
{
	std::cout << "The answer is: " << answer << "\n";
}