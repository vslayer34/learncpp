#include <iostream>

void someFunction(int num)
{

}

void print(unsigned int u)  // note: unsigned
{
    std::cout << u << '\n';
}

int main()
{
    // Make intentional narrowing conversions explicit
    {
        double d { 5.0 };

        someFunction(d);        // bad: implicit narrowing conversion will generate compiler warning

        // good: we're explicitly telling the compiler this narrowing conversion is intentional
        someFunction(static_cast<int>(d));
    }

    {
        
        /*
        int i { 3.5 };          // won't compile
        */
        double d { 3.5 };

        // static_cast<int>() converts double d to int, initializes i with int result
        int i { static_cast<int>(d) };


        // When the source value of a narrowing conversion isn’t known until runtime, the result of the conversion also can’t be determined until runtime.
        // In such cases, whether the narrowing conversion preserves the value or not also can’t be determined until runtime.
        // For example:

        std::cout << "Enter an intergal int: "       ;
        int n {};
        std::cin >> n ;     // enter 5 or -5
        print(n);           // conversion to unsigned may or may not preserve the value

        // In the above program, the compiler has no idea what value will be entered for n.
        // When print(n) is called, the conversion from int to unsigned int will be performed at that time 
        // The results may be value-preserving or not depending on what value for n was entered.
        //  Thus, a compiler that has signed/unsigned warnings enabled will issue a warning for this case.

        {
            constexpr int n1 { 5 };              // note: constexpr
            unsigned int u1 { n1 };             // okay: conversion is not narrowing due to exclusion clause

            constexpr int n2 { -5 };            // note: constexpr
            unsigned int  u2 { n2 };            // compile error: conversion is narrowing due to value change
        }

        //----------------------------------------------------------------------------------------------------------------------------

        // List initialization with constexpr initializers
        // These constexpr exception clauses are incredibly useful when list initializing non-int/non-double objects.
        // As we can use an int or double literal (or a constexpr object) initialization value.
        // This allows us to avoid:
            // Having to use literal suffixes in most cases
            // Having to clutter our initializations with a static_cast
        // For example:

        {
            // we can avoid literals with suufixes
            unsigned int u { 5 };                   // Okay (we don't need to use '5u')
            float f { 1.5 };                        // Okay (we don't need to use '1.5f')

            // we can avoid static_cast<>
            constexpr int u { 5 };
            double d { n };                         // okay (we don't need a static_cast here)
            short s { 5 };                          // okay (there is no suffix for short, we don't need a static_cast here)
        }
    }
}