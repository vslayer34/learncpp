#include <iostream>

//#define ENABLE_DEBUG		// comment out to disable debugging

int getUserInput()
{
	/*
#ifdef ENABLE_DEBUG
	std::cerr << "getUserInput() called\n";
#endif // ENABLE_DEBUG
	*/

	std::cout << "Enter a number: " << "\n";
	int x{ };
	std::cin >> x;
	return x;
}

int main()
{
	/*
#ifdef ENABLE_DEBUG
	std::cerr << "main() called\n";
#endif // ENABLE_DEBUG
	*/

	int x{ getUserInput() };
	std::cout << "You entered: " << x << "\n";
	return 0;
}