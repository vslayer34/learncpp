#include <iostream>
#include <string>
#include <cstddef>                              // for NULL nad std::nullptr_t

void greet(std::string* name = nullptr)
{
    std::cout << "Hello " << (name ? *name : "dear guest") << '\n';
}

void greetOverloaded(std::string_view name)
{
    std::cout << "Hello " << name << '\n';
}

void greetOverloaded()
{
    std::cout << "Hello dear guest" << '\n';
}

// [[maybe_unused]] gets rid of compiler warnings about ptr2 being set but not used
void nullify([[maybe_unused]] int* ptr2)
{
    ptr2 = nullptr;                     // make the function parameter a null pointer
}

void nullifyV2([[maybe_unused]] int*& refptr)       // refptr is now a reference to a pointer
{
    refptr = nullptr;                   // Make the function parameter a null pointer
}

void print(int x)                       // this function accepts an integer
{
    std::cout << "print(int): " << x << '\n';
}

void print(int* ptr)                    // this function accepts an integer pointer
{
    std::cout << "print(int*): " << (ptr ? "non-null" : "null") << '\n';
}

void printV2(std::nullptr_t)
{
    std::cout << "in printV2(std::nullptr_t)" << '\n';
}

/*
void printV2(int*)
{
    std::cout << "in printV2(int*)\n";
}
*/

int main()
{
    // Pass by address for “optional” arguments

    // One of the more common uses for pass by address is to allow a function to accept an “optional” argument. This is easier to illustrate by example than to describe:
    {
        std::string title { "greet() with pointers" };
        std::cout << title << '\n';
        std::cout << std::string(title.length(), '=') << '\n';

        greet();                                // we don't know who's the user yet

        std::string joe { "Joe" };
        greet(&joe);                            // we know the user is Joe
    }
    std::cout << std::string(70, '-') << '\n';

    // In this program, the greet() function has one parameter that is passed by address and defaulted to nullptr.
    // Inside main(), we call this function twice. The first call, we don’t know who the user is, so we call greet() without an argument.
    // The name parameter defaults to nullptr, and the greet function substitutes in the name “guest”.
    // For the second call, we now have a valid user, so we call greet(&joe).
    // The name parameter receives the address of joe, and can use it to print the name “Joe”.

    // However, in many cases, function overloading is a better alternative to achieve the same result:
    {
        std::string title { "greet() overloaded" };
        std::cout << title << '\n';
        std::cout << std::string(title.length(), '=') << '\n';

        greetOverloaded();                      // we don't know who the user is yet

        std::string joe { "Joe" };
        greetOverloaded(joe);                   // We know the user isJoe
    }
    std::cout << std::string(70, '-') << '\n';

    // This has a number of advantages: we no longer have to worry about null dereferences, and we could pass in a string literal if we wanted.

    //---------------------------------------------------------------------------------------------

    // Changing what a pointer parameter points at
    
    // When we pass an address to a function, that address is copied from the argument into the pointer parameter (which is fine, because copying an address is fast).
    // Now consider the following program:
    {
        int x { 5 };
        int* ptr { &x };                        // ptr points to x

        std::cout << "ptr is " << (ptr ? "non-null" : "null") << '\n';

        nullify(ptr);

        std::cout << "ptr is " << (ptr ? "non-null" : "null") << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // As you can see, changing the address held by the pointer parameter had no impact on the address held by the argument (ptr still points at x).
    // When function nullify() is called, ptr2 receives a copy of the address passed in (in this case, the address held by ptr, which is the address of x).
    // When the function changes what ptr2 points at, this only affects the copy held by ptr2.

    // So what if we want to allow a function to change what a pointer argument points to?

    //---------------------------------------------------------------------------------------------

    // Pass by address… by reference?

    // Yup, it’s a thing. Just like we can pass a normal variable by reference, we can also pass pointers by reference.
    // Here’s the same program as above with ptr2 changed to be a reference to an address:
    {
        int x { 5 };
        int* ptr { &x };

        std::cout << "ptr is " << (ptr ? "non-null" : "null") << '\n';

        nullifyV2(ptr);

        std::cout << "ptr is " << (ptr ? "non-null" : "null") << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // Because refptr is now a reference to a pointer, when ptr is passed as an argument, refptr is bound to ptr.
    // This means any changes to refptr are made to ptr.

    //---------------------------------------------------------------------------------------------

    // Why using 0 or NULL is no longer preferred (optional)

    // In this subsection, we’ll explain why using 0 or NULL is no longer preferred.

    // The literal 0 can be interpreted as either an integer literal, or as a null pointer literal. In certain cases, it can be ambiguous which one we intend -- and in some of those cases, the compiler may assume we mean one when we mean the other -- with unintended consequences to the behavior of our program.

    // The definition of preprocessor macro NULL is not defined by the language standard. It can be defined as 0, 0L, ((void*)0), or something else entirely.
    // In lesson 10.10 -- Introduction to function overloading, we discussed that functions can be overloaded (multiple functions can have the same name, so long as they can be differentiated by the number or type of parameters).
    // The compiler can figure out which overloaded function you desire by the arguments passed in as part of the function call.
    // When using 0 or NULL, this can cause problems:
    {
        int x { 5 };
        int* ptr { &x };

        print(ptr);                                     // always calls print(int*) because ptr is type of int* (good)
        print(0);                                       // always calls print(int) because 0 is a integer literal

        /*print(NULL);                                    // this statement could do any of the following:*/
        // call print(int) (Visual Studio does this)
        // call print(int*)
	    // result in an ambiguous function call compilation error (gcc and Clang do this)

        print(nullptr);                                 // always calls print(int*)
    }
    std::cout << std::string(70, '-') << '\n';

    // When passing integer value 0 as a parameter, the compiler will prefer print(int) over print(int*).
    // This can lead to unexpected results when we intended print(int*) to be called with a null pointer argument.

    // In the case where NULL is defined as value 0, print(NULL) will also call print(int), not print(int*) like you might expect for a null pointer literal.
    // In cases where NULL is not defined as 0, other behavior might result, like a call to print(int*) or a compilation error.

    // Using nullptr removes this ambiguity (it will always call print(int*)), since nullptr will only match a pointer type.

    //---------------------------------------------------------------------------------------------

    // std::nullptr_t (optional)

    // Since nullptr can be differentiated from integer values in function overloads, it must have a different type.
    // So what type is nullptr? The answer is that nullptr has type std::nullptr_t (defined in header <cstddef>).
    // std::nullptr_t can only hold one value: nullptr! While this may seem kind of silly, it’s useful in one situation.
    // If we want to write a function that accepts only a nullptr literal argument, we can make the parameter a std::nullptr_t.
    {
        printV2(nullptr);                                 // calls print(std::nullptr_t)

        int x { 5 };
        int* ptr { &x };

        print(ptr);                                     // calls print(int*)

        ptr = nullptr;
        print(ptr);                                     // calls print(int*) since ptr has type of int*
    }
    std::cout << std::string(70, '-') << '\n';

    // In the above example, the function call print(nullptr) resolves to the function print(std::nullptr_t) over print(int*) because it doesn’t require a conversion.
}