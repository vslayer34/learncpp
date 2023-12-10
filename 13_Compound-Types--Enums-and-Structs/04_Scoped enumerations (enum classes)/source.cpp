#include <iostream>
#include <utility>          // for std::to_underlying() (C++23)

// To make a scoped enumeration, we use the keywords enum class.
// The rest of the scoped enumeration definition is the same as an unscoped enumeration definition.
// Here’s an example:
enum class Color        // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
{
    Red,                // Red is considered part of Color's scope region
    Blue,
    Black
};

enum class Fruit
{
    Banana,             // Banana is considered part of Fruit's scope region
    Apple
};


enum class AnimalOrigins
{
    Chicken,
    Dog,
    Cat,
    Elephant,
    Duck,
    Snake,
    maxAnimals
};


// Overload the unary + operator to convert Animals to the underlying type
// adapted from https://stackoverflow.com/a/42198760, thanks to Pixelchemist for the idea
constexpr auto operator+(AnimalOrigins animal) noexcept
{
    return static_cast<std::underlying_type_t<AnimalOrigins>>(animal);
}

// using enum statements C++20
// Introduced in C++20, a using enum statement imports all of the enumerators from an enum into the current scope.
// When used with an enum class type, this allows us to access the enum class enumerators without having to prefix each with the name of the enum class.
// This can be useful in cases where we would otherwise have many identical, repeated prefixes, such as within a switch statement:
constexpr std::string_view getColor(Color color)
{
    // using enum Color;                   // bring all Color enumerators into current scope (C++20)
    // We can now access the enumerators of Color without using a Color:: prefix

    switch (color)
    {
        case Color::Black:     return "black";
        case Color::Red:       return "red";
        case Color::Blue:      return "blue";
        default:                return "????";
    }
}

enum class Animal
{
    Pig,
    Chicken,
    Goat,
    Cat,
    Dog,
    Duck
};

constexpr std::string_view getAnimalName(Animal animal)
{
    switch (animal)
    {
        case Animal::Pig:           return "pig";
        case Animal::Chicken:       return "chicken";
        case Animal::Goat:          return "goat";
        case Animal::Cat:           return "cat";
        case Animal::Dog:           return "dog";
        case Animal::Duck:          return "duck";
        default:                    return "please enter one of those animals { Pig, Chicken, Goat, Cat, Dog, Duck }";
    }
}

void printNumberOfLegs(Animal animal)
{
    int legsNumber;
    switch (animal)
    {
        case Animal::Pig:
        case Animal::Goat:
        case Animal::Cat:
        case Animal::Dog:
            legsNumber = 4;
            break;
        
        case Animal::Chicken:
        case Animal::Duck:
            legsNumber = 2;
            break;

        default:
            legsNumber = 0;
            break;
    }
    
    if (legsNumber != 0)
    {
        std::cout << "A " << getAnimalName(animal) << " has " << legsNumber << " legs." << '\n';
    }
    else
    {
        std::cout << "please enter one of those animals { Pig, Chicken, Goat, Cat, Dog, Duck }" << '\n';
    }
}

int main()
{
    // Scoped enumerations work similarly to unscoped enumerations (13.2 -- Unscoped enumerations), but have two primary differences:
    // They are strongly typed (they won’t implicitly convert to integers) and strongly scoped (the enumerators are only placed into the scope region of the enumeration).

    // Scoped enumerations define their own scope regions
    {
        /*
        * std::cout << Red << '\n';                              // compile error: red not defined in this scope region
        * std::cout << Color::Red << '\n';                       // compile error: std::cout doesn't know how to print this (will not implicitly convert to int)
        */
        
        Color color { Color::Blue };                            // Okay
    }

    // Because scoped enumerations offer their own implicit namespacing for enumerators.
    // There’s no need to put scoped enumerations inside another scope region (such as a namespace), unless there’s some other compelling reason to do so, as it would be redundant.

    //---------------------------------------------------------------------------------------------

    // Scoped enumerations don’t implicitly convert to integers

    // Unlike non-scoped enumerators, scoped enumerators won’t implicitly convert to integers.
    // In most cases, this is a good thing because it rarely makes sense to do so, and it helps prevent semantic errors.
    // Such as comparing enumerators from different enumerations, or expressions such as red + 5.
    {
        enum class Color
        {
            Red,
            Blue
        };

        Color shirt { Color::Red };

        if (shirt == Color::Red)        // this Color to Color comparison is okay
        {
            std::cout << "This shirt is red." << '\n';
        }
        else if (shirt == Color::Blue)
        {
            std::cout << "This shirt is Blue." << '\n';
        }
    }

    // There are occasionally cases where it is useful to be able to treat a scoped enumerator as an integral value.
    // In these cases, you can explicitly convert a scoped enumerator to an integer by using a static_cast.
    // A better choice in C++23 is to use std::to_underlying() (defined in the <utility> header), which converts an enumerator to a value of the underlying type of the enumeration.
    {
        enum class Color
        {
            Red,
            Blue
        };

        Color color { Color::Blue };

        /* std::cout << color << '\n'; */                               // won't work, because there's no implicit conversion to int
        std::cout << static_cast<int>(color) << '\n';                   // explicit conversion to int would print 1
        std::cout << std::underlying_type_t<Color>(color) << '\n';      // convert to underlying type, will print 1 (C++23)
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Easing the conversion of scoped enumerators to integers (advanced) 
    // If you find yourself in the situation where it would be useful to make conversion of scoped enumerators to integers easier.
    // A useful hack is to overload the unary operator+ to perform this conversion.
    // We haven’t explained how this works yet, so consider it magic for now:
    {
        std::cout << +AnimalOrigins::Elephant << '\n';                         // convert Animals::elephant to an integer using unary operator+
    }

    // This method prevents unintended implicit conversions to an integral type, but provides a convenient way to explicitly request such conversions as needed.

    //---------------------------------------------------------------------------------------------

    // using enum statements {{C++20}}
    {
        Color myShirt { Color::Black };

        std::cout << "My shirt's color is " << getColor(myShirt) << '\n';
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Quiz: Question #1
    // Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck.
    // Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for that animal as a std::string_view (or std::string if you’re using C++14).
    // Write another function named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on.
    // Make sure both functions have a default case that prints an error message.
    // Call printNumberOfLegs() from main() with a cat and a chicken. Your output should look like this:
    /***********************
    * A cat has 4 legs.
    * A chicken has 2 legs.
    ***********************/
    {
        printNumberOfLegs(Animal::Cat);
        printNumberOfLegs(Animal::Chicken);
    }
}