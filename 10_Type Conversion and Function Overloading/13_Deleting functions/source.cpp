#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

// In cases where we have a function that we explicitly do not want to be callable, we can define that function as deleted by using the = delete specifier.
//  If the compiler matches a function call to a deleted function, compilation will be halted with a compile error.
void printInt(char) = delete;
void printInt(bool) = delete;

int main()
{
    // While printInt(5) is clearly okay, the other two calls to printInt() are more questionable.
    // With printInt('a'), the compiler will determine that it can promote 'a' to int value 97 in order to match the function call with the function definition.
    // And it will promote true to int value 1. And it will do so without complaint.
    {
        printInt(5);                            // okay: prints 5
        /*
        printInt('a');                          // prints 97!
        printInt(true);                         // printts 1!!
        */
    }

    // Let’s assume we don’t think it makes sense to call printInt() with a value of type char or bool. What can we do?

    //---------------------------------------------------------------------------------------------

    // Deleting a function using the = delete specifier

}