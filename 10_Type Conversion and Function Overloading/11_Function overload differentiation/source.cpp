#include <iostream>

// How overloaded functions are differentiated
// Number of parameters:    yes
// Type of parameters:      Yes
// Return type:             No

//-------------------------------------------------------------------------------------------------

// Overloading based on number of parameters

// An overloaded function is differentiated so long as each overloaded function has a different number of parameters.
// For example:

int add(int x, int y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}

// The compiler can easily tell that a function call with two integer parameters should go to add(int, int)
// and a function call with three integer parameters should go to add(int, int, int).

//-------------------------------------------------------------------------------------------------

// Overloading based on type of parameters
// A function can also be differentiated so long as each overloaded function’s list of parameter types is distinct.
// For example, all of the following overloads are differentiated:
int add(int x, int y);
double add(double x, double y);
double add(int x, double y);
double add(double x, int y);

int main()
{
    
}