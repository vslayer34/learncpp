#include <iostream>
#include <cstdint>                      // for std::int8_t

// When we define an enumerator, each enumerator is automatically assigned an integer value based on its position in the enumerator list.
// By default, the first enumerator is assigned the integral value 0, and each subsequent enumerator has a value one greater than the previous enumerator:
enum Color
{
    Black,                              // assigned 0
    Red,                                // assigned 1
    Blue,                               // assigned 2
    Green,                              // assigned 3
    White,                              // assigned 4
    Cyan,                               // assigned 5
    Yellow,                             // assigned 6
    Magenta                             // assigned 7
};

// It is possible to explicitly define the value of enumerators.
// These integral values can be positive or negative, and can share the same value as other enumerators.
// Any non-defined enumerators are given a value one greater than the previous enumerator.
enum Animal
{
    Cat = -3,
    Dog,                                // assigned -2
    Pig,                                // assigned -1
    Horse = 5,
    Giraffe = 5,                        // Shares the same value with Horse
    Chicken                             // assigned 6
};
// Note in this case, horse and giraffe have been given the same value.
// When this happens, the enumerators become non-distinct -- essentially, horse and giraffe are interchangeable.
// Although C++ allows it, assigning the same value to two enumerators in the same enumeration should generally be avoided.

// As of C++20, C++ doesn’t come with any easy way to do this, so we’ll have to find a solution ourselves.
// Fortunately, that’s not very difficult.
// The typical way to do this is to write a function that takes an enumerated type as a parameter and then outputs the corresponding string (or returns the string to the caller).

// The typical way to do this is to test our enumeration against every possible enumerator:
constexpr std::string_view getColor(Color color)
{
    switch (color)
    {
        case Color::Black:      return "Black";
        case Color::Red:        return "Red";
        case Color::Blue:       return "Blue";
        case Color::Green:      return "Green";
        case Color::White:      return "White";
        case Color::Cyan:       return "Cyan";
        case Color::Yellow:     return "Yellow";
        case Color::Magenta:    return "Magenta";
        default:                return "????";
    }
}

// Although the above example functions well, we still have to remember the name of the function we created to get the enumerator name.
// While this usually isn’t too burdensome, it can become more problematic if you have lots of enumerations.
// Using operator overloading (a capability similar to function overloading), we can actually teach operator<< how to print the value of a program-defined enumeration!
// We haven’t explained how this works yet, so consider it a bit of magic for now:

// std::ostream is the type of std::cout
// The return type and parameter type are references (to prevent copies from being made)!
std::ostream& operator<<(std::ostream& out, Color color)
{
    switch (color)
    {
        case Color::Black:      return out << "Black";
        case Color::Red:        return out << "Red";
        case Color::Blue:       return out << "Blue";
        case Color::Green:      return out << "Green";
        case Color::White:      return out << "White";
        case Color::Cyan:       return out << "Cyan";
        case Color::Yellow:     return out << "Yellow";
        case Color::Magenta:    return out << "Magenta";
        default:                return out << "????";
    }
}

//-------------------------------------------------------------------------------------------------

// Enumeration size and underlying type (base) 
// It is possible to specify a different underlying type.
// For example, if you are working in some bandwidth-sensitive context (e.g. sending data over a network) you may want to specify a smaller type:
enum Vehicle : std::int8_t
{
    Car,
    Plane,
    Boat
};

enum Pet : int
{
    Tiger,
    Retriver,
    Pigglet,
    Whale
};

// Similar to how we were able to teach operator<< to output an enum type above, we can also teach operator>> how to input an enum type:

std::istream& operator>>(std::istream& in, Pet pet)
{
    int input { };
    in >> input;                                    // input an integer

    pet = static_cast<Pet>(input);
    return in;
}

int main()
{
    {
        Color shirt { Color::Blue };                // This actually stores the integral value of 2
    }

    //---------------------------------------------------------------------------------------------

    // Unscoped enumerations will implicitly convert to integral values
    // Consider the following program:
    {
        Color shirt { Color::Red };
        std::cout << "My shirt color is " << shirt << '\n';
    }
    std::cout << std::string(70, '=') << '\n';

    // Since enumerated types hold integral values, as you might expect, this prints:
    // My shirt color is 1

    //---------------------------------------------------------------------------------------------

    // Enumeration size and underlying type (base) 
    {
        Vehicle car { Vehicle::Car };
        std::cout << "Size of enumartor Car is " << sizeof(car) << " byte" << '\n';
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Integer to unscoped enumerator conversion
    // While the compiler will implicitly convert unscoped enumerators to an integer, it will not implicitly convert an integer to an unscoped enumerator.
    // The following will produce a compiler error:
    {
        /*
        * Pet pet { 2 };                            // compile error: integer value 2 won't implicitly convert to a Pet
        * pet = 3;                                  // compile error: integer value 3 won't implicitly convert to a Pet
        */
    }

    // There are two ways to work around this.
    // First, you can force the compiler to convert an integer to an unscoped enumerator using static_cast:
    {
        Pet pet { static_cast<Pet>(2) };            // Convert integer 2 to Pet
        pet = static_cast<Pet>(3);                  // our pet evolved to a whale!

        // Second, in C++17, if an unscoped enumeration has a specified base.
        // Then the compiler will allow you to list initialize an unscoped enumeration using an integral value:
        /*
        * Pet pet1 { 2 };                           // ok: can brace initialize with integer
        * Pet pet2 ( 2 );                           // compile error: cannot direct initialize with integer
        * Pet pet3 = 2;                             // compile error: cannot copy initialize with integer
        * pet1 = 3;                                 // compile error: cannot assign with integer
        */
    }

    //---------------------------------------------------------------------------------------------

    // Unscoped enumerator input
    // Because Pet is a program-defined type, the language doesn’t know how to input a Pet using std::cin:
    {
        /*
        * Pet pet { Pet::Pig };
        * std::cin >> pet;
        */
    }

    // To work around this, we can read in an integer, and use static_cast to convert the integer to an enumerator of the appropriate enumerated type:
    {
        std::cout << "Please enter a pet [ 0: cat, 1: dog, 2: pig, 3: whale ]";

        int input { };
        std::cin >> input;                                  // the user input an integer

        Pet pet { static_cast<Pet>(input) };                // static_cast the integer to Pet
    }

}