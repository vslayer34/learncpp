#include <iostream>

int add(int x, int y)
{																// start block
	return x + y;
}																// end block (no semicolon)

int main()
{																// start outer block
	// A compound statement (also called a block, or block statement) is a group of zero or more statements that is treated by the compiler as if it were a single statement.

	// You have already seen an example of blocks when writing functions, as the function body is a block:
	
	// multiple statements
	int value{};												// this is initialization, not a block
	add(3, 4);

	//---------------------------------------------------------------------------------------------------------------------------------

	// Blocks inside other blocks
	// Although functions can’t be nested inside other functions, blocks can be nested inside other blocks:

	{															// inner/nested block
		add(4, 6);
	}															// end inner/nested block

	// When blocks are nested, the enclosing block is typically called the outer block and the enclosed block is called the inner block or nested block.

	//---------------------------------------------------------------------------------------------------------------------------------

	// Using blocks to execute multiple statements conditionally
	// One of the most common use cases for blocks is in conjunction with if statements. 
	// By default, an if statement executes a single statement if the condition evaluates to true.
	// However, we can replace this single statement with a block of statements if we want multiple statements to execute when the condition evaluates to true.

	std::cout << "Enter an integer: ";
	int value1{};
	std::cin >> value1;

	if (value1 >= 0)
	{														// start of nested block
		std::cout << value1 << " is a positive integer (or zero).\n";
		std::cout << "Double this number is " << value1 * 2 << '\n';
	}														// end of nested block
	else
	{														// start of another nested block
		std::cout << value1 << " is a negative integer.\n";
		std::cout << "The positive of this number is " << -value1 << '\n';
	}														// end of another nested block
	std::cout << '\n';

	//---------------------------------------------------------------------------------------------------------------------------------

	// Block nesting levels
	// It is even possible to put blocks inside of blocks inside of blocks:
	{														// block 1, nesting level 1
		std::cout << "Enter an integer: ";
		int value2{};
		std::cin >> value2;
		
		if (value2 > 0)
		{													// block 2, nesting level 2
			if (value2 % 2 == 0)
			{												// block 3, nesting level 3
				std::cout << "Value is positive and even.\n";
			}
			else											// block 4, also nesting level 3
			{
				std::cout << value2 << " is positive and off.\n";
			}
		}
	}
	std::cout << '\n';

	// Keep the nesting level of your functions to 3 or less.
	// If your function has a need for more nested levels, consider refactoring your function into sub-functions.

	return 0;
}																// end outer block (no semicolon)