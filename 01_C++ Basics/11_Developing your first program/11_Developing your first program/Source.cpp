#include <iostream>

int main()
{
	std::cout << "Hey Dell G5" << std::endl;
	std::cout << "Enter an integer: ";			// ask th user for input
	int num{  };								// variable to store than input
	std::cin >> num;

	// do the required operations on the input
	std::cout << "Double of " << num << " is : " << num * 2 << "\n";
	std::cout << "Triple of " << num << " is : " << num * 3 << "\n";
	
	return 0;
}