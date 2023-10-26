// Question II.

// Upgrade the following program using type aliases:

#include <iostream>

namespace constants
{
    inline constexpr double PI { 3.14159 };
}

double convertToRadians(double degrees)
{
    return degrees * constants::PI / 180;
}

// upgrade
using Degree = double;
using Radian = double;

int main()
{
    // old program
    {
        /*
        std::cout << "Enter a number of degrees: ";
        double degrees { };
        std::cin >> degrees;

        double radians { convertToRadians(degrees) };
        std::cout << degrees << " degrees is " << radians << " radians." << '\n';
        */
    }


    // new program
    {
        std::cout << "Enter a number of degrees: ";
        Degree degrees { };
        std::cin >> degrees;

        Radian radians { convertToRadians(degrees) };
        std::cout << degrees << " degrees is " << radians << " radians." << '\n';
    }
}