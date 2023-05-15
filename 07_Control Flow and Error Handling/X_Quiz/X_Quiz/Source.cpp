#include <iostream>
#include <cassert>
#include <random>
#include "constants.h"


// Question 1 functions

double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen{ myConstants::gravity * seconds * seconds / 2 };
	double heightNow{ initialHeight - distanceFallen };

	// Check whether the ball has fone under the ground
	// If so, set the height to ground level
	if (heightNow < 0.0)
		return 0.0;
	else
		return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time, double& height)
{
	height = calculateHeight(initialHeight, time);
	std::cout << "At " << time << " seconds, the ball is at height: " << height << '\n';
}

//*********************************************************************************************************************

// Question 2 functions

bool isPrime(int x)
{
	if (x <= 1)
		return false;

	// write this function using a for loop
	for (int number{ 2 }; number < x; number++)
	{
		if (x % number == 0)
			return false;
	}

	return true;
}

//*********************************************************************************************************************

// Question 3 functions

bool playGame(int numGuesses, int number)
{
	for (int i{ 0 }; i < numGuesses; i++)
	{
		std::cout << "Guess #" << i << ": ";

		int guess{};
		std::cin >> guess;

		if (guess < number)
			std::cout << "Your guess is too low." << '\n';

		else if (guess > number)
			std::cout << "Your guess is too high." << '\n';

		else
			return true;
	}

	return false;
}

//*********************************************************************************************************************

int main()
{
	// Question #1
	{
		std::cout << "Question #1" << '\n';

		std::cout << "Enter the initial height of the tower in meters: ";
		double initialHeight{};
		std::cin >> initialHeight;

		std::cout << '\n';
		int time{ 0 };

		bool keepFalling{ true };

		while (keepFalling)
		{
			double height{};
			calculateAndPrintHeight(initialHeight, time, height);
			time++;

			if (height == 0.0)
				keepFalling = false;
		}
	}
	std::cout << std::string(100, '-') << '\n';



	// Question #2
	{
		std::cout << "Question #2" << '\n';

		assert(!isPrime(0));
		assert(!isPrime(1));
		assert(isPrime(2));
		assert(isPrime(3));
		assert(!isPrime(4));
		assert(isPrime(5));
		assert(isPrime(7));
		assert(!isPrime(9));
		assert(isPrime(11));
		assert(isPrime(13));
		assert(!isPrime(15));
		assert(!isPrime(16));
		assert(isPrime(17));
		assert(isPrime(19));
		assert(isPrime(97));
		assert(!isPrime(99));
		assert(isPrime(13417));

		std::cout << "Success" << '\n';
	}
	std::cout << std::string(100, '-') << '\n';



	// Question #3
	{
		std::random_device rd;
		std::seed_seq seq{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		std::mt19937 mt{ seq };							// Create a mersenne twister, seeded using the seed sequence
		std::uniform_int_distribution die{ 1, 100 };	// generate random numbers between 1 and 100

		int numOfGuesses{ 7 };

		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is." << '\n';
		char userInput{};
		
		while (userInput != 'n')
		{
			int number{ die(mt) };				// the number the user needs to guess

			bool isRight{ playGame(numOfGuesses, number) };
			if (isRight)
				std::cout << "Correct! You WON!!" << '\n';
			else
				std::cout << "Sorry, You Lose. The correct number is " << number << '.' << '\n';


		}

	}
	
	return 0;
}