#include <iostream>
#include <bitset>

// define a new unscoped enumeration named Color
// this enum is defined in the global namespace
enum Color
{
    // so red for example is put into the global namespace
    // Here are the enumerators
    // These symbolic constants define all possible values this type can hold
    // Each enumerator is seperated by comma (,) not a semicolon (;)
    red,
    green,
    blue
};  // the enum definection must end with semicolon (;)

enum Pet
{
    Cat,
    Dog,
    Pig,
    Whale
};

// Because enumerators are descriptive, they are useful for enhancing code documentation and readability.
// Enumerated types are best used when you have a smallish set of related constants, and objects only need to hold one of those values at a time.

// Commonly defined enumerations include days of the week, the cardinal directions, and the suits in a deck of cards:
enum DaysOfWeek
{
    Sunday,
    Monday,
    Thuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

// One option is to prefix each enumerator with the name of the enumeration itself
enum CardinalDirections
{
    CardinalDirections_North,
    CardinalDirections_East,
    CardinalDirections_South,
    CardinalDirections_West
};

// A better option is to put the enumerated type inside something that provides a separate scope region, such as a namespace
namespace CardSuit
{
    enum CardSuit
    {
        Clubs,
        Diamonds,
        Hearts,
        Spades
    };
}

enum ItemType
{
    Sword,
    Torch,
    Potion
};

// Enumerated types can also make for useful function parameters when the user needs to make a choice between two or more options:
enum SortOrder
{
    Alphabetical,
    AlphabeticalReverse,
    Numerical
};

enum State
{
    IsHungry,
    IsSad,
    IsMad,
    IsHappy,
    IsLaughing,
    IsASleep,
    IsDead,
    IsCrying
};

// Question #1
// Define an enumerated type named MonsterType to choose between the following monster races: orc, goblin, troll, ogre, and skeleton.
namespace MonsterType
{
    enum MonsterType
    {
        Orc,
        Goblin,
        Troll,
        Ogre,
        Skeleton
    };
}

// Put the MonsterType enumeration inside a namespace. Then, create a main() function and instantiate a troll. The program should compile.

void sortData(SortOrder order)
{
    switch (order)
    {
    case SortOrder::Alphabetical:
        // sort data in forward alphabetical order
        break;
    
    case SortOrder::AlphabeticalReverse:
        // sort data in backward alphabetical order
        break;
    
    case SortOrder::Numerical:
        // sord data numericaly
        break;
    }
}

int main()
{
    // Unscoped enumerations
    
    {
        // Define a few variable of enumerated type Color
        Color apple { red };                        // my apple is red
        Color shirt { green };                      // my shirt is green
        Color cup { blue };                         // my cup is blue

        /*
        * Color socks { white };                    // error: white is not an enumerator of Color
        * Color hat { 2 };                          // error: 2 is not an enumerator of Color
        */
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Enumerated types are distinct types
    // Because enumerated types are distinct, enumerators defined as part of one enumerated type can’t be used with objects of another enumerated type:
    {
        /*
        * Pet myPet { red };                        // compile error: red is not an enumerator of Pet
        * Color shirt { Pig };                      // compile error: Pig is not an enumerator of Color
        */
    }

    //---------------------------------------------------------------------------------------------

    // Putting enumerations to use

    // Enumerated types can be put to good use in games, to identify different types of items, or monsters, or terrain.
    // Basically, anything that is a small set of related objects.
    {
        ItemType holding { Torch };
    }

    // Enums can also be used to define a collection of related bit flag positions for use with std::bitset:
    {
        std::bitset<8> me { };
        me.set(State::IsHappy);
        me.set(State::IsLaughing);

        std::cout << std::boolalpha;                // print booleans as true/false

        // Query a few states (we use the any() function to see if any bits remain set)
        std::cout << "Am I happy?" << me.test(State::IsHappy) << '\n';
        std::cout << "Am I laughing?" << me.test(State::IsLaughing) << '\n';
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // The scope of unscoped enumerations

    // Unscoped enumerations are named such because they put their enumerator names into the same scope as the enumeration definition itself (as opposed to creating a new scope region like a namespace does).
    // For example, given this program:
    {
        Color myApple { red };                      // red is in the global scope like the enum decleration
    }

    // The Color enumeration is defined in the global scope. Therefore, all the enumeration names (red, green, and blue) also go into the global scope.
    // This pollutes the global scope and significantly raises the chance of naming collisions.

    // One consequence of this is that an enumerator name can’t be used in multiple enumerations within the same scope

    // to avoid enumerations naming collisions
    // One option is to prefix each enumerator with the name of the enumeration itself
    // A better option is to put the enumerated type inside something that provides a separate scope region, such as a namespace

    //---------------------------------------------------------------------------------------------

    // Comparing against enumerators
    {
        // We can use the equality operators (operator== and operator!=) to test whether an enumeration has the value of a particular enumerator or not.
        {
            Color shirt { Color::blue };

            if (shirt == Color::blue)       // if the shirt is blue
            {
                std::cout << "Your shirt is blue." << std::endl;
            }
            else
            {
                std::cout << "Your shirt isn't blue!" << std::endl;
            }
        }
        std::cout << std::string(70, '=') << std::endl;

        // In the above example, we use an if-statement to test whether shirt is equal to the enumerator blue.
        // This gives us a way to conditionalize our program’s behavior based on what enumerator our enumeration is holding.
    }

    {
        MonsterType::MonsterType troll { MonsterType::Troll };
    }
}