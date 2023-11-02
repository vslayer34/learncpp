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

    //---------------------------------------------------------------------------------------------

    // Pointers and assignment
    
    // We can use assignment with pointers in two different ways:
    // // To change what the pointer is pointing at (by assigning the pointer a new address)
    // // To change the value being pointed at (by assigning the dereferenced pointer a new value)
    
    // First, let’s look at a case where a pointer is changed to point at a different object:
    {
        int x { 5 };
        int* ptr { &x };                        // ptr initialized to point at x

        std::cout << "Pointer to x' address: " << *ptr << '\n';              // print the value at the address being pointed to (x's address)

        int y { 6 };
        ptr = &y;                               // change the pointer to point ay y

        std::cout << "Pointer to y' address: " << *ptr << '\n';              // print the value at the address being pointed to (y's address)
    }
    std::cout << std::string(70, '-') << '\n';

    // In the above example, we define pointer ptr, initialize it with the address of x, and dereference the pointer to print the value being pointed to (5).
    // We then use the assignment operator to change the address that ptr is holding to the address of y.
    // We then dereference the pointer again to print the value being pointed to (which is now 6).

    // Now let’s look at how we can also use a pointer to change the value being pointed at:
    {
        int x { 5 };
        int* ptr { &x };                    // initialize the pointer with the address of variable x

        std::cout << "x's value: " << x << '\n';
        std::cout << "The value at the address being pointed to (x's address): " << *ptr << '\n';

        std::cout << "Changeing the the value at the address the pointer is pointing at." << '\n';
        std::cout << "...." << '\n';
        std::cout << "....." << '\n';

        *ptr = 6;

        std::cout << "new x's value: " << x << '\n';
        std::cout << "The value at the address being pointed to (x's address): " << *ptr << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // In this example, we define pointer ptr, initialize it with the address of x, and then print the value of both x and *ptr (5).
    // Because *ptr returns an lvalue, we can use this on the left hand side of an assignment statement, which we do to change the value being pointed at by ptr to 6.
    // We then print the value of both x and *ptr again to show that the value has been updated as expected.

    //---------------------------------------------------------------------------------------------

    // Pointers behave much like lvalue references

    // Pointers and lvalue references behave similarly. Consider the following program:
    {
        int x { 5 };
        int& ref { x };                                              // get a reference to x
        int* ptr { &x };                                             // get a pointer to x address

        std::cout << "x: " << x << '\n';
        std::cout << "ref: " << ref << '\n';                        // we use reference to print the value of x
        std::cout << "*ptr: " << *ptr << '\n' << '\n';              // use the pointer to print the value at x's memory address

        ref = 6;                                                    // use the reference to change the value of x
        
        std::cout << "x: " << x << '\n';           
        std::cout << "ref: " << ref << '\n';                        // use the reference to print the new value of x
        std::cout << "*ptr: " << *ptr << '\n' << '\n';              // use the pointer to print the new value of x

        *ptr = 7;                                                   // use the pointer to change the value of x

        std::cout << "x: " << x << '\n';
        std::cout << "ref: " << ref << '\n';                        // use the reference to print the value of x
        std::cout << "*ptr: " << *ptr << '\n';                     // use the pointer to print the new value of x
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // The size of pointers

    // The size of a pointer is dependent upon the architecture the executable is compiled for -- a 32-bit executable uses 32-bit memory addresses -- consequently,
    // a pointer on a 32-bit machine is 32 bits (4 bytes).
    // With a 64-bit executable, a pointer would be 64 bits (8 bytes).
    // Note that this is true regardless of the size of the object being pointed to:
    {
        char* charPtr { };                                  // chars are 1 byte
        int* intPtr { };                                    // ints are usually 4 bytes
        long double longDoublePtr { };                      // long doubles are usually 8 to 12 bytes

        std::cout << sizeof(charPtr) << '\n';               // prints 4
        std::cout << sizeof(intPtr) << '\n';                // print 4 also
        std::cout << sizeof(longDoublePtr) << '\n';         // prints 4 too
    }
    std::cout << std::string(70, '-') << '\n';

    // The size of the pointer is always the same.
    // This is because a pointer is just a memory address, and the number of bits needed to access a memory address is constant.

    //---------------------------------------------------------------------------------------------

    // Dangling pointers
    // Here’s an example of creating a dangling pointer:
    {
        int x { 5 };
        int* ptr { &x };

        std::cout << *ptr << '\n';                  // is valid
        {
            int y { 6 };
            ptr = &y;

            std::cout << *ptr << '\n';              // also is valid
        }
        // y goes out of the scope, and now it's a dangling probliem

        std::cout << *ptr << '\n';                  // undefined behaviour from dereferencing a dangling pointer
    }
    std::cout << std::string(70, '-') << '\n';

    // The above program will probably print:
    // 5
    // 6
    // 6
    // But it may not, as the object that ptr was pointing at went out of scope and was destroyed at the end of the inner block, leaving ptr dangling.

    //---------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------

    // Quiz 
    // Question #1
    // What values does this program print? Assume a short is 2 bytes, and a 32-bit machine.
    {
        short value { 7 };                                  // &value: 0012FF60
        short otherValue { 3 };                             // &otherValue: 0012FF54

        short* ptr { &value };

        std::cout << &value << '\n';                        // 0012FF60
        std::cout << value << '\n';                         // 7
        std::cout << ptr << '\n';                           // 0012FF60
        std::cout << *ptr << '\n';                          // 7
        std::cout << '\n';

        *ptr = 9;

        std::cout << &value << '\n';                        // 0012FF60
        std::cout << value << '\n';                         // 9
        std::cout << ptr << '\n';                           // 0012FF60
        std::cout << *ptr << '\n';                          // 9
        std::cout << '\n';

        ptr = &otherValue;

        std::cout << &otherValue << '\n';                   // 0012FF54
        std::cout << otherValue << '\n';                    // 3
        std::cout << ptr << '\n';                           // 0012FF54
        std::cout << *ptr << '\n';                          // 3
        std::cout << '\n';

        std::cout << sizeof(ptr) << '\n';                   // 4
        std::cout << sizeof(*ptr) << '\n';                  // 2
    }
}