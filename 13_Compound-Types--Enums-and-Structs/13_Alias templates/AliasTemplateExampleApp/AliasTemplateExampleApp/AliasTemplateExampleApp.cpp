#include <iostream>

template <typename T>
struct Pair
{
    T first{ };
    T second{ };
};

template <typename T>
void printPair(const Pair<T>& pair)
{
    std::cout << "first:  " << pair.first << '\n';
    std::cout << "second: " << pair.second << '\n';
}

// In other cases, we might want a type alias for a template class where not all of the template arguments are defined as part of the alias (and will instead be provided by the user of the type alias).
// To do this, we can define an alias template, which is a template that can be used to instantiate type aliases.
// Just like type aliases do not define distinct types, alias templates do not define distinct types.

// here's our alias template
// Alias template must be defined in the global scope
template <typename T>
using Coord = Pair<T>;      // Coord is an alias for Pair<T>

int main()
{
    // Creating a type alias for a class template where all template arguments are explicitly specified works just like a normal type alias:
    {
        using Point = Pair<int>;                            // create normal type alias
        Point p1{ .first = 1, .second = 2 };                // compiler replaces this with Pair<int>

        printPair(p1);
    }
    std::cout << std::string(70, '=') << '\n';
    // Such aliases can defined locally (e.g. inside a function) or globally.

    //---------------------------------------------------------------------------------------------

    // Alias templates
    {
        Coord<int> p1{ .first = 1, .second = 2 };           // Pre C++-20: We must explicitly specify all type template argument
        Coord p2{ .first = 3, .second = 4 };                // In C++20, we can use alias template deduction to deduce the template arguments in cases where CTAD works

        std::cout << p1.first << " => " << p1.second << '\n';

        printPair(p2);
    }
}
