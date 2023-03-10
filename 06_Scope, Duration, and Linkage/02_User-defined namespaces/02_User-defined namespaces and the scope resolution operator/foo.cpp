#include <iostream>

namespace foo														// define a namespace named foo
{
	// This doSomething() adds the value of its parameters
	int doSomething(int x, int y)
	{
		return x + y;
	}

	void print()													// this print lives in the foo namespace
	{
		std::cout << "Hello";
	}

	namespace moo
	{
		int add(int x, int y)
		{
			return x + y;
		}
	}
}