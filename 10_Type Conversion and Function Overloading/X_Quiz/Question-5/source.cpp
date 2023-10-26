// Question V.

// 5a) Write a function template named add that allows the users to add 2 values of the same type. The following program should run:
#include <iostream>

// write your add function template here
template <typename T>
T add(T num1, T num2)
{
    return num1 + num2;
}


template <typename T>
T mult(T number, int multplier)
{
    return number * multplier;
}

template <typename T1, typename T2>
auto sub(T1 num1, T2 num2)
{
    return num1 - num2;
}

int main()
{
    // 5a) Write a function template named add that allows the users to add 2 values of the same type. The following program should run:

    // and it should produce
    // 5
    // 4.6
    {
        std::cout << add(2, 3) << '\n';
        std::cout << add(1.2, 3.4) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';


    // 5b) Write a function template named mult that allows the user to multiply one value of any type (first parameter) and an integer (second parameter).
    // The function should return the same type as the first parameter. The following program should run:
    // and produce the following output:
    // 6
    // 3.6
    {
        std::cout << mult(2, 3) << '\n';
        std::cout << mult(1.2, 3) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';


    // 5c) Write a function template named sub that allows the user to subtract two values of different types. The following program should run:
    // and produce the following output:
    // 1
    // 1.5
    // 2.5
    {
        std::cout << sub(3, 2) << '\n';
        std::cout << sub(3.5, 2) << '\n';
        std::cout << sub(4, 1.5) << '\n';
    }
}