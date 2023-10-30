#include <iostream>



int main()
{
    // The address-of operator (&)
    // Although the memory addresses used by variables aren’t exposed to us by default, we do have access to this information.
    // The address-of operator (&) returns the memory address of its operand. This is pretty straightforward:
    {
        int x { 5 };
        std::cout << x << '\n';                                 // print the value of variable x
        std::cout << &x << '\n';                                // prints the memory address of variable x
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // The dereference operator (*)

    // Getting the address of a variable isn’t very useful by itself.
    // The most useful thing we can do with an address is access the value stored at that address.
    // The dereference operator (*) (also occasionally called the indirection operator) returns the value at a given memory address as an lvalue:
    {
        int x { 5 };
        std::cout << x << '\n';                             // prints the value of variable x
        std::cout << &x << '\n';                            // prints the memory address of variable x

        std::cout << *(&x) << '\n';                         // print the value at the memory address of variable x (parentheses not required, but make it easier to read)
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Pointers
    // A pointer is an object that holds a memory address (typically of another variable) as its value.
    // This allows us to store the address of some other object to use later.

    // Much like reference types are declared using an ampersand (&) character, pointer types are declared using an asterisk (*):
    /*
    *{
    *   int;                        // a normal int
    *   int&;                       // a lValue reference to an int value
    *   int*;                       // a pointer to a int value (holds the address of ani integer value).
    *}
    */

    // To create a pointer variable, we simply define a variable with a pointer type:
    {
        int x { 5 };                        // normal variable
        int& ref { x };                     // a reference to an integer (bound to x).
        int* ptr;                           // a pointer to an integer
    }

    //---------------------------------------------------------------------------------------------

    // Pointer initialization
    // Like normal variables, pointers are not initialized by default.
    // A pointer that has not been initialized is sometimes called a wild pointer.
    // Wild pointers contain a garbage address, and dereferencing a wild pointer will result in undefined behavior.
    // Because of this, you should always initialize your pointers to a known value.
    {
        int x { };

        int* ptr1;                           // an uninitialized pointer (holds a garbage address)
        int* ptr2 { };                       // a null pointer (we'll discuss these in the next lesson)
        int* ptr3 { &x };                    // a pointer initialized with the address of variable x
    }

    // Once we have a pointer holding the address of another object, we can then use the dereference operator (*) to access the value at that address.
    // For example:
    {
        int x { 5 };
        std::cout << x << '\n';                     // print a value of variable x

        int* ptr { &x };                            // holds the memory address of variable x
        std::cout << *ptr << '\n';                  // use dereference operator to print the value at the address that ptr is holding
    }
    std::cout << std::string(70, '-') << '\n';

    
}