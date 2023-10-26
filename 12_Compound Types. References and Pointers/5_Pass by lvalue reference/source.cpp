#include <iostream>
#include <string>

void printValue(int y)
{
    std::cout << y << '\n';
}   // y is destroyed here

void printValueReferance(int& y)
{
    std::cout << y << '\n';
}   // y is destroyed here

void printValue(std::string y)
{
    std::cout << y << '\n';
}   // y is destroyed here

void printValueReferance(std::string& y)
{
    std::cout << y << '\n';
}   // y is destroyed here

void addOneByValue(int y) // y is a copy of x
{
    y++;                  // this modifies the copy of x, not the actual object x
}

void addOneByReferance(int& y)   // y is bound to x
{
    y++;                        // this modify the actual x
}

int main()
{
    // First, some context. Back in lesson 2.4 -- Introduction to function parameters and arguments we discussed pass by value,
    // where an argument passed to a function is copied into the function’s parameter:
    {
        int x { 2 };
        printValue(x);      // x is passed by value (copied) into parameter y (inexpensive)
    }
    std::cout << std::string(70, '-') << '\n';

    // In the above program, when printValue(x) is called, the value of x (2) is copied into parameter y.
    // Then, at the end of the function, object y is destroyed.
    // This means that when we called the function, we made a copy of our argument’s value, only to use it briefly and then destroy it!
    // Fortunately, because fundamental types are cheap to copy, this isn’t a problem.

    //---------------------------------------------------------------------------------------------

    // Some objects are expensive to copy
    // Most of the types provided by the standard library (such as std::string) are class types.
    // Class types are usually expensive to copy.
    // Whenever possible, we want to avoid making unnecessary copies of objects that are expensive to copy, especially when we will destroy those copies almost immediately.
    // Consider the following program illustrating this point:
    {
        std::string x { "Hello World!" };                       // x is a std::string
        printValue(x);                                          // x is passed by value (copied) into parameter y (expensive)
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Pass by reference
    // One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value.
    // When using pass by reference, we declare a function parameter as a reference type (or const reference type) rather than as a normal type.
    // When the function is called, each reference parameter is bound to the appropriate argument.
    // Because the reference acts as an alias for the argument, no copy of the argument is made.
    // Here’s the same example as above, using pass by reference instead of pass by value:
    {
        std::string x { "Hello World!" };
        printValue(x);                                          // x is now passed by reference into reference parameter y (inexpensive)
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Pass by reference allows us to change the value of an argument
    // When an object is passed by value, the function parameter receives a copy of the argument.
    // This means that any changes to the value of the parameter are made to the copy of the argument, not the argument itself:
    {
        int x { 5 };
        std::cout << "value: " << x << '\n';

        addOneByValue(x);

        std::cout << "new value: " << x << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    {
        int x { 5 };
        std::cout << "value: " << x << '\n';

        addOneByReferance(x);

        std::cout << "new value: " << x << '\n';        // x is modified
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Pass by reference can only accept modifiable lvalue arguments
    {
        int x { 5 };
        printValueReferance(x);             // ok: x is a modifiable lvalue

        const int z { 5 };
        /*
        printValueReferance(z);             // error: z is a non-modifiable lvalue
        printValueReferance(5);             // error: 5 is an rvalue
        */
    }
}