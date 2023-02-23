#include <iostream>


bool isPrime(int num)
{
	if (num == 2)
		return true;
	else if (num == 3)
		return true;
	else if (num == 5)
		return true;
	else if (num == 7)
		return true;
	else
		return false;
}



bool isAllowedToTakeFunRide()
{
	std::cout << "How tall are you? (cm)\n";
	double height{};
	std::cin >> height;

	return (height > 140.0);
}

int main()
{
	/*
	// A sample program using an if statement
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	
	if (x == 0)
		std::cout << "The value is zero\n";
	else
		std::cout << "the value is non-zero\n";
	


	// Chaining if statements
	if (x > 0)
		std::cout << "The value is positive\n";
	else if (x < 0)
		std::cout << "The value is negative\n";
	else
		std::cout << "The value is zero\n";
	*/

	// Quiz time
	// Question #1

	// A prime number is a whole number greater than 1 that can only be divided evenly by 1 and itself.
	// Write a program that asks the user to enter a number 0 through 9 (inclusive).
	// If the user enters a number within this range that is prime (2, 3, 5, or 7), print “The digit is prime”.
	// Otherwise, print “The digit is not prime”.


	/*
	std::cout << "Enter an integer between 0 and 9: ";
	int num{};
	std::cin >> num;

	if (isPrime(num))
		std::cout << "The digit is prime\n";
	else
		std::cout << "The digit is not prime\n";
	*/


	if (isAllowedToTakeFunRide())
		std::cout << "Have fun!!\n";
	else
		std::cout << "Sorry, You're too short!\n";

	return 0;
}