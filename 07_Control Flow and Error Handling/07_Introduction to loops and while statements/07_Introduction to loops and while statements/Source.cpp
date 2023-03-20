#include <iostream>

int main()
{
	// let’s say you wanted to print all the numbers between 1 and 10. Without loops, you might try something like this:
	{
		std::cout << "1 2 3 4 5 6 7 8 9 10" << '\n';
		std::cout << "done!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// While statements

	// Let’s take a look at a simple while loop that prints all the numbers from 1 to 10:
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

	//------------------------------------------------------------------------------------------------------------------

	// While statements that evaluate to false initially

	// Note that if the condition initially evaluates to false, the associated statement will not execute at all. Consider the following program:
	{
		int count{ 15 };

		while (count <= 10)
		{
			std::cout << count << ' ';
			count++;
		}

		std::cout << "done!!!" << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Intentional infinite loops
	// Here’s a silly example demonstrating this:
	{
		while (true)							// infinite loop
		{
			std::cout << "loop again?" << '\n';
			char c{};
			std::cin >> c;

			if (c == 'n' || c == 'N') { break; }
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Doing something every N iterations

	// Each time a loop executes, it is called an iteration.
	// Often, we want to do something every 2nd, 3rd, or 4th iteration, such as print a newline. 
	// This can easily be done by using the modulus operator on our counter:
	
	{
		// Iterate through every number between 1 and 50
		int count{ 1 };
		while (count <= 50)
		{
			// print the number (pad numbers under 10 with a leading 0 for formatting purposes)
			if (count < 10) { std::cout << '0'; }

			std::cout << count << ' ';
			
			// if the loop variable is divisible by 10, print a newline
			if (count % 10 == 0) { std::cout << '\n'; }

			// increment the loop counter
			count++;
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Nested loops

	// It is also possible to nest loops inside of other loops. In the following example, 
	// the nested loop (which we’re calling the inner loop) and the outer loop each have their own counters.
	// Note that the loop expression for the inner loop makes use of the outer loop’s counter as well!

	{
		// outer loop between 1 and 5
		int outer{ 1 };
		while (outer <= 5)
		{
			// For each iteration of the outer loop, the code in the body of the loop executes once

			// inner loops between 1 and outer
			int inner{ 1 };
			while (inner <= outer)
			{
				std::cout << inner << ' ';
				inner++;
			}

			// print a newline at the end of each row
			std::cout << '\n';
			outer++;
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Question #2
	// Write a program that prints out the letters a through z along with their ASCII codes.
	// Hint: To print characters as integers, you have to use a static_cast.
	{
		char startLetter = 'a';
		char endLetter = 'z';
		while (startLetter <= endLetter)
		{
			std::cout << "letter: " << startLetter << "\t\t ASCII code: " << static_cast<int>(startLetter) << '\n';
			startLetter++;
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Question #3
	// Invert the nested loops example so it prints the following:
	// 5 4 3 2 1
	// 4 3 2 1
	// 3 2 1
	// 2 1
	// 1

	{
		int startCount{ 5 };

		while (startCount >= 1)
		{
			int inner = startCount;
			while (inner >= 1)
			{
				std::cout << inner << ' ';
				inner--;
			}
			std::cout << '\n';
			startCount--;
		}
	}
	std::cout << std::string(50, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------

	// Question #4
	// Now make the numbers print like this:
	//         1
	//	     2 1
	//     3 2 1
	//   4 3 2 1
	// 5 4 3 2 1

	{
		int startCount{ 1 };
		
		while (startCount <= 5)
		{
			int innerCount{ startCount };
			int spaceCount{ 5 - startCount };

			while (spaceCount >= 1)
			{
				// print space instead of the number and the space between the two characters
				std::cout << ' ' << ' ';
				spaceCount--;
			}

			while (innerCount >= 1)
			{
				std::cout << innerCount << ' ';
				innerCount--;
			}
			
			std::cout << '\n';
			startCount++;
		}
	}

	return 0;
}