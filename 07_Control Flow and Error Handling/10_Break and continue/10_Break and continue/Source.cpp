#include <iostream>

// Breaking a switch
// In the context of a switch statement, a break is typically used at the end of each case to signify the case is finished (which prevents fallthrough into subsequent cases):
void printMath(int x, int y, char op)
{
	switch (op)
	{
	case '+':
		std::cout << x << " + " << y << " = " << x + y << '\n';
		break;
	case '-':
		std::cout << x << " - " << y << " = " << x - y << '\n';
		break;
	case '*':
		std::cout << x << " * " << y << " = " << x * y << '\n';
		break;
	case '/':
		std::cout << x << " / " << y << " = " << x / y << '\n';
		break;
	}
}

int breakOrReturn()
{
	while (true)		// infinte loop
	{
		std::cout << "Enter 'b' to break or 'r' to return.." << '\n';
		char ch{};
		std::cin >> ch;

		// execution will continue at the first statement beyond the loop
		if (ch == 'b') { break; }

		// return will cause the function to return immediately to the caller ins this case main()
		if (ch == 'r') { return 1; }
	}

	// breaking from the loop cause this line to execute
	std::cout << "We broke out of the loop" << '\n';

	return 0;
}

int main()
{
	// Breaking a switch
	{
		printMath(2, 3, '+');
	}
	std::cout << std::string(50, '-') << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------------------

	// Breaking a loop
	// In the context of a loop, a break statement can be used to end the loop early. Execution continues with the next statement after the end of the loop.
	// For example:
	{
		int sum{ 0 };

		// allow the user to enter up to 10 numbers
		for (int count{ 0 }; count <= 10; count++)
		{
			std::cout << "Enter a number to add or 0 to exit: ";
			int num{};
			std::cin >> num;

			// exit the loop if the user enter 0
			if (num == 0) { break; }

			// otherwise add the number to the sum
			sum += num;
		}

		// execution will continue here after the break
		std::cout << "The sum of the number you entered are: " << sum << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------------------

	// Break vs return
	// A break statement terminates the switch or loop, and execution continues at the first statement beyond the switch or loop.
	// A return statement terminates the entire function that the loop is within, and execution continues at point where the function was called.
	{
		int returnValue{ breakOrReturn() };
		std::cout << "Function breakOrReturn() returned: " << returnValue << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------------------

	// Continue
	// The continue statement provides a convenient way to end the current iteration of a loop without terminating the entire loop.
	// Here’s an example of using continue:
	{
		for (int count{ 0 }; count <= 10; count++)
		{
			// if the number is divisible by 4, skip this iteration
			if (count % 4 == 0) { continue; }

			// if the number is not divisible by 4 keep goind
			std::cout << count << '\n';

			// the continue statement jumps here
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//--------------------------------------------------------------------------------------------------------------------------------------------------

	return 0;
}