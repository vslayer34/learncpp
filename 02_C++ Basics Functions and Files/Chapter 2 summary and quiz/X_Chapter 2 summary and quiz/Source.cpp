#include <iostream>
#include "io.h"

int main()
{
	std::cout << "A simple program to add two numbers" << "\n";
	int num1{ }, num2{ };
	num1 = readNumber();
	num2 = readNumber();

	writeAnswer(num1 + num2);
	
	return 0;
}