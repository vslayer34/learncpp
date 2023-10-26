// Question IV.

#include <iostream>

template <typename T>
int count(T)            // This is the same as int count(T x), except we're not giving the parameter a name since we don't use the parameter
{
    static int c { 0 };
    return ++c;
}

int main()
{
    // What is the output of this program and why?
    {
        std::cout << count(1) << '\n';
        std::cout << count(2) << '\n';
        std::cout << count(2.3) << '\n';
        std::cout << count<double>(1) << '\n';
    }    

    // it would instantiate 2 times one for the int and one for the double
    // so it would print: 
    // 1: first int version instantiated
    // 2: second int version usage
    // 1: first double version instantiated
    // 2: second double version usage
}