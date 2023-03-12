#include <iostream>

// varables declared outside of a function are global variables
int g_x{};															// global variable g_x

// Global variable initialization
// Unlike local variables, which are uninitialized by default, variables with static duration are zero-initialized by default.
int g_a;															// no explicit initializer (zero-initialized by default)
int g_b;															// zero_initialized
int g_c{ 1 };														// initialized with value

//-------------------------------------------------------------------------------------------------------------------------------------------------------
// Constant global variables
// Just like local variables, global variables can be constant.
// As with all constants, constant global variables must be initialized.

//const int g_x1;													// error: constant variables must be initialized
//constexpr int g_w1;												// error: constexpr variables must be initialized

const int g_y1{ 1 };												 // const global variable g_y, initialized with a value
constexpr int g_z1{ 2 };											// constexpr global variable g_z, initialized with a value


void doSomething()
{
	// global variables can be seen and used everywhere in the file
	g_x = 3;
	std::cout << g_x << '\n';
}

int main()
{
	// Declaring and naming global variables
	// By convention, global variables are declared at the top of a file, below the includes, but above any code. 
	// Here’s an example of a global variable being defined:

	doSomething();
	std::cout << g_x << '\n';

	// global variables can be seen and used everywhere in the file
	g_x = 5;
	std::cout << g_x << '\n';
	std::cout << '\n';

	// By convention, many developers prefix non-const global variable identifiers with “g” or “g_” to indicate that they are global.

	//-------------------------------------------------------------------------------------------------------------------------------------------------------


	
	return 0;
}