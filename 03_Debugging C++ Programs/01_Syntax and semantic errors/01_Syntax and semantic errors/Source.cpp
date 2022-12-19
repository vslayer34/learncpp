#include <iostream>

int add(int x, int y)
{
	return x - y; // function is supposed to add, but it doesn't (logical error)
}


int main()
{
	std::cout << "Hey Dell G5" << std::endl;
	
	/*
	std::cout < "Hi there"; << x;	// invalid operator (<), extraneous semicolon, undeclared variable (x)
	*/

	/*
	int a { 10 };
    int b { 0 };
    std::cout << a << " / " << b << " = " << a / b; // division by 0 is undefined
	*/


	/*
	return 0						// missing semicolon at end of statement
	*/
	return 0;
}