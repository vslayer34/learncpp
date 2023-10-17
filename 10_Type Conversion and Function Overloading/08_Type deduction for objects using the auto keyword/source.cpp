#include <iostream>


int add(int x, int y)
{
    return x + y;
}

std::string_view getString()
{
    return "Mohamed";
}

int main()
{
    // Because C++ is a strongly-typed language, we are required to provide an explicit type for all objects.
    // Thus, we’ve specified that variable d is of type double.
    // However, the literal value 5.0 used to initialize d also has type double (implicitly determined via the format of the literal).
    {
        double d { 5.0 };
    }

    //------------------------------------------------------------------------------------------------------------------------------

    // Type deduction for initialized variables

    // Type deduction (also sometimes called type inference) is a feature that allows the compiler to deduce the type of an object from the object’s initializer.
    // To use type deduction, the auto keyword is used in place of the variable’s type:

    {
        auto d { 5.0 };                     //  5.0 is double literal, so d would be of type doube
        auto i { 1 + 2 };                   // 1 + 2 evaluates to an int, so would be of type int
        auto x { i };                       // i is an int, so x would be of type int as well
    }

    // Because function calls are valid expressions, we can even use type deduction when our initializer is a function call:

    {
        auto sum { add(5, 6) };             // add() returns an int, so sum's type will be deduced to int
    }

    //----------------------------------------------------------------------------------------------------------------------------

    // Type deduction drops const / constexpr qualifiers
    // In most cases, type deduction will drop the const or constexpr qualifier from deduced types. For example:

    {
        const int x { 5 };                  // x has type const int
        auto y { x };                       // y will be type int (const is dropped)
    }

    // If you want a deduced type to be const or constexpr, you must supply the const or constexpr yourself.
    // To do so, simply use the const or constexpr keyword in conjunction with the auto keyword:

    {
        const int x { 5 };                  // x is of type const int (compile-time const)
        auto y { x };                       // y would be of type int (const is dropped)

        constexpr auto z { x };             // z would be of type constxepr int (constexpr is reapplied)
    }

    //-----------------------------------------------------------------------------------------------------------------------------

    // Type deduction for string literals
    // For historical reasons, string literals in C++ have a strange type. Therefore, the following probably won’t work as expected:
    {
        auto s { "Hello World!" };         // s would be of type const char*, not std::string
    }


    // If you want the type deduced from a string literal to be std::string or std::string_view, you’ll need to use the s or sv literal suffixes:

    {
        using namespace std::literals;

        auto s1 { "goo"s };                 // "goo"s is a std::string literal, so s1 will be deduced as a std::string
        auto s2 { "moo"sv };                // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view
    }

    //---------------------------------------------------------------------------------------------------------------------------------

    // Type deduction benefits and downsides
    // Type deduction is not only convenient, but also has a number of other benefits.
    // First, if two or more variables are defined on sequential lines, the names of the variables will be lined up, helping to increase readability:
    {
        // harder to read
        int a { 5 };
        double b { 6.7 };

        // easier to read
        auto c { 5 };
        auto b { 6.7 };
    }

    // Second, type deduction only works on variables that have initializers, so if you are in the habit of using type deduction.
    // it can help avoid unintentionally uninitialized variables:
    {
        int x; // oops, we forgot to initialize x, but the compiler may not complain
        /*
        auto y; // the compiler will error out because it can't deduce a type for y
        */
    }

    // Third, you are guaranteed that there will be no unintended performance-impacting conversions:
    {
        std::string_view getString();                  // some function that returns a string_view

        std::string s1 { getString() };                 // bad: expensive conversion from std::string_view to std::string
        auto s2 { getString() };                        // good: no conversiob is requiered
    }
}