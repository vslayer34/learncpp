#include <iostream>

// This trivial function adds two integers and returns an integer result.
// However, what if we also want a function that can add two floating point numbers? This add() function is not suitable.
// As any floating point parameters would be converted to integers, causing the floating point arguments to lose their fractional values.
int add(int x, int y)
{
    return x + y;
}

// One way to work around this issue is to define multiple functions with slightly different names:
int addInteger(int x, int y)
{
    return x + y;
}

double addDouble(double x, double y)
{
    return x + y;
}

// However, for best effect, this requires that you define a consistent function naming standard for similar functions that have parameters of different types.
// remember the names of these functions, and actually call the correct one.
// And then what happens when we want to have a similar function that adds 3 integers instead of 2? Managing unique names for each function quickly becomes burdensome.

//-------------------------------------------------------------------------------------------------------------------------

// Introduction to function overloading
// To overload our add() function, we can simply declare another add() function that takes double parameters:
double add(double x, double y)
{
    return x + y;
}

// We now have two versions of add() in the same scope:
// The above program will compile.
// Although you might expect these functions to result in a naming conflict, that is not the case here.
// Because the parameter types of these functions differ, the compiler is able to differentiate these functions,
// and will treat them as separate functions that just happen to share a name.


int main()
{
    // Additionally, when a function call is made to a function that has been overloaded,
    // the compiler will try to match the function call to the appropriate overload based on the arguments used in the function call.
    // This is called overload resolution.

    // Here’s a simple example demonstrating this:
    {
        std::cout << add(1, 2) << '\n';                         // calls add(int, int)
        std::cout << '\n';
        std::cout << add(1.2, 3.4) << '\n';                     // calls add(double, double)
    }
    std::cout << std::string(70, '-') << '\n';

    // When we provide integer arguments in the call to add(1, 2), the compiler will determine that we’re trying to call add(int, int).
    // And when we provide floating point arguments in the call to add(1.2, 3.4), the compiler will determine that we’re trying to call add(double, double).

    //------------------------------------------------------------------------------------------------------------------------------

    
}