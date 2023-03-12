#include <iostream>


// Global variables with external linkage
// Global variables with external linkage are sometimes called external variables. 
// To make a global variable external (and thus accessible by other files), we can use the extern keyword to do so:
int g_x{ 2 };													// non-constant globals are external by default.

extern const int g_y{ 3 };										// const globals can be defined as extern, making them external
extern constexpr int g_z{ 4 };									// constexpr globals can be defined as extern, making them external

// Non-const global variables are external by default (if used, the extern keyword will be ignored).

//-------------------------------------------------------------------------------------------------------------------------------------------------------

extern int g_x1;												// this extern is a forward declaration of a variable named g_x1 that is defined somewhere else
extern const int g_y1;											// this extern is a forward declaration of a const variable named g_y1 that is defined somewhere else

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void sayHi();													// forward declaration of function sayHi(), making sayHi() accessible in this file.

int main()
{
	// An identifier with external linkage can be seen and used both from the file in which it is defined, and from other code files (via a forward declaration).
	// In this sense, identifiers with external linkage are truly “global” in that they can be used anywhere in your program!

	//-------------------------------------------------------------------------------------------------------------------------------------------------------

	// Functions have external linkage by default
	// In order to call a function defined in another file, you must place a forward declaration for the function in any other files wishing to use the function.
	// The forward declaration tells the compiler about the existence of the function, and the linker connects the function calls to the actual function definition.

	{
		sayHi();												// call to function defined in another file, linker will connect this call to the function definition.
	}
	std::cout << std::string(75, '-') << '\n';

	// In the above example, the forward declaration of function sayHi() in main.cpp allows main.cpp to access the sayHi() function defined in a.cpp. 
	// The forward declaration satisfies the compiler, and the linker is able to link the function call to the function definition.

	// If function sayHi() had internal linkage instead, the linker would not be able to connect the function call to the function definition, and a linker error would result.

	//-------------------------------------------------------------------------------------------------------------------------------------------------------

	// Variable forward declarations via the extern keyword
	// To actually use an external global variable that has been defined in another file,
	// you also must place a forward declaration for the global variable in any other files wishing to use the variable. 
	// For variables, creating a forward declaration is also done via the extern keyword (with no initialization value).

	{
		std::cout << g_x1 << '\n';
	}
	std::cout << std::string(75, '-') << '\n';

	
	return 0;
}