#include <iostream>

// Handling the error within the function

// An alternate strategy is just to ignore the error and/or cancel the operation. For example:
void printDivision(int x, int y)
{
	if (y != 0)
		std::cout << static_cast<double>(x) / y;
}
// In the above example, if the user passed in an invalid value for y, we just ignore the request to print the result of the division operation.
// The primary challenge with doing this is that the caller or user have no way to identify that something went wrong.In such case, printing an error message can be helpful :
void printDivisionV2(int x, int y)
{
	if (y != 0)
		std::cout << static_cast<double>(x) / y;
	else
		std::cout << "Error: Could not divide by zero." << '\n';
}
// However, if the calling function is expecting the called function to produce a return value or some useful side-effect, then just ignoring the error may not be an option.

//---------------------------------------------------------------------------------------------------------------------------------------------------

// Passing errors back to the caller

// In many cases, the error can’t reasonably be handled in the function that detects the error. For example, consider the following function:
double doDivision(int x, int y)
{
	return static_cast<double>(x) / y;
}
// In such cases, the best option can be to pass the error back to the caller in hopes that the caller will be able to deal with it.
// How might we do that?
// If the function has a void return type, it can be changed to return a Boolean that indicates success or failure. For example, instead of:

bool printDivisionV3(int x, int y)
{
	if (y == 0)
	{
		std::cerr << "Error: could not divide by zero" << '\n';
		return false;
	}

	std::cout << static_cast<double>(x) / y;
	return true;
}
// That way, the caller can check the return value to see if the function failed for some reason.

// If the function returns a normal value, things are a little more complicated. In some cases, the full range of return values isn’t used.
// In such cases, we can use a return value that wouldn’t otherwise be possible to occur normally to indicate an error. For example, consider the following function:

// The reciprocal of x is 1/x
double reciprocal(double x)
{
	return 1.0 / x;
}
// The reciprocal of some number x is defined as 1/x, and a number multiplied by its reciprocal equals 1.

// However, what happens if the user calls this function as reciprocal(0.0)? We get a divide by zero error and a program crash, 
// so clearly we should protect against this case. But this function must return a double value, so what value should we return?
// It turns out that this function will never produce 0.0 as a legitimate result, so we can return 0.0 to indicate an error case.
double reciprocalV2(double x)
{
	if (x == 0.0) { return 0.0; }

	return 1.0 / x;
}
// However, if the full range of return values are needed,
// then using the return value to indicate an error will not be possible (because the caller would not be able to tell whether the return value is a valid value or an error value). 
// In such a case, an out parameter might be a viable choice.

//---------------------------------------------------------------------------------------------------------------------------------------------------

// Fatal errors

// If the error is so bad that the program can not continue to operate properly, this is called a non-recoverable error (also called a fatal error). 
// In such cases, the best thing to do is terminate the program. If your code is in main() or a function called directly from main(), 
// the best thing to do is let main() return a non-zero status code.
// However, if you’re deep in some nested subfunction, it may not be convenient or possible to propagate the error all the way back to main().
// In such a case, a halt statement (such as std::exit()) can be used.
double doDivisonV2(int x, int y)
{
	if (y == 0)
	{
		std::cerr << "Error: Could not divide by ZERO." << '\n';
		std::exit(1);
	}
	
	return static_cast<double>(x) / y;
}

int main()
{
	// Handling the error within the function

	// If the error has occurred due to something outside of the program’s control, the program can retry until success is achieved. 
	// For example, if the program requires an internet connection, and the user has lost their connection, 
	// the program may be able to display a warning and then use a loop to periodically recheck for internet connectivity. 
	// Alternatively, if the user has entered invalid input, the program can ask the user to try again, and loop until the user is successful at entering valid input.
	
	
	return 0;
}