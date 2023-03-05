#include <iostream>

int main()
{
	// Logical NOT
	// If logical NOT’s operand evaluates to true, logical NOT evaluates to false.
	// If logical NOT’s operand evaluates to false, logical NOT evaluates to true. 
	// In other words, logical NOT flips a Boolean value from true to false, and vice-versa.
	// Logical NOT is often used in conditionals:

	bool tooLarge{ 102 > 100 };
	if (!tooLarge);
		// do something
	else;
		// print an error


	// One thing to be wary of is that logical NOT has a very high level of precedence. New programmers often make the following mistake:
	int x1{ 5 };
	int y1{ 7 };

	if (!x1 > 7)
		std::cout << x1 << " is not greater than " << y1 << '\n';
	else
		std::cout << x1 << " is greater than " << y1 << '\n';
	std::cout << '\n';

	// This program prints: 5 is greater than 7
	// But x is not greater than y, so how is this possible?
	// The answer is that because the logical NOT operator has higher precedence than the greater than operator, 
	// the expression ! x > y actually evaluates as (!x) > y.
	// Since x is 5, !x evaluates to 0, and 0 > y is false, so the else statement executes!
	// The correct way to write the above snippet is:
	if (!(x1 > 7))
		std::cout << x1 << " is not greater than " << y1 << '\n';
	else
		std::cout << x1 << " is greater than " << y1 << '\n';
	std::cout << '\n';

	//----------------------------------------------------------------------------------------------------------------------

	// Logical OR
	// The logical OR operator is used to test whether either of two conditions is true.
	// If the left operand evaluates to true, or the right operand evaluates to true, or both are true, then the logical OR operator returns true. 
	// Otherwise it will return false.
	std::cout << "Enter a number: ";
	int value1{};
	std::cin >> value1;

	if (value1 == 0 || value1 == 1)
		std::cout << "You've picked 0 or 1" << '\n';
	else
		std::cout << "You've not picked 0 or 1" << '\n';
	// You can string together many logical OR statements:
	if (value1 == 0 || value1 == 1 || value1 == 2 || value1 == 3)
		std::cout << "You picked 0, 1, 2, or 3\n";
	std::cout << '\n';

	//----------------------------------------------------------------------------------------------------------------------

	// Logical AND
	// The logical AND operator is used to test whether both operands are true.
	// If both operands are true, logical AND returns true. Otherwise, it returns false.

	// For example, we might want to know if the value of variable x is between 10 and 20.
	// This is actually two conditions: we need to know if x is greater than 10, and also whether x is less than 20.
	std::cout << "Enter a number: ";
	int value2{};
	std::cin >> value2;

	if (value2 > 10 && value2 < 20)
		std::cout << "Your value is between 10 and 20\n";
	else
		std::cout << "Your value is not between 10 and 20\n";
	std::cout << '\n';

	// As with logical OR, you can string together many logical AND statements:
	if (value2 > 10 && value2 < 20 && value2 != 16);
		// do something
	else;
		// do something else

	//----------------------------------------------------------------------------------------------------------------------

	// Many programmers assume that logical AND and logical OR have the same precedence (or forget that they don’t),
	// just like addition/subtraction and multiplication/division do. 
	// However, logical AND has higher precedence than logical OR,
	// thus logical AND operators will be evaluated ahead of logical OR operators (unless they have been parenthesized).
	
	return 0;
}