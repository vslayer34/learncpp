#include <iostream>

/*
// A default argument is a default value provided for a function parameter. For example:
void print(int x, int y = 4)    // 4 is a default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
*/

// A function can have multiple parameters with default arguments:

void print(int x = 10, int y = 20, int z = 30)
{
    std::cout << "values: " << x << ' ' << y << ' ' << z << '\n';
}

int main()
{
    {
        // print(1, 2);                        // y will use user-supplied argument 2
        std::cout << '\n';
        // print(3);                           // y will use default argument 4, as if we had called print(3, 4)
    }
    std::cout << std::string(70, '-') << '\n';


    {
        print(1, 2, 3);                         // all explicit arguments
        print(1, 2);                            // rightmost argument defaulted
        print(1);                               // two rightmost arguments defaulted
        print();                                // all arguments defaulted
    }
}