#include <iostream>

int main()
{
    // Because 10 and 4 are both of type int, integer division is performed, and the expression evaluates to int value 2.
    //  This value then undergoes numeric conversion to double value 2.0 before being used to initialize variable d.
    // Most likely, this isn’t what was intended.
    {
        // does integer division, initializes d with value 2.0
        double d = 10 / 4;
    }

    // In the case where you are using literal operands, replacing one or both of the integer literals with double literals will cause floating point division to happen instead:
    {
        // does floating point division, initializes d with value 2.5
        double d = 10.0 / 4.0;
    }

    // But what if you are using variables instead of literals? Consider this case:
    {
        int x { 10 };
        int y { 4 };

        double d = x / y;                               // does integer division, initializes d with value 2.0
    }

    //---------------------------------------------------------------------------------------------------------------------------------------------

    // Type casting
    // C++ supports 5 different types of casts: C-style casts, static casts, const casts, dynamic casts, and reinterpret casts.
    //  The latter four are sometimes referred to as named casts.

    // We’ll cover C-style casts and static casts in this lesson.

    //---------------------------------------------------------------------------------------------------------------------------------------------
    
    // C-style casts

    // In standard C programming, casts are done via the () operator, with the name of the type to convert the value placed inside the parentheses.
    //  You may still see these used in code (or by programmers) that have been converted from C.

    // For example:
    {
        int x { 10 };
        int y { 4 };

        // convert x to a double so we get floating point division
        double d { (double)x / y };

        // prints 2.5
        std::cout << d << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // C++ will also let you use a C-style cast with a more function-call like syntax:
    {
        double d { double(10) / 4 };
    }

    // This performs identically to the prior example, but has the benefit of parenthesizing the value being converted (making it easier to tell what is being converted).

    //-------------------------------------------------------------------------------------------------------------------------------------------------

    // static_cast
    // C++ introduces a casting operator called static_cast, which can be used to convert a value of one type to a value of another type.
    // You’ve previously seen static_cast used to convert a char into an int so that std::cout prints it as an integer instead of a char:
    {
        char c { 'a' };
        
        // prints a 97
        std::cout << c << ' ' << static_cast<int>(c) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';



    // The static_cast operator takes an expression as input, and returns the evaluated value converted to the type specified inside the angled brackets.
    //  static_cast is best used to convert one fundamental type into another.
    {
        int x { 10 };
        int y { 4 };

        // static cast x to a double so we get floating point division
        double d { static_cast<double>(x) / y };
        // print 2.5
        std::cout << d << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // The main advantage of static_cast is that it provides compile-time type checking, making it harder to make an inadvertent error.

    {
        // a C-style string literal can't be converted to an int, so the following is an invalid conversion
        
        /*
        int x { static_cast<int>("Hello") };
        */
    }

    //-------------------------------------------------------------------------------------------------------------------------------------------------

    // Using static_cast to make narrowing conversions explicit
    // Compilers will often issue warnings when a potentially unsafe (narrowing) implicit type conversion is performed. For example, consider the following program:
    {
        int i { 48 };
        // implicit narrowing conversion
        char ch = i;
    }

    // Casting an int (2 or 4 bytes) to a char (1 byte) is potentially unsafe (as the compiler can’t tell whether the integer value will overflow the range of the char or not),
    // and so the compiler will typically print a warning. If we used list initialization, the compiler would yield an error.

    // To get around this, we can use a static cast to explicitly convert our integer to a char:
    {
        int i { 48 };
        char ch { static_cast<char>(i) };
    }

    // When we do this, we’re explicitly telling the compiler that this conversion is intended,
    //  and we accept responsibility for the consequences (e.g. overflowing the range of a char if that happens).
    //  Since the output of this static_cast is of type char, the initialization of variable ch doesn’t generate any type mismatches, and hence no warnings or errors.
}