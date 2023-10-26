#include <iostream>

int g_x { 5 };

int main()
{
    // In the previous lesson (12.3 -- Lvalue references), we discussed how an lvalue reference can only bind to a modifiable lvalue.
    // This means the following is illegal:
    {
        const int x { 5 };              // x is a non-modifiable (const) lvalue
        /*
        int& ref { x };                 // error: ref can not bind to a non-modifiable value
        */
    }

    // Lvalue reference to const

    // By using the const keyword when declaring an lvalue reference, we tell an lvalue reference to treat the object it is referencing as const.
    // Such a reference is called an lvalue reference to a const value (sometimes called a reference to const or a const reference).
    // Lvalue references to const can bind to non-modifiable lvalues:
    {
        const int x { 5 };                                  // x is a non-modifiable lvalue
        const int& ref { x };                               // okay: ref is a an lvalue reference to a const value
    }

    // Because lvalue references to const treat the object they are referencing as const, they can be used to access but not modify the value being referenced:

    {
        const int x { 5 };                                  // x is a non-modifiable lvalue
        const int& ref { x };                               // okay: ref is a an lvalue reference to a const value

        std::cout << ref << '\n';                           // okay: we can access the const object
        /*
        ref = 6;                                            // error: we can not modify an object through a const reference
        */
    }

    //---------------------------------------------------------------------------------------------

    // Initializing an lvalue reference to const with a modifiable lvalue
    // Lvalue references to const can also bind to modifiable lvalues.
    // In such a case, the object being referenced is treated as const when accessed through the reference (even though the underlying object is non-const):
    {
        int x { 5 };                                        // x is a modifiable lvalue
        const int& ref { x };                               // okay: we can bind a const reference to a modifiable lvalue

        std::cout << ref << '\n';                           // okay: we can access the object through our const reference
        /*
        ref = 7;                                            // error: we can not modify an object through a const reference
        */
       
        x = 6;                                              // okay: x is a modifiable lvalue, we can still modify it through the original identifier
    }

    //---------------------------------------------------------------------------------------------

    // Const references bound to temporary objects extend the lifetime of the temporary object
    
    // Temporary objects are normally destroyed at the end of the expression in which they are created.
    // However, consider what would happen in the above example if the temporary object created to hold rvalue 5 was destroyed at the end of the expression that initializes ref.
    //  Reference ref would be left dangling (referencing an object that had been destroyed), and we’d get undefined behavior when we tried to access ref.

    // To avoid dangling references in such cases, C++ has a special rule:
    // When a const lvalue reference is bound to a temporary object, the lifetime of the temporary object is extended to match the lifetime of the reference.
    {
        const int& ref { 5 };                               // The temporary object holding value 5 has its lifetime extended to match ref
        std::cout << ref << '\n';                           // Therefore, we can safely use it here
    }   // Both ref and the temporary object die here

    // In the above example, when ref is initialized with rvalue 5, a temporary object is created and ref is bound to that temporary object.
    // The lifetime of the temporary object matches the lifetime of ref.
    // Thus, we can safely print the value of ref in the next statement.
    // Then both ref and the temporary object go out of scope and are destroyed at the end of the block.

    //---------------------------------------------------------------------------------------------

    // Constexpr lvalue references

    // When applied to a reference, constexpr allows the reference to be used in a constant expression.
    // Constexpr references have a particular limitation: they can only be bound to objects with static duration (either globals or static locals).
    // This is because the compiler knows where static objects will be instantiated in memory, so it can treat that address as a compile-time constant.

    // A constexpr reference cannot bind to a (non-static) local variable.
    // This is because the address of local variables is not known until the function they are defined within is actually called.
    {
        [[maybe_unused]] constexpr int& ref1 { g_x };                   // ok, can bind to global
        
        static int s_x { 6 };
        [[maybe_unused]] constexpr int& ref2 { s_x };                   // ok, can bind to static local

        int x { 6 };
        /*
        [[maybe_unused]] constexpr int& ref3 { x };                     // compile error: can't bind to non-static object
        */
    }
}