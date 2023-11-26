#include <iostream>
#include <string>

std::string returnByValue();                                    // (expensive)

// Return by reference
std::string& returnByReference();                               // return a reference to an existing std::string (cheap)
const std::string& returnByReferenceToConst();                  // return a const reference to an existing std::string (cheap)

//-------------------------------------------------------------------------------------------------

// return a const reference
const std::string& getProgramName()
{
    static const std::string s_programName { "Calculator" };     // has static duration, destroyed at end of program

    return s_programName;
}

const int& getNextId()
{
    static int s_id { 0 };
    s_id++;

    return s_id;
}

int main()
{
    {
        std::cout << "This program is named " << getProgramName();
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // The object being returned by reference must exist after the function returns

    // Using return by reference has one major caveat: the programmer must be sure that the object being referenced outlives the function returning the reference.
    // Otherwise, the reference being returned will be left dangling (referencing an object that has been destroyed), and use of that reference will result in undefined behavior.

    // In the program above, because s_programName has static duration, s_programName will exist until the end of the program.
    // When main() accesses the returned reference, it is actually accessing s_programName, which is fine, because s_programName won’t be destroyed until later.

    //---------------------------------------------------------------------------------------------

    // Assigning/initializing a normal variable with a returned reference makes a copy

    // If a function returns a reference, and that reference is used to initialize or assign to a non-reference variable,
    // the return value will be copied (as if it had been returned by value).
    {
        const int id1 { getNextId() };                  // id1 is a normal variable now and receives a copy of the value returned by reference from getNextId()
        const int id2 { getNextId() };                  // id2 is a normal variable now and receives a copy of the value returned by reference from getNextId()

        std::cout << "ID #1: " << id1 << '\n';
        std::cout << "ID #2: " << id2 << '\n';
    }
    std::cout << std::string(70, '-') << '\n';
}