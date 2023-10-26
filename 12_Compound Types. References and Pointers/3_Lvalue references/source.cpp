#include <iostream>



int main()
{
    // In C++, a reference is an alias for an existing object.
    // Once a reference has been defined, any operation on the reference is applied to the object being referenced.

    // Lvalue reference types
    // An lvalue reference (commonly just called a reference since prior to C++11 there was only one type of reference)
    // acts as an alias for an existing lvalue (such as a variable).
    // To declare an lvalue reference type, we use an ampersand (&) in the type declaration:
    {
        /*
        int                         // a normal int type
        int&                        // an lvalue referance to an int object
        double&                     // and lvalue referance to a double object
        */
    }

    //---------------------------------------------------------------------------------------------

    // Lvalue reference variables
    // One of the things we can do with an lvalue reference type is create an lvalue reference variable.
    // An lvalue reference variable is a variable that acts as a reference to an lvalue (usually another variable).

    // To create an lvalue reference variable, we simply define a variable with an lvalue reference type:
    {
        int x { 5 };                    // x is a normal integer variable
        int& ref { x };                 // ref is an lvalue referance variable that can now be used as an alias for variable x

        std::cout << x << '\n';         // print the value of x (5)
        std::cout << ref << '\n';       // print the value of x via ref (5)
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Modifying values through an lvalue reference
    // In the above example, we showed that we can use a reference to read the value of the object being referenced.
    // We can also use a reference to modify the value of the object being referenced:
    {
        int x { 5 };                            // normal integer variable
        int& ref { x };                         // ref is now an alias for variable x

        std::cout << x << ref << '\n';          // prints 55

        x = 6;                                  // x now has the value of 6

        std::cout << x << ref << '\n';          // prints 66

        ref = 7;                                // the object being referenced (x) now has the value of 7

        std::cout << x << ref << '\n';          // prints 77
    }
    std::cout << std::string(70, '-') << '\n';

    // In the above example, ref is an alias for x, so we are able to change the value of x through either x or ref.

    //---------------------------------------------------------------------------------------------

    // Initialization of lvalue references
    // Much like constants, all references must be initialized.
    {
        /*
        int& invalidRef;                        // errors: references must be initialized
        */

       int x { 5 };
       int& ref { x };                          // okay: reference to int is bound to int variable
    }
    // When a reference is initialized with an object (or function), we say it is bound to that object (or function).
    // The process by which such a reference is bound is called reference binding.
    // The object (or function) being referenced is sometimes called the referent.

    // Lvalue references must be bound to a modifiable lvalue.
    {
        int x { 5 };
        int& ref { x };                     // valid: lvalue reference bound to a modifiable lvalue

        const int y { 5 };
        /*
        int& invalidRef { y };              // invalid: can't bind to a non-modifiable lvalue
        int& invalidRef2 { 0 };             // invalid: can't bind to an rvalue
        */
    }

    // Lvalue references can’t be bound to non-modifiable lvalues or rvalues (otherwise you’d be able to change those values through the reference,
    // which would be a violation of their const-ness).
    // For this reason, lvalue references are occasionally called lvalue references to non-const (sometimes shortened to non-const reference).

    // In most cases, the type of the reference must match the type of the referent (there are some exceptions to this rule that we’ll discuss when we get into inheritance):
    {
        int x { 5 };
        int& ref { x };                     // okay: reference to int is bound to int variable

        double y { 6.0 };
        /*
        int& invalidRef { y };              // invalid: reference to int cannot bind to double variable
        double& invalidRef2 { x };          // invalid: reference to double cannot bind to int variable
        */
    }

    // Lvalue references to void are disallowed (what would be the point?).

    //---------------------------------------------------------------------------------------------

    // References can’t be reseated (changed to refer to another object)
    
    // Once initialized, a reference in C++ cannot be reseated, meaning it cannot be changed to reference another object.
    // New C++ programmers often try to reseat a reference by using assignment to provide the reference with another variable to reference.
    // This will compile and run -- but not function as expected. Consider the following program:
    {
        int x { 5 };
        int y { 6 };

        int& ref { x };      // ref is now an alias for x
        ref = y;            // assigns 6 (the value of y) to x (the object being referenced by ref)
        // The above line does NOT change ref into a reference to variable y!
        
        std::cout << x << '\n';         // user is expecting this to print 5
    }
    std::cout << std::string(70, '-') << '\n';

    // When a reference is evaluated in an expression, it resolves to the object it’s referencing.
    // So ref = y doesn’t change ref to now reference y.
    // Rather, because ref is an alias for x, the expression evaluates as if it was written x = y -- and since y evaluates to value 6, x is assigned the value 6.

    //---------------------------------------------------------------------------------------------

    // References and referents have independent lifetimes
    
    // With one exception (that we’ll cover next lesson), the lifetime of a reference and the lifetime of its referent are independent.
    // In other words, both of the following are true:
    // // // A reference can be destroyed before the object it is referencing.
    // // // The object being referenced can be destroyed before the reference.

    // When a reference is destroyed before the referent, the referent is not impacted. The following program demonstrates this:
    {
        int x { 5 };

        {
            int& ref { x };                         // ref is a reference to x
            std::cout << ref << '\n';               // prints value of ref (5)
        }   // // ref is destroyed here -- x is unaware of this

        std::cout << x << '\n';
    }   // x is destroyed here
    std::cout << std::string(70, '-') << '\n';

    // When ref dies, variable x carries on as normal, blissfully unaware that a reference to it has been destroyed.

    //---------------------------------------------------------------------------------------------
    
    // Dangling references
    // When an object being referenced is destroyed before a reference to it, the reference is left referencing an object that no longer exists.
    // Such a reference is called a dangling reference. Accessing a dangling reference leads to undefined behavior.

    //---------------------------------------------------------------------------------------------

    // Question #1
    // Determine what values the following program prints by yourself (do not compile the program).
    {
        int x { 1 };
        int& ref { x };

        std::cout << x << ref << '\n';

        int y { 2 };
        ref = y;
        y = 3;

        std::cout << x << ref << '\n';

        x = 4;

        std::cout << x << ref << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // it prints
    // 11
    // 22
    // 44
}