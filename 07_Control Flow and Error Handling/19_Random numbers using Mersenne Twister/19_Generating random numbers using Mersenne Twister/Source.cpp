#include <iostream>
#include <random>				// for std::mt19937 and std::uniform_int_distribution
#include <chrono>				// for std::chrono

int main()
{
	// Generating random numbers in C++ using Mersenne Twister
	// The random library has support for two Mersenne Twister types:
	// mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
	// mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers

	// Using Mersenne Twister is straightforward:
	{
		std::mt19937 mt{};										// Instantiate a 32-bit Mersenne Twister

		// Print a bunch of random numbers
		for (int i{ 1 }; i <= 40; i++)
		{
			std::cout << mt() << '\t';						// generate a random number

			// If we've printed 5 numbers, start a new row
			if (i % 5 == 0)
				std::cout << '\n';
		}
		std::cout << std::string(100, '-') << '\n';
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	// Rolling a dice using Mersenne Twister
	// The random library has many random numbers distributions, most of which you will never use unless you’re doing some kind of statistical analysis. 
	// But there’s one random number distribution that’s extremely useful: 
	// a uniform distribution is a random number distribution that produces outputs between two numbers X and Y (inclusive) with equal probability.

	// Here’s a similar program to the one above, using a uniform distribution to simulate the roll of a 6-sided dice:
	{
		std::mt19937 mt{};

		// Create a reusable random number generator that generates uniform numbers between 1 and 6
		std::uniform_int_distribution die6{ 1, 6 };

		// Print a bunch of random numbers
		for (int i{ 1 }; i <= 40; i++)
		{
			std::cout << die6(mt) << '\t';				// generate a roll of the die here

			// If we've printed 10 numbers, start a new row
			if (i % 10 == 0)
				std::cout << '\n';
		}
	}
	std::cout << std::string(100, '-') << '\n';

	// If you run the program multiple times, you will note that it prints the same numbers every time!
	// While each number in the sequence is random with regards to the previous one, the entire sequence is not random at all! 
	// Each run of our program produces the exact same result.
	// because the program starts with the same seed each time
	// The solution is to change the seed each time the program starts

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	// Seeding with the system clock

	// Fortunately, C++ has a high resolution clock that we can use to generate a seed value. 
	// To minimize the chance of two time values being identical if the program is run quickly in succession, we want to use some time measure that changes as quickly as possible. 
	// For this, we’ll ask the clock how much time has passed since the earliest time it can measure. 
	// This time is measured in “ticks”, which is a very small unit of time (usually nanoseconds, but could be milliseconds).

	{
		// Seed our Mersenne Twister using the chrono library to get the time
		std::mt19937 mt{ static_cast<unsigned int>(
			std::chrono::steady_clock::now().time_since_epoch().count()
			) };

		// Create a reusable random number generator that generates uniform numbers between 1 and 6
		std::uniform_int_distribution die6{ 1, 6 };

		// Print a bunch of random numbers
		for (int i{ 1 }; i <= 40; i++)
		{
			std::cout << die6(mt) << '\t';		// generate a roll of the die here

			// If we've printed 10 numbers, start a new row
			if (i % 10 == 0)
				std::cout << '\n';
		}
	}
	std::cout << std::string(100, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	// Seeding with the random device

	// The random library contains a type called std::random_device that is an implementation-defined PRNG.
	// Normally we avoid implementation-defined capabilities because they have no guarantees about quality or portability, 
	// but this is one of the exception cases. Typically std::random_device will ask the OS for a random number (how it does this depends on the OS).

	{
		std::mt19937 mt{ std::random_device{}() };

		// Create a reusable random number generator that generates uniform numbers between 1 and 6
		std::uniform_int_distribution die6{ 1, 6 };

		// Print a bunch of random numbers

		for (int i{ 1 }; i <= 40; i++)
		{
			std::cout << die6(mt) << '\t';			// generate a roll of the die here

			// If we've printed 10 numbers, start a new row
			if (i % 10 == 0)
				std::cout << '\n';
		}
	}
	std::cout << std::string(100, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------------------------

	// Mersenne Twister and underseeding issues

	// The more pieces of random data we can give std::seed_seq to work with, the better.
	// So the easiest idea is to simply use std::random_device to give std::seed_seq more data to work with.
	// If we initialize std::seed_seq with 8 numbers from std::random_device instead of 1, then the remaining numbers generated by std::seed_seq should be that much better:
	{
		std::random_device rd;
		// get 8 integers of random numbers from std::random_device for our seed
		std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		std::mt19937 mt { ss };				// initialize our Mersenne Twister with the std::seed_seq

		// Create a reusable random number generator that generates uniform numbers between 1 and 6
		std::uniform_int_distribution die6{ 1, 6 };

		for (int i{ 1 }; i <= 40; i++)
		{
			std::cout << die6(mt) << '\t';			// generate a roll of the die here

			// If we've printed 10 numbers, start a new row
			if (i % 10 == 0)
				std::cout << '\n';
		}
	}
	std::cout << std::string(100, '-') << '\n';

	//-----------------------------------------------------------------------------------------------------------------------------------------------




	
	return 0;
}