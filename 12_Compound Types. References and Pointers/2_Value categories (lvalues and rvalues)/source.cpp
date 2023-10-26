#include <iostream>


int return5()
{
    return 5;
}


int main()
{
    // Before we talk about our first compound type (lvalue references), we’re going to take a little detour and talk about what an lvalue is.
    // we defined an expression as “a combination of literals, variables, operators, and function calls that can be executed to produce a singular value”.
    // For example:
    {
        // The expression 2 + 3 produces the value 5
        std::cout << 2 + 3 << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // In lesson 6.4 -- Increment/decrement operators, and side effects, we also noted that expressions can produce side effects that outlive the expression:
    {
        int x { 5 };
        x++;
        std::cout << x << '\n'; // prints 6
    }
    std::cout << std::string(70, '-') << '\n';
    // In the above program, the expression x++ increments the value of x, and that value remains changed even after the expression has finished evaluating.

    //---------------------------------------------------------------------------------------------

    // The type of an expression
    // The type of an expression is equivalent to the type of the value, object, or function that results from the evaluated expression. For example:
    {
        auto v1 { 12 / 4 };     // int / int => int
        auto v2 { 12.0 / 4 };   // double / int => double
    }

    //---------------------------------------------------------------------------------------------

    // Entities with identities can be accessed via an identifier, reference, or pointer, and typically have a lifetime longer than a single expression or statement.
    // and called l-value
    {
        int x { 5 };
        int y { x };
    }
    // In the above program, the expression x is an lvalue expression as it evaluates to variable x (which has an identifier).
    
    {
        int x { };
        const double d { };

        int y { x };                // x is a modifiable lvalue expression
        const double e { d };       // d is a non-modifiable lvalue expression
    }

    // An rvalue (pronounced “arr-value”, short for “right value”, and sometimes written as r-value) is an expression that is not an lvalue.
    // Commonly seen rvalues include literals (except C-style string literals, which are lvalues) and the return value of functions and operators that return by value.
    // Rvalues aren’t identifiable (meaning they have to be used immediately), and only exist within the scope of the expression in which they are used.
    {
        int x { 5 };                            // 5 is an rvalue expression
        const double d { 1.2 };                 // 1.2 is an rvalue expression

        int y { x };                            // x is a modifiable lvalue expression
        const double e { d };                   // d is a non-modifiable lvalue expression
        int z { return5() };                    // return5() is an rvalue expression (since the result is returned by value)

        int w { x + 1 };                        // x + 1 is an rvalue expression
        int q { static_cast<int>(d) };          // the result of static casting d to an int is an rvalue expression
    }

    // You may be wondering why return5(), x + 1, and static_cast<int>(d) are rvalues:
    // the answer is because these expressions produce temporary values that are not identifiable objects.

    
}