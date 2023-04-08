#include <iostream>

int plusOne()
{
	static int s_state{ 3 };				// only initialized the first time the function is called

	// Generate the next number
	s_state++;								// first the state is modified
	return s_state;							// then the new state is used to generate an number in the sequence
}

// simple number generator
unsigned int LCG16()
{
	static unsigned int s_state{ 5323 };

	// Generate the next number

	// We modify the state using large constants and intentional overflow to make it hard
	// for someone to casually determine what the next number in the sequence will be.

	s_state = 8253729 * s_state + 2396403;		// the state is modified
	return s_state % 32768;						// then it's used to generate the next number in the sequence
}

int main()
{
	// Algorithms and state
	// Here’s a simple algorithm for generating a sequence of numbers where each successive number is incremented by 1:
	{
		std::cout << plusOne() << '\n';
		std::cout << plusOne() << '\n';
		std::cout << plusOne() << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	// Pseudo-random number generators (PRNGs)

	{
		// print 100 random numbers

		for (int count{ 1 }; count <= 100; count++)
		{
			std::cout << LCG16() << '\t';

			// when 10 numbers are printed we jumb a new line
			if (count % 10 == 0) { std::cout << '\n'; }
		}
	}
	std::cout << std::string(50, '-') << '\n';

	
	return 0;
}