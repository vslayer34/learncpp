#include <iostream>

// When this function is compiled, the compiler will determine that x + y evaluates to an int,
//  then ensure that type of the return value matches the declared return type of the function (or that the return value type can be converted to the declared return type).
int addReturnInt(int x, int y)
{
    return x + y;
}

// Since the compiler already has to deduce the return type from the return statement,
//  in C++14, the auto keyword was extended to do function return type deduction.
// This works by using the auto keyword in place of the function’s return type.
auto addReturnAuto(int x, int y)
{
    return x + y;
}

// When using an auto return type, all return statements within the function must return values of the same type, otherwise an error will result. For example:
auto someFcn(bool b)
{
    if (b)
        return 5;                   // return an int
    else
    {
        /*return 6.7;*/             // return a double
        return 6;
    }
}

// In the above function, the two return statements return values of different types, so the compiler will give an error.

//-----------------------------------------------------------------------------------------------------------------------------

// The auto keyword can also be used to declare functions using a trailing return syntax
// Where the return type is specified after the rest of the function prototype.
// Consider the following function:

int add(int x, int y)
{
    return x + y;
}

// Using the trailing return syntax, this could be equivalently written as:
auto add2(int x, int y) -> int
{
    return x + y;
}

// In this case, auto does not perform type deduction -- it is just part of the syntax to use a trailing return type.
// One nice thing is that it makes all of your function names line up:
auto add(int x, int y) -> int;
auto divide(double x, double y) -> double;
auto printSomething() -> void;
auto generateSubstring(const std::string &s, int start, int len) -> std::string;

int main()
{

}