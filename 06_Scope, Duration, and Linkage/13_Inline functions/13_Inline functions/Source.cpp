#include <iostream>

inline int min(int x, int y)													// hint to the compiler that it should do inline expansion of this function
{
	return (x < y) ? x : y;
}

int main()
{
	// one downside of using a function is that every time a function is called,
	// there is a certain amount of performance overhead that occurs. 
	// Consider the following example:
	{
		std::cout << min(5, 6) << '\n';
		std::cout << min(3, 2) << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//----------------------------------------------------------------------------------------------------------------------

	// Inline expansion
	// Fortunately, the C++ compiler has a trick that it can use to avoid such overhead cost:
	// Inline expansion is a process where a function call is replaced by the code from the called function’s definition.

	// For example, if the compiler expanded the min() calls in the above example, the resulting code would look like this:
	{
		std::cout << ((5 < 6) ? 5 : 6) << '\n';
		std::cout << ((3 < 2) ? 3 : 2) << '\n';
	}
	// Note that the two calls to function min() have been replaced by the code in the body of the min() function (with the value of the arguments substituted for the parameters).
	// This allows us to avoid the overhead of those calls, while preserving the results of the code.

	//----------------------------------------------------------------------------------------------------------------------

	// Inline expansion is best suited to simple, short functions (e.g. no more than a few statements),
	// especially cases where a single function call is executed more than once (e.g. function calls inside a loop).

	//----------------------------------------------------------------------------------------------------------------------

	// The inline keyword, historically
	// Historically, compilers either didn’t have the capability to determine whether inline expansion would be beneficial,
	// or were not very good at it. For this reason, C++ provides the keyword inline,
	// which was intended to be used as a hint to the compiler that a function would benefit from being expanded inline:
	
	return 0;
}