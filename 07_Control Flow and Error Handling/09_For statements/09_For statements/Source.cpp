#include <iostream>

// Here’s an example of a function that uses a for loop to calculate integer exponents :
int pow(int base, int exponent)
{
	int total{ 1 };	

	for (int count{ 0 }; count < exponent; count++)
	{
		total *= base;
	}

	return total;
}


int sumTo(int value)
{
	int sum{ 0 };

	for (int num{ 1 }; num <= value; num++)
	{
		sum += num;
	}

	return sum;
}

int main()
{
	// Let’s take a look at a sample for loop and discuss how it works:
	{
		for (int count{ 1 }; count <= 10; count++)
		{
			std::cout << count << ' ';
		}
		std::cout << "done!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// For the sake of example, let’s convert the above for loop into an equivalent while loop:
	{
		int count{ 1 };
		while (count <= 10)
		{
			std::cout << count << ' ';
			count++;
		}
		std::cout << "done!!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------

	// More for loop examples

	// Although most for loops increment the loop variable by 1, we can decrement it as well:
	{
		for (int count{ 10 }; count >= 0; count--)
		{
			std::cout << count << ' ';
		}

		std::cout << "done!!!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// Alternately, we can change the value of our loop variable by more than 1 with each iteration:

	{
		for (int count{ 0 }; count <= 10; count += 2)
		{
			std::cout << count << ' ';
		}

		std::cout << "done!!!!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------

	// The perils of operator!= in for-loop conditions
	// When writing a loop condition involving a value, we can often write the condition in many different ways. The following two loops execute identically:
	{
		for (int i{ 0 }; i < 10; i++)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
		
		for (int i{ 0 }; i != 10; i++)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// So which should we prefer? The former is the better choice, as it will terminate even if i jumps over the value 10

	//-----------------------------------------------------------------------------------------------------

	// Off-by-one errors
	// One of the biggest problems that new programmers have with for loops (and other loops that utilize counters) are off-by-one errors.
	// Off-by-one errors occur when the loop iterates one too many or one too few times to produce the desired result.
	{
		// oops, we used operator (<) instead of operator (<=)
		for (int count{ 1 }; count < 5; count++)
		{
			std::cout << count << ' ';
		}
		std::cout << "done!!!!!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// This program is supposed to print 1 2 3 4 5, but it only prints 1 2 3 4 because we used the wrong relational operator.
	// Although the most common cause for these errors is using the wrong relational operator, 
	// they can sometimes occur by using pre-increment or pre-decrement instead of post-increment or post-decrement, or vice-versa.

	//-----------------------------------------------------------------------------------------------------

	// Omitted expressions
	// It is possible to write for loops that omit any or all of the statements or expressions. 
	// For example, in the following example, we’ll omit the init-statement and end-expression, leaving only the condition:
	{
		int count{ 0 };
		for (; count < 10;)				// no init-statement or end-expression
		{
			std::cout << count << ' ';
			count++;
		}
		std::cout << "done!!!!!!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------

	// For loops with multiple counters
	// Although for loops typically iterate over only one variable, sometimes for loops need to work with multiple variables. 
	// To assist with this, the programmer can define multiple variables in the init-statement, 
	// and can make use of the comma operator to change the value of multiple variables in the end-expression:
	{
		for (int x{ 0 }, y{ 9 }; x < 10; x++, y--)
		{
			std::cout << '(' << x << ", " << y << ')' << '\n';
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------

	// Nested for loops
	// Like other types of loops, for loops can be nested inside other loops.
	// In the following example, we’re nesting a for loop inside another for loop:
	{
		for (char c{ 'a' }; c <= 'e'; c++)			// outer loop on letters
		{
			std::cout << c;							// print our letter first

			for (int i{ 0 }; i < 3; i++)			// inner loop on numbers
			{
				std::cout << i;
			}

			std::cout << '\n';
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------

	// Question #1

	// Write a for loop that prints every even number from 0 to 20.

	{
		int limit{ 20 };
		for (int i{ 0 }; i <= limit - 1; i++)
		{
			std::cout << i << " -> ";
		}
		std::cout << limit << '.' << '\n';
		std::cout << "0 -> 20 finished" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------

	// Question #2
	// Write a function named sumTo() that takes an integer parameter named value, and returns the sum of all the numbers from 1 to value.
	// For example, sumTo(5) should return 15, which is 1 + 2 + 3 + 4 + 5.
	{
		std::cout << "Enter a positive integer: ";
		int num{};
		std::cin >> num;

		std::cout << "The sum of all numbers: " << sumTo(num) << '\n';
	}
	std::cout << std::string(50, '-') << '\n';


	return 0;
}