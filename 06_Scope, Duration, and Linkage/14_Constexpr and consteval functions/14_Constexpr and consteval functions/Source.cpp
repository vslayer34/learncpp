#include <iostream>

// Consteval functions provides a way to make this happen, using a neat helper function:
consteval auto compileTime(auto value)
{
	return value;
}

int isGreater(int x, int y)
{
	return (x > y) ? x : y;												// here's our expression
}

constexpr int greater(int x, int y)												// now a constexpr function
{
	return (x > y) ? x : y;
}

consteval int greater20(int x, int y)									// function is now consteval
{
	return (x > y) ? x : y;
}

int main()
{
	{
		constexpr int x{ 5 };
		constexpr int y{ 6 };

		std::cout << ((x > y) ? x : y) << " is greater." << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// Because x and y are constexpr, the compiler can evaluate the constant expression (x > y ? x : y) at compile-time,
	// reducing it to just 6. Because this expression no longer needs to be evaluated at runtime, our program will run faster.

	// However, having a non-trivial expression in the middle of our print statement isn’t ideal -- it would be better if the expression were a named function.
	// Here’s the same example using a function:
	{
		constexpr int x{ 5 };
		constexpr int y{ 6 };

		std::cout << isGreater(x, y) << " is greater!." << '\n';	// will be evaluated at runtime
	}
	std::cout << std::string(50, '-') << '\n';

	// This program produces the same output as the prior one.
	// But there’s a downside to putting our expression in a function: the call to greater(x, y) will execute at runtime. 
	// By using a function (which is good for modularity and documentation) we’ve lost our ability for that code to be evaluated at compile-time (which is bad for performance).

	//--------------------------------------------------------------------------------------------------------------------------------------

	// Constexpr functions can be evaluated at compile-time
	// A constexpr function is a function whose return value may be computed at compile-time.
	// To make a function a constexpr function, we simply use the constexpr keyword in front of the return type.
	// Here’s a similar program to the one above, using a constexpr function:

	{
		constexpr int x{ 5 };
		constexpr int y{ 6 };

		constexpr int g{ greater(x, y) };							// will be evaluated at compile-time

		std::cout << g << " is greater!!." << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// This produces the same output as the prior example, but the function call greater(x, y) will be evaluated at compile-time instead of runtime!
	// When a function call is evaluated at compile-time, the compiler will calculate the return value of the function call, and then replace the function call with the return value.
	// So in our example, the call to greater(x, y) will be replaced by the result of the function call, which is the integer value 6. 
	// In other words, the compiler will compile this:
	{
		constexpr int x{ 5 };
		constexpr int y{ 6 };

		constexpr int g{ 6 }; // greater(x, y) evaluated and replaced with return value 6

		std::cout << g << " is greater!!!.\n";
	}
	std::cout << std::string(50, '-') << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------

	// Constexpr functions can also be evaluated at runtime
	// Functions with a constexpr return value can also be evaluated at runtime,
	// in which case they will return a non-constexpr result. For example:
	{
		int x{ 5 };										// not constexpr
		int y{ 6 };										// not constexpr

		std::cout << greater(x, y) << " is greater!!!!." << '\n';						// will be evaluated at runtime
	}
	std::cout << std::string(50, '-') << '\n';
	// In this example, because arguments x and y are not constexpr, the function cannot be resolved at compile-time.
	// However, the function will still be resolved at runtime, returning the expected value as a non-constexpr int.

	//--------------------------------------------------------------------------------------------------------------------------------------

	// Consteval C++20
	// C++20 introduces the keyword consteval, which is used to indicate that a function must evaluate at compile-time, 
	// otherwise a compile error will result. Such functions are called immediate functions.

	{
		constexpr int g{ greater20(5, 6) };											// ok: will evaluate at compile-time
		std::cout << greater20(5, 6) << " is greater!!!!!." << '\n';				// ok: will evaluate at compile-time

		int x{ 5 };																	// not constexpr
		std::cout << greater(x, 6) << " is greater!\n";								// error: consteval functions must evaluate at compile-time
	}

	//--------------------------------------------------------------------------------------------------------------------------------------

	// Using consteval to make constexpr execute at compile-time C++20
	// The downside of consteval functions is that such functions can’t evaluate at runtime, making them less flexible than constexpr functions, which can do either.
	// Therefore, it would still be useful to have a convenient way to force constexpr functions to evaluate at compile-time 
	// (even when the return value is being used where a constant expression is not required), 
	// so that we could have compile-time evaluation when possible, and runtime evaluation when we can’t.
	{
		std::cout << greater(5, 6) << '\n';											// may or may not execute at compile-time
		std::cout << compileTime(greater(5, 6)) << '\n';							// will execute at compile-time

		int x{ 5 };
		std::cout << greater(x, 6) << '\n';											// we can still call the constexpr version at runtime if we wish
	}
	
	return 0;
}