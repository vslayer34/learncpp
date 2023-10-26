// Question III.

// 3a) What is the output of this program and why?
#include <iostream>


void print()
{
    std::cout << "void!" << '\n';
}


void print(int x = 0)
{
    std::cout << "int: " << x << '\n';
}

void print(double x)
{
    std::cout << "double: " << x << '\n';
}


int main()
{
    {
        short s { 5 };
        print(s);
    }
    std::cout << std::string(70, '-') << '\n';
    // it prints 5 because short can be numetricly promoted to int and call the print(int) overload


    // 3b) Why won’t the following compile?
    {
        print(5.0f);
        /*print();*/
    }
    std::cout << std::string(70, '-') << '\n';
    // The compiler won't know if the code calls print() the void one and the print(x = 0) with the default parameter

    
    // 3c) Why won’t the following compile?

    // The compiler would have to convert the number from int to long or double but it won't be able to determine if its long or double
}