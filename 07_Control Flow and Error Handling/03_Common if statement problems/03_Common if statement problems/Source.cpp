#include <iostream>

int main()
{
	// Nested if statements and the dangling else problem
	// It is possible to nest if statements within other if statements:
	{
		std::cout << "Enter a number: ";
		int num{};
		std::cin >> num;

		if (num >= 0)									// outer if statement
			// it is bad coding style to nest if statements this way
			if (num <= 20)								// inner if statement
				std::cout << num << " is between 0 and 20." << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// Now consider the following program:

	{
		std::cout << "Enter a number: ";
		int num{};
		std::cin >> num;

		if (num >= 0)									// outer if statement
			// it is bad coding style to nest if statements this way
			if (num <= 20)								// inner if statement
				std::cout << num << " is between 0 and 20." << '\n';

		// which if statement does this else belong to?
			else
				std::cout << num << " is negative." << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// The above program introduces a source of potential ambiguity called a dangling else problem. 
	// Is the else statement in the above program matched up with the outer or inner if statement?

	// The answer is that an else statement is paired up with the last unmatched if statement in the same block. 
	// Thus, in the program above, the else is matched up with the inner if statement,
	// as if the program had been written like this:
	{
		std::cout << "Enter a number: ";
		int num{};
		std::cin >> num;

		if (num >= 0) // outer if statement
		{
			if (num <= 20) // inner if statement
				std::cout << num << " is between 0 and 20\n";
			else // attached to inner if statement
				std::cout << num << " is negative\n";
		}
	}
	std::cout << std::string(50, '-') << '\n';

	// To avoid such ambiguities when nesting if statements, it is a good idea to explicitly enclose the inner if statement within a block. 
	// This allows us to attach an else to either if statement without ambiguity:
	{
		std::cout << "Enter a number: ";
		int num{};
		std::cin >> num;

		if (num >= 0)
		{
			if (num <= 20)
				std::cout << num << " is between 0 and 20." << '\n';
			
			else									// attached to inner if statement
				std::cout << num << " is greater than 20." << '\n';
		}
		else										// attached to outer if statement
			std::cout << num << " is negative." << '\n';
	}

	//-----------------------------------------------------------------------------------------------------------------------

	// Flattening nested if statements
	// For example, the above example can be flattened as follows:
	{
		std::cout << "Enter a number: ";
		int num{};
		std::cin >> num;

		if (num < 0)
			std::cout << num << " is negative." << '\n';
		
		else if (num <= 20)									// only executes if x >= 0
			std::cout << num << " is between 0 and 20." << '\n';

		else												// only executes if x > 20
			std::cout << num << " is greater than 20." << '\n';
	}

	// Here’s another example that uses logical operators to check multiple conditions within a single if statement:

	{
		std::cout << "Enter a number: ";
		int num1{};
		std::cin >> num1;

		std::cout << "Enter another number: ";
		int num2{};
		std::cin >> num2;

		if (num1 > 0 && num2 > 0)							// && is logical and -- checks if both conditions are true
			std::cout << "Both numbers are positive." << '\n';

		else if (num1 > 0 || num2 > 0)						// || is logical or -- checks if either condition is true
			std::cout << "One of the numbers is positive." << '\n';

		else
			std::cout << "Neither number is positive." << '\n';
	}

	//-----------------------------------------------------------------------------------------------------------------------

	// Null statements
	// A null statement is an expression statement that consists of just a semicolon:
	// Null statements do nothing. They are typically used when the language requires a statement to exist but the programmer doesn’t need one. 
	// For readability, null statements are typically placed on their own lines.
	{
		if (11 > 10)
			;												// this is a null statement
	}
	
	//-----------------------------------------------------------------------------------------------------------------------

	// Operator== vs Operator= inside the conditional
	// Inside your conditional, you should be using operator== when testing for equality, not operator= (which is assignment).
	// Consider the following program:

	{
		std::cout << "Enter 0 or 1: ";
		int num{};
		std::cin >> num;

		if (num = 0)											// oops, we used an assignment here instead of a test for equality
			std::cout << "You entered 0." << '\n';
		else
			std::cout << "You entered 1." << '\n';
	}
	// In fact, this program will always produce the result You entered 1. 
	// This happens because x = 0 first assigns the value 0 to x, then evaluates to the value of x, which is now 0, which is Boolean false.
	// Since the conditional is always false, the else statement always executes.


	return 0;
}