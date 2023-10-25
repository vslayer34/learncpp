#include <iostream>

// In lesson 10.15 -- Function templates, we wrote a function template to calculate the maximum of two values:
template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}


// Provide an explicit type template argument
double max(double x, double y)
{
    return (x < y) ? y : x;
}

// The best way to solve this problem is to rewrite our function template in such a way that our parameters can resolve to different types.
// Rather than using one template type parameter T, we’ll now use two (T1 and T2):
/*
template <typename T1, typename T2>
T1 max(T1 x, T2 y)
{
    return (x < y) ? y : x;
}
*/

// However, the above code still has a problem: using the usual arithmetic rules (10.5 -- Arithmetic conversions),
// double takes precedence over int, so our conditional operator will return a double.
// But our function is defined as returning a T -- in cases where T resolves to an int, our double return value will undergo a narrowing conversion to an int,
// which will produce a warning (and possible loss of data).

// Making the return type a U instead doesn’t solve the problem, as we can always flip the order of the operands in the function call to flip the types of T and U.

// How do we solve this? This is a good use for an auto return type -- we’ll let the compiler deduce what the return type should be from the return statement:
template <typename T1, typename T2>
auto max(T1 x, T2 y)
{
    return (x < y) ? y : x;
}

// Abbreviated function templates C++20

// C++20 introduces a new use of the auto keyword:
// When the auto keyword is used as a parameter type in a normal function.
// The compiler will automatically convert the function into a function template with each auto parameter becoming an independent template type parameter.
// This method for creating a function template is called an abbreviated function template.
auto max(auto x, auto y)
{
    return (x < y) ? y : x;
}


int main()
{
    {
        std::cout << max<int>(1, 2) << '\n';             // will instantiate max(int, int)
        std::cout << max<double>(1.5, 2.5) << '\n';      // will instantiate max(double, double)
    }
    std::cout << std::string(70, '-') << '\n';

    //---------------------------------------------------------------------------------------------

    // Use static_cast to convert the arguments to matching types
    // The first solution is to put the burden on the caller to convert the arguments into matching types. For example:
    {
        // convert our int to a double so we can call max(double, double)
        std::cout << max(static_cast<double>(2), 3.5) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';
    // Now that both arguments are of type double, the compiler will be able to instantiate max(double, double) that will satisfy this function call.
    
    //---------------------------------------------------------------------------------------------

    // Provide an explicit type template argument

    // If we had written a non-template max(double, double) function, then we would be able to call max(int, double) and let the implicit type conversion rules convert our int argument into a double so the function call could be resolved:
    {
        // std::cout << max(2, 3.5) << '\n';               // the int argument will be converted to a double
    }
    std::cout << std::string(70, '-') << '\n';

    // However, when the compiler is doing template argument deduction, it won’t do any type conversions.
    // Fortunately, we don’t have to use template argument deduction if we specify an explicit type template argument to be used instead:
    {
        // we've explicitly specified type double, so the compiler won't use template argument deduction
        std::cout << "we've explicitly specified type double, so the compiler won't use template argument deduction" << '\n';
        std::cout << max<double>(2, 3.5) << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // In the above example, we call max<double>(2, 3.5).
    // Because we’ve explicitly specified that T should be replaced with double, the compiler won’t use template argument deduction.
    // Instead, it will just instantiate the function max<double>(double, double), and then type convert any mismatched arguments.
    // Our int parameter will be implicitly converted to a double.

    // While this is more readable than using static_cast, it would be even nicer if we didn’t even have to think about the types when making a function call to max at all.

    //---------------------------------------------------------------------------------------------

    // Function templates with multiple template type parameters
    // The root of our problem is that we’ve only defined the single template type (T) for our function template,
    // and then specified that both parameters must be of this same type.

    
}