#include <iostream>
#include <cmath>																// for std::abs()
#include <algorithm>															// std::max


// New developers often try to write their own “close enough” function like this:
// epsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double relEpsilon = 1e-8)
{
	// if the distance between a and b is less than absEpsilon, then a and b are "close enough"
	return std::abs(a - b) <= (std::max(std::abs(a), std::abs(b))) * relEpsilon;
	// In this case, instead of epsilon being an absolute number, epsilon is now relative to the magnitude of a or b.
	// On the right side of the <= operator, we need to calculate the largest value of “close enough” we’re willing to accept.
	// To do this, the algorithm chooses the larger of a and b (as a rough indicator of the overall magnitude of the numbers), 
	// and then multiplies it by relEpsilon. In this function, relEpsilon represents a percentage. 
	// For example, if we want to say “close enough” means a and b are within 1% of the larger of a and b,
	// we pass in an relEpsilon of 0.01 (1% = 1/100 = 0.01). 
	// The value for relEpsilon can be adjusted to whatever is most appropriate for the circumstances (e.g. an epsilon of 0.002 means within 0.2%).
}

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
	// Check if the numbers are really close -- needed when comparing numbers near zero.
	double diff{ std::abs(a - b) };
	if (diff <= absEpsilon)
		return true;

	// Otherwise fall back to Knuth's algorithm
	return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// To do inequality (!=) instead of equality, simply call this function and use the logical NOT operator (!) to flip the result:


int main()
{
	// Relational operators
	// Here’s some sample code using these operators with integers:
	std::cout << "Enter an integer: ";
	int x1{};
	std::cin >> x1;

	std::cout << "Enter another integer: ";
	int y1;
	std::cin >> y1;


	if (x1 == y1)
		std::cout << x1 << " equals " << y1 << '\n';
	if (x1 != y1)
		std::cout << x1 << " does not equal " << y1 << '\n';
	if (x1 > y1)
		std::cout << x1 << " is greater than " << y1 << '\n';
	if (x1 < y1)
		std::cout << x1 << " is less than " << y1 << '\n';
	if (x1 >= y1)
		std::cout << x1 << " is greater than or equal to " << y1 << '\n';
	if (x1 <= y1)
		std::cout << x1 << " is less than or equal to " << y1 << '\n';
	std::cout << '\n';

	//--------------------------------------------------------------------------------------------------------------

	// Comparison of calculated floating point values can be problematic
	// Consider the following program:

	double d1{ 100.0 - 99.99 };													// should equal 0.01 mathematically
	double d2{ 10.0 - 9.99 };													// should equal 0.01 mathematically

	if (d1 == d2)
		std::cout << "d1 == d2" << '\n';
	else if (d1 > d2)
		std::cout << "d1 > d2" << '\n';
	else if (d1 < d2)
		std::cout << "d1 < d2" << '\n';
	std::cout << '\n';

	// Variables d1 and d2 should both have value 0.01. But this program prints an unexpected result:
	// d1 > d2
	// If you inspect the value of d1 and d2 in a debugger, you’d likely see that d1 = 0.0100000000000005116 and d2 = 0.0099999999999997868.
	// Both numbers are close to 0.01, but d1 is greater than, and d2 is less than.
	// If a high level of precision is required, comparing floating point values using any of the relational operators can be dangerous.
	// This is because floating point values are not precise, and small rounding errors in the floating point operands may cause unexpected results.
	// We discussed rounding errors in lesson 4.8 --Floating point numbers if you need a refresher.

	//--------------------------------------------------------------------------------------------------------------

	// Floating point equality
	// The equality operators (== and !=) are much more troublesome.
	// Consider operator==, which returns true only if its operands are exactly equal.
	// Because even the smallest rounding error will cause two floating point numbers to not be equal,
	// operator== is at high risk for returning false when a true might be expected. Operator!= has the same kind of problem.
	// For this reason, use of these operators with floating point operands should generally be avoided.
	// It is okay to compare a low-precision (few significant digits) floating point literal to the same literal value of the same type.

	//--------------------------------------------------------------------------------------------------------------

	// Comparing floating point numbers
	// The most common method of doing floating point equality involves using a function that looks to see if two numbers are almost the same.
	// If they are “close enough”, then we call them equal. The value used to represent “close enough” is traditionally called epsilon.
	// Epsilon is generally defined as a small positive number (e.g. 0.00000001, sometimes written 1e-8).

	// Note that while the approximatelyEqualRel() function will work for most cases, it is not perfect, especially as the numbers approach zero:
	
	// a is really close to 1.0, but has rounding errors, so it's slightly smaller than 1.0
	double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

	// First, let's compare a (almost 1.0) to 1.0.
	std::cout << approximatelyEqualAbs(a, 1.0, 1e-8) << '\n';					// compare "almost 1.0" to 1.0

	// Second, let's compare a-1.0 (almost 0.0) to 0.0
	std::cout << approximatelyEqualAbs(a, 0.0, 1e-8) << '\n';					// compare "almost 0.0" to 0.0
	std::cout << '\n';
	// The second call didn’t perform as expected. The math simply breaks down close to zero.
	// One way to avoid this is to use both an absolute epsilon (as we did in the first approach) and a relative epsilon (as we did in Knuth’s approach):

	std::cout << approximatelyEqualAbsRel(a, 1.0, 1e-12, 1e-8) << '\n';			// compare "almost 1.0" to 1.0
	std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, 1e-12, 1e-8) << '\n';	// compare "almost 0.0" to 0.0
	
	
	return 0;
}