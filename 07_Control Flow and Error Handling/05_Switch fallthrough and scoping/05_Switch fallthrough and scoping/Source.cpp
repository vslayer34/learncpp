#include <iostream>

// You can use the logical OR operator to combine multiple tests into a single statement:
bool isVowl(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Sequential case labels
// You can combine multiple tests into a single statement using switch statements by placing multiple case labels in sequence:

bool isVOwlSwitch(char c)
{
	switch (c)
	{
	case 'a':				// if c is 'a'
	case 'e':				// or if c is 'e'
	case 'i':				// or if c is 'i'
	case 'o':				// or if c is 'o'
	case 'u':				// or if c is 'u'
	case 'A':				// or if c is 'A'
	case 'E':				// or if c is 'E'
	case 'I':				// or if c is 'I'
	case 'O':				// or if c is 'O'
	case 'U':				// or if c is 'U'
		return true;
	default:
		return false;
	}
}

// Question #1
int calculate(int num1, int num2, char op)
{
	switch (op)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	default:
		std::cerr << "calculate(): Unkown operator. error code: ";
		return 0;
	}
}


int main()
{
	// Fallthrough
	// When a switch expression matches a case label or optional default label, execution begins at the first statement following the matching label.
	// Execution will then continue sequentially until one of the following termination conditions happens:

	// The end of the switch block is reached.
	// Another control flow statement(typically a break or return) causes the switch block or function to exit.
	// Something else interrupts the normal flow of the program(e.g.the OS shuts the program down, the universe implodes, etc…)

	// Here is a program that exhibits this behavior:
	{
		switch (2)
		{
		case 1:												// doesn't match
			std::cout << 1 << '\n';							// skipped
		case 2:												// Match!
			std::cout << 2 << '\n';							// Execution begins here
		case 3:
			std::cout << 3 << '\n';							// This is also executed
		case 4:
			std::cout << 4 << '\n';							// This is also executed
		case 5:
			std::cout << 5 << '\n';							// This is also executed
		}
		std::cout << std::string(50, '-') << '\n';

		//------------------------------------------------------------------------------------------------------------------

		// The [[fallthrough]] attribute
		// Attributes are a modern C++ feature that allows the programmer to provide the compiler with some additional data about the code. 
		// To specify an attribute, the attribute name is placed between double hard braces. 
		// Attributes are not statements -- rather, they can be used almost anywhere where they are contextually relevant.

		// The [[fallthrough]] attribute modifies a null statement to indicate that fallthrough is intentional (and no warnings should be triggered):
		{
			switch (2)
			{
			case 1:
				std::cout << 1 << '\n';
				break;
			case 2:
				std::cout << 2 << '\n';						// Execution begins here
				[[fallthrough]];							// intentional fallthrough -- note the semicolon to indicate the null statement
			case 3:
				std::cout << 3 << '\n';						// This is also executed
				break;
			}
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Switch case scoping

	// With if statements, you can only have a single statement after the if-condition, and that statement is considered to be implicitly inside a block:
	{
		if (11 > 10)
			std::cout << "11 is greater than 10." << '\n';			// This line implicitly considered to be inside a block
	}
	std::cout << std::string(50, '-') << '\n';

	// However, with switch statements, the statements after labels are all scoped to the switch block. No implicit blocks are created.
	{
		switch (1)
		{
		case 1:											// does not create an implicit block
			std::cout << "One." << '\n';				// this is part of the switch scope, not an implicit block to case 1
			break;										// this is part of the switch scope, not an implicit block to case 1
		default:
			std::cout << "Default case." << '\n';
			break;
		}
	}
	std::cout << std::string(50, '-') << '\n';
	// In the above example, the 2 statements between the case 1 and the default label are scoped as part of the switch block, not a block implicit to case 1.

	//------------------------------------------------------------------------------------------------------------------

	// Variable declaration and initialization inside case statements
	
	// You can declare or define (but not initialize) variables inside the switch, both before and after the case labels:
	{
		switch (1)
		{
			int a;											// okay: definition is allowed before the case labels
			//int b{ 5 };									// illegal: initialization is not allowed before the case labels

		case 1:
			int y;											// okay but bad practice: definition is allowed within a case
			y = 4;											// okay: assignment is allowed
			break;
		case 2:
			//int z{ 4 };									// illegal: initialization is not allowed if subsequent cases exist
			y = 5;											// okay: y was declared above, so we can use it here too
			break;
		case 3:
			break;
		}
	}
	std::cout << std::string(50, '-') << '\n';

	// Although variable y was defined in case 1, it was used in case 2 as well.
	// All statements inside the switch are considered to be part of the same scope.
	// Thus, a variable declared or defined in one case can be used in a later case, 
	// even if the case in which the variable is defined is never executed (because the switch jumped over it)!
	
	// However, initialization of variables does require the definition to execute at runtime (since the value of the initializer must be determined at that point).
	// Initialization of variables is disallowed in any case that is not the last case (because the initializer could be jumped over, 
	// which would leave the variable uninitialized). Initialization is also disallowed before the first case,
	// as those statements will never be executed, as there is no way for the switch to reach them.

	// If a case needs to defineand /or initialize a new variable, the best practice is to do so inside an explicit block underneath the case statement:
	{
		switch (1)
		{
		case 1:
			{	// note the addition of explicit block here
				int x{ 4 };								// okay, variables can be initialized inside a block inside a case
				std::cout << x << '\n';
				break;
			}
		default:
			std::cout << "default case." << '\n';
			break;
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Question #1

	// Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations: +, -, *, /, or % (modulus). 
	// Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result.
	// If an invalid operator is passed into the function, the function should print an error. 
	// For the division operator, do an integer division.

	{
		std::cout << "Enter a integer: ";
		int num1{};
		std::cin >> num1;

		std::cout << "Enter another integer: ";
		int num2{};
		std::cin >> num2;

		std::cout << "Enter the operator: ";
		char op{};
		std::cin >> op;

		std::cout << "The result is: " << calculate(num1, num2, op) << '\n';
	}

	return 0;
}