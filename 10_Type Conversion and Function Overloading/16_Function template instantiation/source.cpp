#include <iostream>
#include "addOne.h"

// In this lesson, we’ll focus on how function templates are used.

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

//-------------------------------------------------------------------------------------------------

// Function templates with non-template parameters
// It’s possible to create function templates that have both template parameters and non-template parameters.
// The type template parameters can be matched to any type, and the non-template parameters work like the parameters of normal functions.
// For example:

// T is a type template parameter
// double is a non-template parameter
template <typename T>
int someFunc(T, double)
{
    return 5;
}

//-------------------------------------------------------------------------------------------------

// We can use the delete keyword to omit instantiating a fuction with a data type we don't need
template <typename T>
T addOne(T x)
{
    return x + 1;
}

// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
template <>
const char* addOne(const char* x) = delete;

int main()
{
    // To use our max<T> function template, we can make a function call with the following syntax:
    // max<actual_type>(arg1, arg2); // actual_type is some actual type, like int or double

    {
        // instantiates and calls function max<int>(int, int)
        std::cout << max<int>(1, 2) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // You can compile this yourself and see that it works.
    // A function template is only instantiated the first time a function call is made in each translation unit.
    // Further calls to the function are routed to the already instantiated function.
    // Conversely, if no function call is made to a function template, the function template won’t be instantiated in that translation unit.
    // Let’s do another example:
    {
        std::cout << max<int>(1, 2) << '\n';                // instantiates and calls function max<int>(int, int)
        std::cout << max<int>(4, 3) << '\n';                // calls already instantiated function max<int>(int, int)
        std::cout << max <double>(7, 9) << '\n';            // instantiates and calls function max<double>(double, double)
    }
    std::cout << std::string(70, '-') << '\n';
    // This works similarly to the previous example, but our function template will be used to generate two functions this time:
    // one time replacing T with int, and the other time replacing T with double

    //---------------------------------------------------------------------------------------------

    // Template argument deduction

    // In cases where the type of the arguments match the actual type we want.
    // We do not need to specify the actual type -- instead.
    // We can use template argument deduction to have the compiler deduce the actual type that should be used from the argument types in the function call.

    // We can do one of these instead:
    {
        std::cout << max<>(1, 2) << '\n';
        std::cout << max(1, 2) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';
    
    // The difference between the two cases has to do with how the compiler resolves the function call from a set of overloaded functions.
    // In the top case (with the empty angled brackets),
    // the compiler will only consider max<int> template function overloads when determining which overloaded function to call.
    // In the bottom case (with no angled brackets), the compiler will consider both max<int> template function overloads and max non-template function overloads.

    //---------------------------------------------------------------------------------------------

    // Function templates with non-template parameters

    {
        someFunc(1, 3.4);                       // matches someFunc(int, double)
        someFunc(1, 3.4f);                      // matches someFunc(int, double) ---> the float is promoted to double
        someFunc(1.2, 3.4);                     // matches someFunc(double, double)
        someFunc(1.2f, 3.4);                    // matches someFunc(float, double)
        someFunc(1.2f, 3.4f);                   // matches someFunc(float, float)
    }

    // This function template has a templated first parameter, but the second parameter is fixed with type double.
    // Note that the return type can also be any type. In this case, our function will always return an int value.

    // compile error
    {
        /*
        std::cout << addOne("Hello world") << '\n';
        */
    }

    {
        std::cout << addOne(1) << '\n';
        std::cout << addOne(2.3f) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';
}