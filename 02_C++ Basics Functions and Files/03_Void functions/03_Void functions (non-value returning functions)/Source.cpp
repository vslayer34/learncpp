#include <iostream>

void printHi()
{
	std::cout << "Hi\n";
}

int printTest()
{
	std::cout << "A";
	return 5;
	std::cout << "B";
}

int main()
{
	std::cout << "Hey Dell G5" << std::endl;
	printHi();
	std::cout << "***************************" << "\n";
	std::cout << printTest();
	
	return 0;
}