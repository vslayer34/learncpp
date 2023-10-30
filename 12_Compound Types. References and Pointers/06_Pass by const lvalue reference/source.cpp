#include <iostream>
#include <string>
#include <string_view>

void printValueConst(const int& y)      // y is a conts reverence
{
    std::cout << y << '\n';
}

// A function with multiple parameters can determine whether each parameter is passed by value or passed by reference individually.
void foo(int a, int& b, const std::string& c)
{

}

// Function-like macro that evaluates to true if the type (or object) is equal to or smaller than
// the size of two memory addresses
#define isSmall(T)(sizeof(T) <= sizeof(void*))

struct S
{
    double a;
    double b;
    double c;
};

void printStringView(std::string_view sv)
{
    std::cout << sv << '\n';
}

void PrintString(const std::string& s)
{
    std::cout << s << '\n';
}

int main()
{
    // Passing by const reference offers the same primary benefit as pass by reference (avoiding making a copy of the argument).
    // While also guaranteeing that the function can not change the value being referenced.
    {
        int x { 5 };
        printValueConst(x);         // ok: x is a modifiable lValue

        const int z { 3 };
        printValueConst(z);         // ok: z is a non-modifiable lValue

        printValueConst(4);         // ok: 4 is a literal rValue
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Mixing pass by value and pass by reference
    {
        int x { 5 };
        const std::string s { "Hello World!" };

        foo(5, x, s);
    }

    //---------------------------------------------------------------------------------------------

    // The following program defines a function-like macro that can be used to determine if a type (or object) is cheap to copy accordingly:
    {
        std::cout << std::boolalpha;                        // print true or false rather than 1 or 0
        std::cout << isSmall(int) << '\n';                  // true
        std::cout << isSmall(double) << '\n';
        std::cout << isSmall(S) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';


    //---------------------------------------------------------------------------------------------

    // As you can see, std::string_view handles all three cases inexpensively.
    // a const std::string& parameter only handles std::string arguments inexpensively.
    {
        std::string s { "Hello World! "};
        std::string_view sv { s };

        // Pass to `std::string_view` parameter
        printStringView(s);                                         // ok: inexpensive conversion from std::string to std::string_view
        printStringView(sv);                                        // ok: inexpensive copy of std::string_view
        printStringView("Hello,, World!");                          // ok: inexpensive conversion of C-style string literal to std::string_view

        // pass to `const std::string&` parameter
        PrintString(s);                                             // ok: inexpensive bind to std::string argument
        /*PrintString(sv);                                          // compile error: cannot implicit convert std::string_view to std::string */
        PrintString(static_cast<std::string>(sv));                  // bad: expensive creation of std::string temporary    
        PrintString("Hello,, World");                               // bad: expensive creation of std::string temporary
    }
}