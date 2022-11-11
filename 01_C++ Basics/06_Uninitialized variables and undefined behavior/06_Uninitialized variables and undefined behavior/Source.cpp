#include <iostream>

void doNothing(int&)
{
	// Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
}

int main()
{
	int x; // this variable is uninitialized because we haven't given it a value
	
	doNothing(x);		// make the compiler think we're assigning a value to this variable

	std::cout << x;
	
	return 0;
}