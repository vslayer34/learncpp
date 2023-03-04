#include <iostream>

int add(int x, int y)
{
	return x + y;
}

int main()
{
	// Incrementing and decrementing variables
	// The prefix increment/decrement operators are very straightforward.
	// First, the operand is incremented or decremented, and then expression evaluates to the value of the operand.
	// For example:
	int x1{ 5 };
	int y1 = ++x1;											// x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

	std::cout << x1 << " >> " << y1 << '\n';
	std::cout << '\n';


	// The postfix increment/decrement operators are trickier. 
	// First, a copy of the operand is made. Then the operand (not the copy) is incremented or decremented. 
	// Finally, the copy (not the original) is evaluated.
	// For example:
	int x2{ 5 };
	int y2 = x2++;											// x is incremented to 6, copy of original x is evaluated to the value 5, and 5 is assigned to y

	std::cout << x2 << " >> " << y2 << '\n';
	std::cout << '\n';

	// Here is another example showing the difference between the prefix and postfix versions:
	int x3{ 5 };
	int y3{ 5 };

	std::cout << x3   << "    "  << y3  << '\n';
	std::cout << ++x3 << " >> " << --y3 << '\n';			// prefix
	std::cout << x3   << "    " << y3   << '\n';
	std::cout << x3++ << " >> " << y3-- << '\n';			// postfix
	std::cout << x3   << "    " << y3   << '\n';
	std::cout << '\n';

	//---------------------------------------------------------------------------------------------------------------------

	// Side effects can cause undefined behavior

	int x5{ 5 };
	int value{ add(x5, ++x5) };							// is this 5 + 6, or 6 + 6?
	// It depends on what order your compiler evaluates the function arguments in

	std::cout << value << '\n';								// value could be 11 or 12, depending on how the above line evaluates!


	// The C++ standard does not define the order in which function arguments are evaluated.
	// If the left argument is evaluated first, this becomes a call to add(5, 6), which equals 11. 
	// If the right argument is evaluated first, this becomes a call to add(6, 6), which equals 12!
	// Note that this is only a problem because one of the arguments to function add() has a side effect.
	
	return 0;
}