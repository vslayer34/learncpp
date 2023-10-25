#include <iostream>

// Let’s say you wanted to write a function to calculate the maximum of two numbers. You might do so like this:
int max(int x, int y)
{
    return (x < y) ? y : x;
    // Note: we use < instead of > because std::max uses <
}

// So what happens later when you want to find the max of two double values?
// Because C++ requires us to specify the type of all function parameters, the solution is to create a new overloaded version of max with parameters of type double:
int max(double x, double y)
{
    return (x < y) ? y : x;
}

//-------------------------------------------------------------------------------------------------

// Function templates
// // // Type template parameters (where the template parameter represents a type).
// // // Non-type template parameters (where the template parameter represents a constexpr value).
// // // Template template parameters (where the template parameter represents a template).

//-------------------------------------------------------------------------------------------------

// Creating a templated max function

// Here’s our new function that uses a single template type:
// won't compile because we haven't defined T with template <typename T>
template <typename T>   // this is the template parameter declaration
T max(T x, T y)         // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

// Because this function template has one template type named T, we’ll refer to it as max<T>.

int main()
{
    
}