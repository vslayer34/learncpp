#include <iostream>
#include "constants.h"											// include a copy of each constant in this file
#include "constants2.h"											// include all the forward declarations
#include "constants3.h"

int main()
{
	// In some applications, certain symbolic constants may need to be used throughout your code (not just in one location). 
	// These can include physics or mathematical constants that don’t change (e.g. pi or Avogadro’s number),
	// or application-specific “tuning” values (e.g. friction or gravity coefficients).
	// Instead of redefining these constants in every file that needs them (a violation of the “Don’t Repeat Yourself” rule),
	// it’s better to declare them once in a central location and use them wherever needed.
	// That way, if you ever need to change them, you only need to change them in one place, and those changes can be propagated out.
	// This lesson discusses the most common ways to do this.

	//---------------------------------------------------------------------------------------------------------------------------------------------

	// Global constants as internal variables

	// Prior to C++17, the following is the easiest and most common solution:
	// - Create a header file to hold these constants
	// - Inside this header file, define a namespace (discussed in lesson 6.2 -- User-defined namespaces and the scope resolution operator)
	// - Add all your constants inside the namespace (make sure they’re constexpr)
	// - #include the header file wherever you need it
	// For example:

	{
		std::cout << "Enter a radius: ";
		int radius{};
		std::cin >> radius;

		std::cout << "The circumference is: " << 2.0 * radius * constants::pi << '\n';
	}
	std::cout << std::string(55, '-') << '\n';

	//---------------------------------------------------------------------------------------------------------------------------------------------

	// Global constants as external variables

	// One way to avoid these problems is by turning these constants into external variables, 
	// since we can then have a single variable (initialized once) that is shared across all files. 
	// In this method, we’ll define the constants in a .cpp file (to ensure the definitions only exist in one place), 
	// and put forward declarations in the header (which will be included by other files).

	{
		std::cout << "Enter a radius: ";
		int radius{};
		std::cin >> radius;

		std::cout << "The circumference is: " << 2.0 * radius * constants2::pi << '\n';
	}
	std::cout << std::string(55, '-') << '\n';

	// Now the symbolic constants will get instantiated only once (in constants.cpp) instead of in each code file where constants.h is #included,
	// and all uses of these constants will be linked to the version instantiated in constants.cpp. 
	// Any changes made to constants.cpp will require recompiling only constants.cpp.

	//---------------------------------------------------------------------------------------------------------------------------------------------

	// Global constants as inline variables C++17

	// Inline variables have two primary restrictions that must be obeyed:

	// All definitions of the inline variable must be identical (otherwise, undefined behavior will result).
	// The inline variable definition (not a forward declaration) must be present in any file that uses the variable.

	{
		std::cout << "Enter a radius: ";
		int radius{};
		std::cin >> radius;

		std::cout << "The circumference is: " << 2.0 * radius * constants3::pi << '\n';
	}
	std::cout << std::string(55, '-') << '\n';

	// We can include constants3.h into as many code files as we want, but these variables will only be instantiated once and shared across all code files.


	return 0;
}