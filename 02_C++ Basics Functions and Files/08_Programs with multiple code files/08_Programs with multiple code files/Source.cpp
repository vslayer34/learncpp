#include <iostream>

int getInteger();
int add(int x, int y);

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " = " << add(x, y) << "\n";

	return 0;
}