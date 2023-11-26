#include <iostream>
#include <string>
#include <cmath>                         // for std::sin() and std::cos()

void print(int x)                        // x is an (in parameter)
{
    std::cout << x << '\n';
}

void print(const std::string& s)         // s is an in parameter
{
    std::cout << s << '\n';
}


// sinOut and cosOut are out parameters
void getSinCos(double degrees, double& sinOut, double& cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    constexpr double PI { 3.14159265358979323846 };             // PI's value

    double radians = degrees * PI / 180;

    sinOut = std::sin(radians);
    cosOut == std::cos(radians);
}

int getByValue()
{
    return 5;
}

void getByReference(int& x)
{
    x = 5;
}

int main()
{
    // In parameters
    // In most cases, a function parameter is used only to receive an input from the caller.
    // Parameters that are used only for receiving input from the caller are sometimes called in parameters.
    {
        print(5);
        std::string s { "Hello Rana! "};
        print(s);
    }
    std::cout << std::string(70, '-') << '\n';

    // In-parameters are typically passed by value or by const reference.
    
    //---------------------------------------------------------------------------------------------

    // Out parameters

    // A function argument passed by (non-const) reference (or by address) allows the function to modify the value of an object passed as an argument.
    // This provides a way for a function to return data back to the caller in cases where using a return value is not sufficient for some reason.

    // A function parameter that is used only for the purpose of returning information back to the caller is called an out parameter.
    // for example:
    {
        double sin { };
        double cos { };

        std::cout << "Enter the number of degrees: ";
        double degrees { };
        std::cin >> degrees;

        // getSinCos will return the sin and cos in variables sin and cos
        getSinCos(degrees, sin, cos);

        std::cout << "The sin is: " << sin << '\n';
        std::cout << "The cos is: " << cos << '\n';
    }
    std::cout <<std::string(70, '-') << '\n';

    // This function has one parameter degrees (whose argument is passed by value) as input, and “returns” two parameters (by reference) as output.

    //---------------------------------------------------------------------------------------------

    // Out parameters have an unnatural syntax

    // Out-parameters, while functional, have a few downsides.
    // First, the caller must instantiate (and initialize) objects and pass them as arguments, even if it doesn’t intend to use them.
    // These objects must be able to be assigned to, which means they can’t be made const.
    // Second, because the caller must pass in objects, these values can’t be used as temporaries, or easily used in a single expression.
    // The following example shows both of these downsides:
    {
        // return by value
        [[maybe_unused]] int x { getByValue() };            // can be used to initialize object
        std::cout << getByValue() << '\n';                  // can use temporary return value in expression

        // return by out parameter
        int y { };                                          // must first allocate an assignable object
        getByReference(y);                                  // then pass to a function to assign the desired value
        std::cout << y << '\n';                             // and only then we can use this value
    }
    std::cout << std::string(70, '-') << '\n';

    // As you can see, the syntax of using out-parameters is a bit unnatural.

    //---------------------------------------------------------------------------------------------

    // In/out parameters

    // In rare cases, a function will actually use the value of an out-parameter before overwriting its value.
    // Such a parameter is called an in-out parameter. In-out-parameters work identically to out-parameters and have all the same challenges.

    //---------------------------------------------------------------------------------------------

    // When to pass by non-const reference

    // If you’re going to pass by reference in order to avoid making a copy of the argument, you should almost always pass by const reference.
    // However, there are two primary cases where pass by non-const reference may be the better choice.
    // First, use pass by non-const reference when a parameter is an in-out-parameter.
    // Since we’re already passing in the object we need back out, it’s often more straightforward and performant to just modify that object.
    {

    }
}