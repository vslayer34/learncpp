#include <iostream>
#include <cassert>

void printByValue(std::string value)            // The function parameter is a copy of str
{
    std::cout << value << '\n';                 // print the value via the copy
}

void printByReference(const std::string& ref)   // The function parameter is a reference that binds to a str
{
    std::cout << ref << '\n';                   // print the value via the reference
}

void printByAddress(const std::string* ptr)     // The function parameter is a parameter that holds the address of str
{
    std::cout << *ptr << '\n';                  // prints the value via the derefrenced pointer
}

void changeValue(int* ptr)                      // ptr is pointer to a non-constant in this example
{
    *ptr = 6;                                   // change the value to 6
}

// If a function is not supposed to modify the object being passed in, the function parameter can be made a pointer to const:
void changeValueConstant(const int* ptr)
{

}

void print(int* ptr)
{
    std::cout << *ptr << '\n';
}

void printNullSafe(int* ptr)
{
    if (ptr)                                    // if ptr is not a null pointer
    {
        std::cout << *ptr << '\n';
    }
}

// In the above program, we’re testing ptr to ensure it is not null before we dereference it.
// While this is fine for such a simple function, in more complicated functions this can result in redundant logic (testing if ptr is not null multiple times) or nesting of the primary logic of the function (if contained in a block).

// In most cases, it is more effective to do the opposite: test whether the function parameter is null as a precondition (8.18 -- Assert and static_assert) and handle the negative case immediately:
void printNullSafe2(int* ptr)
{
    if (!ptr)                                   // if ptr is null pointer, return early to the caller
    {
        return;
    }

    // if the code reached this point, we can assume ptr is a valid pointer
    // so no more testing is required

    std::cout << "printNullSafe2(int) " << *ptr << '\n';
}


void printAssert(const int* ptr)                // now a pointer to a const int
{
    // assert(ptr);                                // fail the program in debug mode if a null pointer is passed (since this should never happen)

    // (optionally) handle this as an error case in production mode so we don't crash if it does happen
    if (!ptr)
    {
        return;
    }

    std::cout << "printAssert() " << *ptr << '\n';
}

int main()
{
    // Here’s a sample program that shows a std::string object being passed by value and by reference:
    {
        std::string str { "I hate Moustafa!" };

        printByValue(str);                      // pass str by value, make a copy of it
        printByReference(str);                  // pass str by reference, doesn't make a copy of str
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Pass by address

    // C++ provides a third way to pass values to a function, called pass by address.
    // With pass by address, instead of providing an object as an argument, the caller provides an object’s address (via a pointer).
    // This pointer (holding the address of the object) is copied into a pointer parameter of the called function (which now also holds the address of the object).
    // The function can then dereference that pointer to access the object whose address was passed.

    // Here’s a version of the above program that addIf a function is not supposed to modify the object being passed in, the function parameter can be made a pointer to const:s a pass by address variant:
    {
        std::string str { "Moustafa Kheder \uF620" };

        printByValue(str);                      // pass str by value, make a copy of it
        printByReference(str);                  // pass str by reference, doesn't make a copt of it
        printByAddress(&str);                    // pass str by address, doesn't make a copy of it
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Pass by address does not make a copy of the object being pointed to
    // Consider the following statements:
    {
        std::string str { "Hello World!" };
        printByAddress(&str);                       // use address-of operator (&) to get pointer holding address of str
    }
    std::cout << std::string(70, '-') << '\n';

    // As we noted in 12.5 -- Pass by lvalue reference, copying a std::string is expensive, so that’s something we want to avoid.
    // When we pass a std::string by address, we’re not copying the actual std::string object -- we’re just copying the pointer (holding the address of the object) from the caller to the called function.
    // Since an address is typically only 4 or 8 bytes, a pointer is only 4 or 8 bytes, so copying a pointer is always fast.

    // Thus, just like pass by reference, pass by address is fast, and avoids making a copy of the argument object.

    //---------------------------------------------------------------------------------------------

    // Pass by address allows the function to modify the argument’s value

    // When we pass an object by address, the function receives the address of the passed object, which it can access via dereferencing.
    // Because this is the address of the actual argument object being passed (not a copy of the object), if the function parameter is a pointer to non-const, the function can modify the argument via the pointer parameter:
    {
        int x { 5 };
        std::cout << "x (before changeValue()): " << x << '\n';

        changeValue(&x);                            // we're passing the address of x to the function
        std::cout << "x (after changeValue()): " << x << '\n';

    }

    //---------------------------------------------------------------------------------------------

    // Null checking
    // Now consider this fairly innocent looking program:
    {
        int x { 5 };
        print(&x);

        int* myPtr { };
        /*print(myPtr);*/
    }
    std::cout << std::string(70, '-') << '\n';

    // When this program is run, it will print the value 5 and then most likely crash.

    // In the call to print(myPtr), myPtr is a null pointer, so function parameter ptr will also be a null pointer.
    // When this null pointer is dereferenced in the body of the function, undefined behavior results.

    // When passing a parameter by address, care should be taken to ensure the pointer is not a null pointer before you dereference the value.
    // One way to do that is to use a conditional statement:
    {
        int x { 5 };
        printNullSafe(&x);

        int* myPtr { };
        printNullSafe(myPtr);
    }
    std::cout << std::string(70, '-') << '\n';

    // In most cases, it is more effective to do the opposite: test whether the function parameter is null as a precondition (8.18 -- Assert and static_assert) and handle the negative case immediately:
    {
        int x { 5 };

        printNullSafe2(&x);
        printNullSafe2(nullptr);
    }
    std::cout << std::string(70, '-') << '\n';

    // If a null pointer should never be passed to the function, an assert (which we covered in lesson 8.18 -- Assert and static_assert) can be used instead (or also) (as asserts are intended to document things that should never happen):
    {
        int x { 5 };

        printAssert(&x);
        printAssert(nullptr);
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Prefer pass by (const) reference

    // Note that function print() in the example above doesn’t handle null values very well -- it effectively just aborts the function.
    // Given this, why allow a user to pass in a null value at all?
    // Pass by reference has the same benefits as pass by address without the risk of inadvertently dereferencing a null pointer.

    // Pass by const reference has a few other advantages over pass by address.

    // First, because an object being passed by address must have an address, only lvalues can be passed by address (as rvalues don’t have addresses).
    // Pass by const reference is more flexible, as it can accept lvalues and rvalues:
    
    // Second, the syntax for pass by reference is natural, as we can just pass in literals or objects.
    // With pass by address, our code ends up littered with ampersands (&) and asterisks (*).

    // In modern C++, most things that can be done with pass by address are better accomplished through other methods.
    // Follow this common maxim: “Pass by reference when you can, pass by address when you must”.
}