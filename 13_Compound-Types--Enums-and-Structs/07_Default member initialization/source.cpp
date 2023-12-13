#include <iostream>

// When we define a struct (or class) type, we can provide a default initialization value for each member as part of the type definition.
// This process is called non-static member initialization, and the initialization value is called a default member initializer.
struct Something
{
    int x;                                          // No initilaization value (bad)
    int y { };                                      // Value initialized by default
    int z { 2 };                                    // explicit default value
};
// In the above definition of Something, x has no default value, y is value-initialized by default, and z has the default value 2.
// These default member initialization values will be used if the user doesn’t provide an explicit initialization value when instantiating an object of type Something.


int main()
{

}