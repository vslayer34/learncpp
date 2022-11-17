#include <iostream>

#define MY_NAME "Mohamed"
#define PRINT_JOE
#define PRINT

void doSomething();					// forward declaration

int main()
{
	std::cout << "My Name is: " << MY_NAME << "\n";

#ifdef PRINT_JOE
	std::cout << "Joe" << "\n";
#endif // PRINT_JOE

#ifdef PRINT_BOB
	std::cout << "Bob" << "\n";
#endif // PRINT_BOB

#ifndef PRINT_SARA
	std::cout << "Sara" << "\n";
#endif // !PRINT_SARA


	// Prevent that code from compiling
#if 0
	std::cout << "Bad Day!!!!" << "\n";
#endif

#define FOO 9

#ifdef FOO
	std::cout << FOO << "\n";
#endif // FOO

	doSomething();
	
	return 0;
}