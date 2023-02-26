#include <iostream>

int getNumber()
{
	std::cout << "Enter a number: ";
	int y{};
	std::cin >> y;

	return y;
}

int main()
{
	const int x{ 3 };															// x is a compile-time const
	const int y{ 4 };															// y is a compile-time const

	const int z{ x + y };														// x + y is a constant expression, so z is compile-time const

	std::cout << z << '\n';


	// Runtime const
	// Any const variable that is initialized with a non-constant expression is a runtime constant.
	// Runtime constants are constants whose initialization values aren’t known until runtime.


	const int num1{ 3 };														// num1 is a compile time constant
	const int num2{ getNumber() };												// num2 is a runtime const

	const int num3{ num1 + num2 };												// num3 is a runtime const

	std::cout << num3 << '\n';													// this is also a runtime expression


	// Even though num2 is const, the initialization value (the return value of getNumber()) isn’t known until runtime.
	// Thus, num2 is a runtime constant, not a compile-time constant.
	// And as such, the expression num1 + num2 is a runtime expression.


	// The constexpr keyword
	// A constexpr (which is short for “constant expression”) variable can only be a compile-time constant.
	// If the initialization value of a constexpr variable is not a constant expression, the compiler will error.

	constexpr double gravityConst{ 9.8 };										// ok: 9.8 is a constant expression
	constexpr int sum{ 4 + 5 };													// ok: 4 + 5 is a constant expression
	constexpr int something{ sum };												// ok: sum is a constant expression

	return 0;
}