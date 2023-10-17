#include <iostream>
#include <string>                       // for std::string
#include <vector>                       // for std::vector
#include <utility>                      // for std::pair


using Distance = double;                        // define Distance as an alias for type double

bool hasDuplicate(std::vector<std::pair<std::string, int>> pairList)
{
    // do some stuff

    return false;
}

int main()
{
    // In C++, using is a keyword that creates an alias for an existing data type.
    // To create such a type alias, we use the using keyword, followed by a name for the type alias.
    // followed by an equals sign and an existing data type. For example:

    {        
        Distance milesToDistance { 3.4 };               // defines a variable of type double
    }

    // When the compiler encounters a type alias name, it will substitute in the aliased type. For example:

    {
        Distance milesToDistinsation { 3.4 };           // defines a variable of type double
        std::cout << milesToDistinsation << '\n';       // prints a double value
    }

    //-------------------------------------------------------------------------------------------------

    // Type aliases are not distinct types

    // An alias does not actually define a new, distinct type (one that is considered separate from other types) -- it just introduces a new identifier for an existing type.
    // A type alias is completely interchangeable with the aliased type.

    // This allows us to do things that are syntactically valid but semantically meaningless. For example:

    {
        using Miles = long;                             // define Miles as an alias for type long
        using Speed = long;                             // define Speed as an alias for type long

        Miles distance { 5 };                           // distance is actually just a long
        Speed mhz { 3200 };                             // mhz is actually just a long

        // The following is syntactically valid (but semantically meaningless)
        distance = mhz;
    }

    //-------------------------------------------------------------------------------------------------------

    // The scope of a type alias
    
    // Because scope is a property of an identifier, type alias identifiers follow the same scoping rules as variable identifiers:
    // a type alias defined inside a block has block scope and is usable only within that block.
    // whereas a type alias defined in the global namespace has global scope and is usable to the end of the file.
    // In the above example, Miles and Speed are only usable in the main() function.

    // If you need to use one or more type aliases across multiple files,
    // they can be defined in a header file and #included into any code files that needs to use the definition:

    //---------------------------------------------------------------------------------------------------------

    // Typedefs

    // A typedef (which is short for “type definition”) is an older way of creating an alias for a type. To create a typedef alias, we use the typedef keyword:

    {
        // The following aliases are identical
        typedef long Miles;
        using Miles = long;
    }

    // The syntax for typedefs can get ugly with more complex types.
    // For example, here is a hard-to-read typedef, along with an equivalent (and slightly easier to read) type alias:

    {
        typedef int (*FcnType)(double, char);               // FcnType hard to find
        using FcnType = int(*)(double, char);               // FcnType easier to find
    }

    // In the above typedef definition, the name of the new type (FcnType) is buried in the middle of the definition.
    // Whereas in the type alias, the name of the new type and the rest of the definition are separated by an equals sign.

    //------------------------------------------------------------------------------------------------------------

    // Using type aliases to make complex types easier to read

    // Although we have only dealt with simple data types so far, in advanced C++, types can be complicated and lengthy to manually enter on your keyboard.
    // For example, you might see a function and variable defined like this:

    {
        std::vector<std::pair<std::string, int>> pairList;
    }

    // Typing std::vector<std::pair<std::string, int>> everywhere you need to use that type is cumbersome.
    // it is easy to make a typing mistake. It’s much easier to use a type alias:

    {
        using VectPairSI = std::vector<std::pair<std::string, int>>;

        VectPairSI pairList;                                    // instantiate a VectPairSI variable
    }

    
}