#include <iostream>

// Defining structs
// Because structs are a user-defined type, we first have to tell the compiler what our struct type looks like before we can begin using it.
// Here is an example of a struct definition for a simplified employee:
struct Employee
{
    int id { };
    int age { };
    double wage { };
};
// The struct keyword is used to tell the compiler that we’re defining a struct, which we’ve named Employee (since user-defined types are typically given names starting with a capital letter).
// Then, inside a pair of curly braces, we define the variables that each Employee object will contain.
// In this example, each Employee we create will have 3 variables: an int id, an int age, and a double wage.
// The variables that are part of the struct are called data members (or member variables).


int main()
{
    // Defining struct objects
    {
        Employee joe { };

        // This defines a variable of type Employee named joe.
        // When the code is executed, an Employee object is instantiated that contains the 3 data members.
        // The empty braces ensures our object is value-initialized.

        // Just like any other type, it is possible to define multiple variables of the same struct type:
        Employee frank { };

        // Accessing members
        // In the above example, the name joe refers to the entire struct object (which contains the member variables).
        // To access a specific member variable, we use the member selection operator (operator.) in between the struct variable name and the member name.
        // For example, to access Joe’s age member, we’d use joe.age.
        // Struct member variables work just like normal variables, so it is possible to do normal operations on them, including assignment, arithmetic, comparison, etc…

        joe.age = 32;                               // use member selection operator (.) to select the age member of variable joe
        // prints joe.age
        std::cout << "Joe's age: " << joe.age << '\n';
    }
    std::cout << std::string(70, '=') << '\n';

    // One of the biggest advantages of structs is that we only need to create one new name per struct variable
    // (the member names are fixed as part of the struct type definition). In the following example, we instantiate two Employee objects: joe and frank.
    {
        Employee joe { };
        joe.id = 14;
        joe.age = 32;
        joe.wage = 60000.0;

        Employee frank { };
        frank.id = 15;
        frank.age = 28;
        frank.wage = 45000.0;

        int totalAge { joe.age + frank.age };

        if (joe.wage > frank.wage)
        {
            std::cout << "Joe makes more money than Frank." << '\n';
        }
        else if (joe.wage < frank.wage)
        {
            std::cout << "Joe makes less money than Frank." << '\n';
        }
        else
        {
            std::cout << "Joe and Frank make the same amount of money." << '\n';
        }

        // Frank got a promosion
        frank.wage += 5000.0;

        // Todat is Joe's birthday
        joe.age++;
    }
    // In the above example, it is very easy to tell which member variables belong to Joe and which belong to Frank.
    // This provides a much higher level of organization than individual variables would.
    // Furthermore, because Joe’s and Frank’s members have the same names, this provides consistency when you have multiple variables of the same struct type.
}