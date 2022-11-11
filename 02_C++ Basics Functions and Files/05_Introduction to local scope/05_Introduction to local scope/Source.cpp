#include <iostream>

int add(int x, int y)		// function parameters x and y are local variables
{
	int z{ x + y };			// z is a local variable too

	return z;
}

void doIt(int x)
{
	int y{ 4 };
	std::cout << "doIt(): x = " << x << "    y = " << y << "\n";

	x = 3;
	std::cout << "doIt(): x = " << x << "    y = " << y << "\n";
}

int main()
{
	std::cout << "Hey Dell G5" << std::endl;
	int x{ 1 }, y{ 2 };

	std::cout << "main(): x = " << x << "    y = " << y << "\n";

	doIt(x);

	std::cout << "main(): x = " << x << "    y = " << y << "\n";
	
	return 0;
}