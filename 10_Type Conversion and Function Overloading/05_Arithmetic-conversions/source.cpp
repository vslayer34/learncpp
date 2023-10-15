#include <iostream>


/// 10.5 — Arithmetic conversions
int main()
{
    // When binary operator+ is invoked, it is given two operands, both of type int.
    //  Because both operands are of the same type, that type will be used to perform the calculation and to return the result. 
    // Thus, 2 + 3 will evaluate to int value 5.d
    {
        int x { 2 + 3 };
    }

    // But what happens when the operands of a binary operator are of different types?


    // Binary operator+ is one of the operators that requires its operands to have the same type.
    // In the following examples, we’ll use the typeid operator (included in the <typeinfo> header), to show the resulting type of an expression.

    // First, let’s add an int and a double:
    {
        int i { 2 };
        double d { 3.5 };

        std::cout << typeid(i + d).name() << ' ' << i + d << '\n';      // show us the type i + d        
    }
    std::cout << std::string(70, '-') << '\n';


    // Now let’s add two values of type short:
    {
        short a { 4 };
        short b { 5 };

        std::cout << typeid(a + b).name() << ' ' << a + b << '\n';      // show us the type of a + b
    }
    std::cout << std::string(70, '-') << '\n';

    //----------------------------------------------------------------------------------------------------------------------------------------

    // Signed and unsigned issues
    // This prioritization hierarchy can cause some problematic issues when mixing signed and unsigned values.
    // For example, take a look at the following code:
    {
        std::cout << typeid(5u - 10).name() << ' ' << 5u - 10 << '\n';  // 5u means treat 5 as an unsigned integer
    }


    // Because the unsigned int operand has higher priority, the int operand is converted to an unsigned int.
    // And since the value -5 is out of range of an unsigned int, we get a result we don’t expect.
    // Here’s another example showing a counterintuitive result:
    {
        std::cout << std::boolalpha << (-3 < 5u) << '\n';
    }

    // While it’s clear to us that 5 is greater than -3, when this expression evaluates, -3 is converted to a large unsigned int that is larger than 5.
    // Thus, the above prints false rather than the expected result of true.



}