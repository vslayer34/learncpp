#include <iostream>

static int g_x1{};														// non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

const int g_y1{ 1 };													// const globals have internal linkage by default
constexpr int g_z1{ 2 };												// constexpr globals have internal linkage by default

int add(int x, int y);													// forward decleration of function add()

int main()
{
	// An identifier with internal linkage can be seen and used within a single file, but it is not accessible from other files (that is, it is not exposed to the linker).
	// This means that if two files have identically named identifiers with internal linkage, those identifiers will be treated as independent.

	//------------------------------------------------------------------------------------------------------------------------------------------------------
	// Global variables with internal linkage
	// Global variables with internal linkage are sometimes called internal variables.
	// To make a non-constant global variable internal, we use the static keyword.

	{
		std::cout << g_x1 << ' ' << g_y1 << ' ' << g_z1 << '\n';
	}
	std::cout << std::string(75, '-') << '\n';

	//------------------------------------------------------------------------------------------------------------------------------------------------------

	// Functions with internal linkage
	// Because linkage is a property of an identifier (not of a variable), function identifiers have the same linkage property that variable identifiers do.
	// Functions default to external linkage (which we’ll cover in the next lesson), but can be set to internal linkage via the static keyword:

	{
		//std::cout << add(3, 4) << '\n';
		// This program won’t link, because function add is not accessible outside of add.cpp.
	}

	
	return 0;
}