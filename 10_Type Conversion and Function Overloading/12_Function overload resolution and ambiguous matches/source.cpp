#include <iostream>

// With non-overloaded functions (functions with unique names), there is only one function that can potentially match a function call.
// That function either matches (or can be made to match after type conversions are applied), or it doesn’t (and a compile error results).
// With overloaded functions, there can be many functions that can potentially match a function call.
// Since a function call can only resolve to one of them, the compiler has to determine which overloaded function is the best match.
// The process of matching function calls to a specific overloaded function is called overload resolution.

void print(int x)
{
    std::cout << "int: " << x << '\n';
}

void print(double x)
{
    std::cout<< "double: " << x << '\n';
}

int main()
{
    {
        print(5);                           // 5 is an int so it matches the print(int)
        print(6.7);                         // 6.7 is double so it matches the print(double)
    }

    // But what happens in cases where the argument types in the function call don’t exactly match the parameter types in any of the overloaded functions? For example:

    {
        print('a');                         // char does not match int or double
        /*print(5L);                          // long does not match int or double*/
    }
}