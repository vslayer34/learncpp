#include <iostream>

int foo()
{
    return 5;
}

int& max(int &x, int &y)
{
    return (x > y) ? x : y;
}

void sort2(int& smallerNum, int& largestNum)
{
    if (smallerNum < largestNum)
    {
        return;
    }

    int temp = smallerNum;
    smallerNum = largestNum;
    largestNum = temp;
}

int main()
{
    // Question I
    // For each of the following expressions on the right side of operator <<, indicate whether the expression is an lvalue or rvalue:
    {
        std::cout << 5;                                             // rvalue
    }

    {
        int x { 5 };
        std::cout << x;                                             // lvalue
    }

    {
        int x { 5 };
        std::cout << x + 1;                                         // rvalue
    }

    {
        std::cout << foo();                                         // rvalue
    }

    {
        int x { 5 };
        int y { 6 };
        std::cout << max(x, y);                                     // lvaue reference
    }
    std::cout << '\n' << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Question II
    // What is the output of this program?
    {
        int x { 5 };
        int y { 6 };

        int& ref { x };
        ref++;
        ref = y;
        ref++;

        std::cout << x << ' ' << y;
    }
    std::cout << '\n' << std::string(70, '-') << '\n';
    // Th output should be: 7 6

    //---------------------------------------------------------------------------------------------

    // Question III
    // Name two reasons why we prefer to pass arguments by const reference instead of by non-const reference whenever possible.

    //// a const reference can accept modifiable and non modifiable lvalues
    //// it prevent us from modifing the argument if we don't need to..

    //---------------------------------------------------------------------------------------------

    // Question IV
    // What is the difference between a const pointer and a pointer-to-const?

    //// const pointer you cant change the memory address that is referencing
    // pointer to const  can't change the value at the memory address it's dereferencing

    //---------------------------------------------------------------------------------------------

    // Question V
    // Write a function named sort2 which allows the caller to pass 2 int variables as arguments.
    // When the function returns, the first argument should hold the lesser of the two values, and the second argument should hold the greater of the two values.

    // The following code should run and print the values noted in the comments:
    {
        int x { 7 };
        int y { 5 };

        sort2(x, y);
        std::cout << x << ' ' << y << '\n';             // should return 5 7

        sort2(y, x);
        std::cout << y << ' ' << x << '\n';             // should print 5 7
    }
}