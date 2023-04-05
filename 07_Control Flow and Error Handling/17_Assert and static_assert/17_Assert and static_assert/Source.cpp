#include <cassert>					// for assert()
#include <cmath>					// for std::sqrt
#include <iostream>

// Preconditions, invariants, and postconditions

// In programming, a precondition is any condition that must always be true prior to the execution of component of code.
// Our check of y is a precondition that ensures y has a valid value before the function continues.
// It’s more common for functions with preconditions to be written like this:
void printDivision(int x, int y)
{
	if (y == 0)
	{
		std::cerr << "Error: Could not divide by zero!" << '\n';
		return;
	}

	std::cout << static_cast<double>(x) / y;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

// Assertions
// In C++, runtime assertions are implemented via the assert preprocessor macro, which lives in the <cassert> header.
double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
	assert(gravity > 0.0 && "Gravity can't be a negative number");						// Object won't reach the ground unless there is a positive gravity

	if (initialHeight <= 0.0)
	{
		// The object is either buried or on the ground
		return 0.0;
	}

	return std::sqrt((2.0 * initialHeight) / gravity);
}

int main()
{
	std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " seconds." << '\n';

	//---------------------------------------------------------------------------------------------------------------------------------------------------

	// NDEBUG
	// The assert macro comes with a small performance cost that is incurred each time the assert condition is checked.
	// Furthermore, asserts should (ideally) never be encountered in production code (because your code should already be thoroughly tested). 
	// Consequently, many developers prefer that asserts are only active in debug builds. 
	// C++ comes with a way to turn off asserts in production code. If the macro NDEBUG is defined, the assert macro gets disabled.
	
	// Some IDEs set NDEBUG by default as part of the project settings for release configurations. 
	// For example, in Visual Studio, the following preprocessor definitions are set at the project level: WIN32;NDEBUG;_CONSOLE. 
	// If you’re using Visual Studio and want your asserts to trigger in release builds, you’ll need to remove NDEBUG from this setting.

	return 0;
}