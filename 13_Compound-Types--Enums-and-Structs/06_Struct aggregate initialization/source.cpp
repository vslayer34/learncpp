#include <iostream>

struct Employee
{
    int id { };
    int age { };
    double wage { };
};

struct Rectangle
{
    double length { };
    double width { };
};

struct Foo
{
    int a { };
    int b { };
    int c { };
};



int main()
{
    // Aggregate initialization of a struct
    
    {
        // Because a normal variable can only hold a single value, we only need to provide a single initializer:
        int x { 5 };

        // However, a struct can have multiple members:
        struct Employee
        {
            int id { };
            int age { };
            double wage { };
        };
    }

    // Aggregates use a form of initialization called aggregate initialization, which allows us to directly initialize the members of aggregates.
    // To do this, we provide an initializer list as an initializer, which is just a braced list of comma-separated values.
    {
        Employee frank = { 1, 32, 60000.0 };                    // copy-list initialization using braced list
        Employee joe { 2, 28, 45000.0 };                        // list initialization using braced list (preferred)
    }

    //---------------------------------------------------------------------------------------------

    // Missing initializers in an initializer list
    // If an aggregate is initialized but the number of initialization values is fewer than the number of members, then all remaining members will be value-initialized.
    {
        Employee joe { 2, 28 };                                 // joe.wage will be value-initialized to 0.0
    }
    // In the above example, joe.id will be initialized with value 2, joe.age will be initialized with value 28, and because joe.
    // wage wasn’t given an explicit initializer, it will be value-initialized to 0.0.

    //---------------------------------------------------------------------------------------------

    // Const structs
    // Variables of a struct type can be const (or constexpr), and just like all const variables, they must be initialized.
    {
        const Rectangle unit { 1.0, 1.0 };
        const Rectangle zero { };                                // 0.0 would be initialized to all members
    }

    //---------------------------------------------------------------------------------------------

    // Assignment with designated initializers C++20

    // Designated initializers can also be used in a list assignment:
    {
        Employee joe { 1, 32, 60000.0 };
        joe =
        {
            .id = joe.id,
            .age = 33,
            .wage = 66000.0
        };
    }

    // Any members that aren’t designated in such an assignment will be assigned the value that would be used for value initialization.
    // If we hadn’t have specified a designated initializer for joe.id, joe.id would have been assigned the value 0.

    //---------------------------------------------------------------------------------------------

    // Initializing a struct with another struct of the same type
    // A struct may also be initialized using another struct of the same type:
    {
        Foo foo
        {
            .a = 1,
            .b = 2,
            .c = 3
        };

        Foo x = foo;                                            // copy initialization
        Foo y ( foo );                                          // direct initialization
        Foo z { foo };                                          // list initialization

        std::cout << x.a << ' ' << y.b << ' ' << z.c << '\n';
    }
}