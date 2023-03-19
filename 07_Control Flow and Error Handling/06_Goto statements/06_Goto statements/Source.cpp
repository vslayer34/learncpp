#include <iostream>
#include <cmath>					// for sqrt() function

void printCats(bool skip)
{
	if (skip) { goto end; }			// jump forward; statement label 'end' is visible here due to it having function scope
	std::cout << "caaaats." << '\n';

end:
	;								// statement labels must be associated with a statement

}

int main()
{
	// The next kind of control flow statement we’ll cover is the unconditional jump.
	// An unconditional jump causes execution to jump to another spot in the code.
	// The term “unconditional” means the jump always happens (unlike an if statement or switch statement, where the jump only happens conditionally based on the result of an expression).

	// In C++, unconditional jumps are implemented via a goto statement, and the spot to jump to is identified through use of a statement label.
	// The following is an example of a goto statement and statement label:

	{
		double x{};
	tryAgain:								// this is a statement label
		std::cout << "Enter a non-negative number: ";
		std::cin >> x;

		if (x < 0.0) { goto tryAgain; }		// this is a goto statement

		std::cout << "The square root of " << x << " is " << std::sqrt(x) << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	// In this program, the user is asked to enter a non-negative number.
	// However, if a negative number is entered, the program utilizes a goto statement to jump back to the tryAgain label. 
	// The user is then asked again to enter a new number.
	// In this way, we can continually ask the user for input until he or she enters something valid.

	//----------------------------------------------------------------------------------------------------------------------------

	// Statement labels have function scope
	// Statement labels utilize a third kind of scope: function scope,
	// which means the label is visible throughout the function even before its point of declaration. 
	// The goto statement and its corresponding statement label must appear in the same function.

	// While the above example shows a goto statement that jumps backwards (to a preceding point in the function), goto statements can also jump forward:
	{
		printCats(true);
		printCats(false);
	}
	std::cout << std::string(50, '-') << '\n';

	// There are two primary limitations to jumping: 
	// You can jump only within the bounds of a single function (you can’t jump out of one function and into another),
	// and if you jump forward, you can’t jump forward over the initialization of any variable that is still in scope at the location being jumped to.
	// For example:
	/*******************************
	{
		goto skip;							// error: this jump is illegal because...
		int x{ 5 };							// this initialized variable is still in scope at statement label 'skip'
	skip:
		x += 3;								// what would this even evaluate to if x wasn't initialized?
	}
	******************************/

	//----------------------------------------------------------------------------------------------------------------------------


	return 0;
}