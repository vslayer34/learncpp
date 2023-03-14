#include <iostream>

// Automatic duration (default):
void incrementAndPrint()
{
	int value{ 1 };														// automatic duration by default
	++value;
	std::cout << "Autamitic duration: " << value << '\n';
}	// value is destroyed here

// Static duration (using static keyword):
void staticIncrementAndPrint()
{
	static int s_value{ 1 };												// static duration via static keyword, this initilaizer is only excuted once
	++s_value;
	std::cout << "static duration: " << s_value << '\n';
}	// s_value is not destroyed here, but becomes inaccessible because it goes out of scope

// Generating a unique ID number is very easy to do with a static duration local variable:
int generateID()
{
	static int s_itemID{ 0 };
	
	// makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
	return s_itemID++;
}

int main()
{
	// Static local variables
	// Using the static keyword on a local variable changes its duration from automatic duration to static duration. 
	// This means the variable is now created at the start of the program, and destroyed at the end of the program (just like a global variable). 
	// As a result, the static variable will retain its value even after it goes out of scope!

	// Automatic duration (default):
	{
		incrementAndPrint();
		incrementAndPrint();
		incrementAndPrint();
	}
	std::cout << std::string(55, '-') << '\n';

	// Static duration (using static keyword):
	{
		staticIncrementAndPrint();
		staticIncrementAndPrint();
		staticIncrementAndPrint();
	}
	std::cout << std::string(55, '-') << '\n';

	return 0;
}