#include <iostream>


bool isEqual(int x, int y)
{
	return (x == y);
}


int main()
{
	// To declare a Boolean variable, we use the keyword bool.
	bool b;


	// To initialize or assign a true or false value to a Boolean variable, we use the keywords true and false.
	bool b1{ true };
	bool b2{ false };

	b1 = false;
	bool b3{};																// default initialize to false


	// The logical NOT operator (!) can be used to flip a Boolean value from true to false, or false to true:
	bool b4{ !true };														// b3 will be initialized with the value false
	bool b5{ !false };														// b4 will be initialized with the value true


	// When we print Boolean values, std::cout prints 0 for false, and 1 for true:
	std::cout << true << "\n";												// true evaluates to 1
	std::cout << !true << "\n";												// !true evaluates to 0

	bool b6{ false };

	std::cout << b6 << "\n";
	std::cout << !b6 << "\n";
	std::cout << "\n";


	// If you want std::cout to print “true” or “false” instead of 0 or 1, you can use std::boolalpha. Here’s an example:
	std::cout << true << "\n";
	std::cout << false << "\n";

	std::cout << std::boolalpha;											// print bools as true or false

	std::cout << true << "\n";
	std::cout << false << "\n";
	std::cout << "\n";

	// You can use std::noboolalpha to turn it back off.
	//std::cout << std::noboolalpha;



	// Boolean values are often used as the return values for functions that check whether something is true or not.
	// Such functions are typically named starting with the word is (e.g. isEqual) or has (e.g. hasCommonDivisor).

	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << x << " and " << y << " are equal?\n";
	std::cout << isEqual(x, y) << "\n";

	
	return 0;
}