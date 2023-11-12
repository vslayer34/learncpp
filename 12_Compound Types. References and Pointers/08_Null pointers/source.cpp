#include <iostream>
#include <cstddef>              // to use NULL

void someFunction(int* ptr)
{
    std::cout << "someFunction is called" << '\n';
}

int main()
{
    {
        int x { 5 };
        std::cout << x << '\n';                 // print the value of variable x

        int* ptr { &x };                        // ptr holds the address of x
        std::cout << *ptr << '\n';              // use dereference operator to print the value of the object at the address the pointer is holding (x's address)
    }
    std::cout << std::string(70, '-') << '\n';

    // In the prior lesson, we also noted that pointers do not need to point to anything.
    // In this lesson, we’ll explore such pointers (and the various implications of pointing to nothing) further.

    //---------------------------------------------------------------------------------------------

    // Null pointers

    // Besides a memory address, there is one additional value that a pointer can hold: a null value.
    // A null value (often shortened to null) is a special value that means something has no value.
    // When a pointer is holding a null value, it means the pointer is not pointing at anything.
    // Such a pointer is called a null pointer.

    // The easiest way to create a null pointer is to use value initialization:
    {
        int* ptr { };                           // ptr is now a null pointer, and isn't holding any address
    }
    std::cout << std::string(70, '-') << '\n';

    // Because we can use assignment to change what a pointer is pointing at, a pointer that is initially set to null can later be changed to point at a valid object:

    {
        int* ptr { };                           // ptr is now a null pointer, and isn't holding any address

        int x { 5 };
        ptr = &x;                               // ptr is now pointing to the object x address

        std::cout << *ptr << '\n';              // print the value of x through dereferenced ptr
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // The nullptr keyword

    // Much like the keywords true and false represent Boolean literal values, the nullptr keyword represents a null pointer literal.
    // We can use nullptr to explicitly initialize or assign a pointer a null value.
    {
        int* ptr { nullptr };                   // can use nullptr to initialize a pointer to be a null pointer

        int value { 5 };
        int* ptr2 { &value };                   // ptr2 is a valid pointer
        ptr2 = nullptr;                         // can assign nullptr to make the pointer a null pointer

        someFunction(ptr);                      // we can also pass nullptr to a function that has a pointer as a parameter
    }
    std::cout << std::string(70, '-') << '\n';

    // Use nullptr when you need a null pointer literal for initialization, assignment, or passing a null pointer to a function.

    //---------------------------------------------------------------------------------------------

    // Dereferencing a null pointer results in undefined behavior

    // Much like dereferencing a dangling (or wild) pointer leads to undefined behavior, dereferencing a null pointer also leads to undefined behavior.
    // In most cases, it will crash your application.
    /*
    {
        int* ptr { };                           // Create a null pointer
        std::cout << *ptr << '\n';              // Dereference a null pointer
    }
    std::cout << std::string(70, '-') << '\n';
    */
    
    //---------------------------------------------------------------------------------------------

    // Checking for null pointers

    // Much like we can use a conditional to test Boolean values for true or false, we can use a conditional to test whether a pointer has value nullptr or not:
    {
        int x { 5 };
        int* ptr { &x };

        if (ptr == nullptr)                     // explicit test for equivalence
        {
            std::cout << "ptr is null" << '\n';
        }
        else
        {
            std::cout << "ptr is non-null" << '\n';
        }

        int* nullPointer { };
        std::cout << "nullptr is " << (nullPointer == nullptr ? "null pointer\n" : "non-null pointer\n");          // explicit test for equivalence
    }
    std::cout << std::string(70, '-') << '\n';

    // In lesson 4.9 -- Boolean values, we noted that integral values will implicitly convert into Boolean values: an integral value of 0 converts to Boolean value false, and any other integral value converts to Boolean value true.

    // Similarly, pointers will also implicitly convert to Boolean values: a null pointer converts to Boolean value false,
    // and a non-null pointer converts to Boolean value true.
    // This allows us to skip explicitly testing for nullptr and just use the implicit conversion to Boolean to test whether a pointer is a null pointer.
    // The following program is equivalent to the prior one:
    {
        int x { 5 };
        int *ptr { &x };

        // pointers convert to boolean false if they are null
        // and true if they are non-null
        if (ptr)            // implicit conversion to boolean
        {
            std::cout << "ptr is non-null" << '\n';
        }
        else
        {
            std::cout << "ptr is null" << '\n';
        }

        int* nullPointer { nullptr };
        std::cout << "nullPointer is " << (nullPointer ? "non-null\n" : "null\n");
    }
    std::cout << std::string(70, '-') << '\n';

    // Conditionals can only be used to differentiate null pointers from non-null pointers.
    // There is no convenient way to determine whether a non-null pointer is pointing to a valid object or dangling (pointing to an invalid object).

    //---------------------------------------------------------------------------------------------

    // Use nullptr to avoid dangling pointers

    // Above, we mentioned that dereferencing a pointer that is either null or dangling will result in undefined behavior.
    // Therefore, we need to ensure our code does not do either of these things.

    // We can easily avoid dereferencing a null pointer by using a conditional to ensure a pointer is non-null before trying to dereference it:
    {
        int* ptr { };
        // assume ptr is a pointer that may or may not be a null pointer

        if (ptr)        // if ptr is not a null pointer
        {
            std::cout << *ptr << '\n';
        }
        else
        {
            // do something else that doesn't involve dereferencing ptr (print an error message, do nothing at all, etc...)
            std::cout << "The pointer is null" << '\n';
        }
    }
    std::cout << std::string(70, '-') << '\n';

    // But what about dangling pointers? Because there is no way to detect whether a pointer is dangling.
    // We need to avoid having any dangling pointers in our program in the first place.
    // We do that by ensuring that any pointer that is not pointing at a valid object is set to nullptr.

    // That way, before dereferencing a pointer, we only need to test whether it is null -- if it is non-null, we assume the pointer is not dangling.

    // A pointer should either hold the address of a valid object, or be set to nullptr.
    // That way we only need to test pointers for null, and can assume any non-null pointer is valid.

    //-----------------------------------------------------------------------------------------

    // Legacy null pointer literals: 0 and NULL

    // In older code, you may see two other literal values used instead of nullptr.
    // The first is the literal 0. In the context of a pointer, the literal 0 is specially defined to mean a null value,
    // and is the only time you can assign an integral literal to a pointer.

    {
        float* ptr { 0 };                   // this pointer is now a null pointer

        float* ptr2;                        // ptr2 is uninitialized
        ptr2 = 0;                           // ptr2 is now a null pointer
    }

    // Additionally, there is a preprocessor macro named NULL (defined in the <cstddef> header).
    // This macro is inherited from C, where it is commonly used to indicate a null pointer.
    {
        double* ptr { NULL };               // ptr is now a null pointer

        double* ptr2;                       // ptr2 is uninitialized
        ptr2 = NULL;                        // ptr2 is now a null pointer
    }

    // Both 0 and NULL should be avoided in modern C++ (use nullptr instead). We discuss why in lesson 12.11 -- Pass by address (part 2).

    //---------------------------------------------------------------------------------------------

    // Favor references over pointers whenever possible

    // Pointers and references both give us the ability to access some other object indirectly.
    // Pointers have the additional abilities of being able to change what they are pointing at, and to be pointed at null.
    // However, these pointer abilities are also inherently dangerous:
    // A null pointer runs the risk of being dereferenced, and the ability to change what a pointer is pointing at can make creating dangling pointers easier:
    {
        int* ptr { };

        {
            int x { 5 };
            ptr = &x;
            // set the pointer to an object that is gonna be destroyed after existing this scope
        }
        // ptr is now a dangling pointer
    }

    // Since references can’t be bound to null, we don’t have to worry about null references.
    // And because references must be bound to a valid object upon creation and then can not be reseated, dangling references are harder to create.
    
    // Because they are safer, references should be favored over pointers, unless the additional capabilities provided by pointers are required.

    //---------------------------------------------------------------------------------------------

    // Quiz Time

    // Question #1
    // Can we determine whether a pointer is a null pointer or not? If so, how?

    //// we can use conditional if to check for the pointer if it's null or not before using it

    // Can we determine whether a non-null pointer is valid or dangling? If so, how?

    //// We can't determine for sure if the pointer is dangling or not
    //// so we must set it to nullpointer once the object it reference it is destroyed

    // Question #2
    // For each subitem, answer whether the action described will result in behavior that is:
    // predictable
    // undefined
    // or possibly undefined.
    // If the answer is “possibly undefined”, clarify when.

    // 2a) Assigning a new address to a non-const pointer
    //// predictable

    // 2b) Assigning nullptr to a pointer
    //// predictable

    // 2c) Dereferencing a pointer to a valid object
    //// predictable

    // 2d) Dereferencing a dangling pointer
    //// undefined

    // 2e) Dereferencing a null pointer
    //// undefined

    // 2f) Dereferencing a non-null pointer
    //// Possibly undefined
    //// It may be a dangling pointer

    // Question #3
    // Why should we set pointers that aren’t pointing to a valid object to ‘nullptr’?
    //// because we can't determine the type of dangling pointers
    //// so we must assign it to nullptr when it's pointed object is destroyed to prevent undefined behaviour
}