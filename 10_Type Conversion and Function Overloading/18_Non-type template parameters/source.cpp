#include <iostream>
#include <bitset>
#include <cassert>
#include <cmath>            // for std::sqrt



// declare a non-type template parameter of type int named N
template <int N>
void print()
{
    // use value of N here
    std::cout << N << '\n';
}

/*
double getSqrt(double d)
{
    assert(d >= 0.0 && "getSqrt(): d must not be a negative number");

    if (d >= 0)
    {
        return std::sqrt(d);
    }

    return 0.0;
}
*/

// However, if we change the function parameter to a non-type template parameter instead, then we can do exactly as we want:
// requires C++20 for floating point non-type parameters
template <double D>
double getSqrt()
{
    static_assert(D >= 0.0 && "getSqrt(): d must not be a negative number");

    if constexpr (D >= 0.0) // ignore the constexpr here for this example
    {
        return std::sqrt(D);    // strangely, std::sqrt isn't a constexpr function (until C++26)
    }

    return 0.0;
}

int main()
{
    // Non-type template parameters
    // A non-type template parameter is a template parameter with a fixed type that serves as a placeholder for a constexpr value passed in as a template argument.
    // A non-type template parameter can be any of the following types:
    // // An integral type
    // // An enumeration type
    // // std::nullptr_t
    // // A floating point type (since C++20)
    // // A pointer or reference to an object
    // // A pointer or reference to a function
    // // A pointer or reference to a member function
    // // A literal class type (since C++20)

    // We saw our first example of a non-type template parameter when we discussed std::bitset
    {
        std::cout << std::bitset<8>{ 0b0000'0101 } << '\n'; 
    }
    std::cout << std::string(70, '-') << '\n';
    // In the case of std::bitset, the non-type template parameter is used to tell the std::bitset how many bits we want it to store.

    //---------------------------------------------------------------------------------------------

    // Defining our own non-type template parameters
    // Here’s a simple example of a function that uses an int non-type template parameter:

    {
        // 5 is our non-type template argument
        print<5>();
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // What are non-type template parameters useful for?
    // As of C++20, function parameters cannot be constexpr.
    // This is true for normal functions, constexpr functions (which makes sense, as they must be able to be run at runtime),
    // and perhaps surprisingly, even consteval functions.

    {
        // std::cout << getSqrt<5.0>() << '\n';
        // std::cout << getSqrt<-5.0>() << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // When run, the call to getSqrt(-5.0) will runtime assert out.
    // While this is better than nothing, because -5.0 is a literal (and implicitly constexpr),
    // it would be better if we could static_assert so that errors such as this one would be caught at compile-time.
    // However, static_assert requires a constant expression, and function parameters can’t be constexpr…
}