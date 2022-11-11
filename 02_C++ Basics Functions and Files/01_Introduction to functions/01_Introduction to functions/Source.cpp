#include <iostream>

void doPrint()
{
	std::cout << "In doPrint()\n";
}

void doB()
{
	std::cout << "In doB()\n";
}

void doA()
{
	std::cout << "Starting doA()\n";
	doB();
	std::cout << "Ending doA()\n";
}

int main()
{
	/*
	std::cout << "Starting main()\n";
	doPrint();
	doPrint();
	std::cout << "Ending main()\n";
	*/

	std::cout << "Starting main()\n";
	doA();
	std::cout << "Ending main()\n";
	
	return 0;
}