#include <iostream>

template <typename T>
struct Pair
{
    T first{ };
    T second{ };
};


template <typename T>
constexpr T getMax(Pair<T> pair)
{
    return pair.first < pair.second ? pair.second : pair.first;
}
// The max() function template is pretty straightforward.Because we want to pass in a Pair<T>, we need the compiler to understand what T is.
// Therefore, we need to start our function with a template parameter declaration that defines template type T.
// We can then use T as both our return type, and as the template type for Pair<T>.

int main()
{
    {
        Pair<int> p1{ .first = 5, .second = 6 };
        std::cout << p1.first << " < " << p1.second << '\n';

        Pair<double> p2{ .first = 1.2, .second = 3.4 };
        std::cout << p2.first << " < " << p2.second << '\n';

        Pair<double> p3{ .first = 7.8, .second = 9.0 };
        std::cout << p3.first << " < " << p3.second << '\n';
    }
    std::cout << std::string(70, '=') << '\n';

    {
        Pair<int> p1{ .first = 5, .second = 6 };
        std::cout << getMax(p1) << " is larger." << '\n';

        Pair<double> p2{ .first = 1.2, .second = 3.4 };
        std::cout << getMax(p2) << " is largere." << '\n';
    }
}
