#include <iostream>

// Comma as a separator
void add(int x, int y) { }													// avoid compile error

void foo(int x, int y)													// Comma used to separate parameters in function definition
{
	add(x, y);															// Comma used to separate arguments in function call
	constexpr int z{ 3 }, w{ 5 };										// Comma used to separate multiple variables being defined on the same line (don't do this)
}

//--------------------------------------------------------------------------------------------------------------------

int main()
{
	// The comma operator
	// The comma operator (,) allows you to evaluate multiple expressions wherever a single expression is allowed. 
	// The comma operator evaluates the left operand, then the right operand, and then returns the result of the right operand.
	// For example:
	int x1{ 1 };
	int y1{ 2 };

	std::cout << (++x1, ++y1) << '\n';										// increment x and y, evaluates to the right operand

	// z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
	// z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded.

	// This makes the comma operator somewhat dangerous to use.
	// In almost every case, a statement written using the comma operator would be better written as separate statements. 
	// For example, the above code could be written as:

	++x1;
	std::cout << ++y1 << '\n';

	//--------------------------------------------------------------------------------------------------------------------

	// The conditional operator
	// The conditional operator (?:) (also sometimes called the “arithmetic if” operator) is a ternary operator (it takes 3 operands).
	// Because it has historically been C++’s only ternary operator, it’s also sometimes referred to as “the ternary operator”.

	// Consider an if/else statement that looks like this:
	int larger{};
	if (x1 > y1)
		larger = x1;
	else
		larger = y1;

	// can be rewritten as:
	larger = (x1 > y1) ? x1 : y1;

	//--------------------------------------------------------------------------------------------------------------------

	// Parenthesization of the conditional operator
	// Note that the ?: operator has a very low precedence.
	// If doing anything other than assigning the result to a variable, the whole ?: operator also needs to be wrapped in parentheses.

	//--------------------------------------------------------------------------------------------------------------------

	// The conditional operator evaluates as an expression
	// Because the conditional operator operands are expressions rather than statements, the conditional operator can be used in some places where if/else can not.
	// For example, when initializing a constant variable:

	constexpr bool inBigClassroom{ false };
	constexpr int classSize{ inBigClassroom ? 30 : 20 };
	std::cout << "The class size is: " << classSize << '\n';
	
	// There’s no satisfactory if/else statement for this. You might think to try something like this:

	/*
	constexpr bool inBigClassroom { false };

    if (inBigClassroom)
        constexpr int classSize { 30 };
    else
        constexpr int classSize { 20 };

    std::cout << "The class size is: " << classSize << '\n';
	*/

	// However, this won’t compile, and you’ll get an error message that classSize isn’t defined. 
	// Much like how variables defined inside functions die at the end of the function, 
	// variables defined inside an if or else statement die at the end of the if or else statement.
	// Thus, classSize has already been destroyed by the time we try to print it.

	/*
	int getClassSize(bool inBigClassroom)
	{
		if (inBigClassroom)
			return 30;

		return 20;
	}

	int main()
	{
		const int classSize { getClassSize(false) };
		std::cout << "The class size is: " << classSize << '\n';

		return 0;
	}
	*/

	// This one works because we’re not defining variables inside the if or else,
	// we’re just returning a value back to the caller,
	//  which can then be used as the initializer.
	// That’s a lot of extra work!

	//--------------------------------------------------------------------------------------------------------------------


	return 0;
}