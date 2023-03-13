#include <iostream>

int g_mode;																// declare a golabal variable (will be zero-initilaized by default)

void doSomething()
{
	g_mode = 2;															// set the global g_mode variable to 2
}

int main()
{
	// Why (non-const) global variables are evil
	// By far the biggest reason non-const global variables are dangerous is because their values can be changed by any function that is called,
	// and there is no easy way for the programmer to know that this will happen.
	// Consider the following program:

	{
		g_mode = 1;														// note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

		doSomething();

		// programmer still expects g_mode to be 1
		// but doSomething() changed it to 2

		if (g_mode == 1)
		{
			std::cout << "No threats detected." << '\n';
		}
		else
		{
			std::cout << "Launching nuclear missiles...." << '\n';
		}
	}
	std::cout << std::string(50, '-') << '\n';
	
	return 0;
}