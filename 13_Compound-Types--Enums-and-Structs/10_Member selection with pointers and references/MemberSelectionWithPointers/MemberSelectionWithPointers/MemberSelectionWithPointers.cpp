#include <iostream>

struct Employee
{
    int id{ };
    int age{ };
    double wage{ };
};

void printEmployee(const Employee& employee)
{
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

struct Paw
{
    int claws{ };
};

struct Animal
{
    std::string name{ };
    Paw paw{ };
};

int main()
{
    // Member selection for structs and references to structs
    // In lesson 13.5 -- Introduction to structs, members, and member selection.
    // We showed that you can use the member selection operator (.) to select a member from a struct object:
    {
        Employee joe{ .id = 1, .age = 34, .wage = 65000.0 };
        
        // Use member selection operator (.) to select a member from struct object
        joe.age++;                      // Joe had a birthday
        joe.wage += 3000.0;             // Joe got a promotion
    }
    
    // Since references to an object act just like the object itself, we can also use the member selection operator (.) to select a member from a reference to a struct:
    {
        Employee joe{ .id = 1, .age = 34, .wage = 65000.0 };

        // Use member selection operator (.) to select a member from struct object
        joe.age++;                      // Joe had a birthday
        joe.wage += 3000.0;             // Joe got a promotion

        printEmployee(joe);
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Member selection for pointers to structs
    // However, use of the member selection operator (.) doesn’t work if you have a pointer to a struct:
    {
        Employee joe{ .id = 1, .age = 34, .wage = 65000.0 };

        // Use member selection operator (.) to select a member from struct object
        joe.age++;                      // Joe had a birthday
        joe.wage += 3000.0;             // Joe got a promotion

        Employee* ptr{ &joe };
        /*std::cout << ptr.id << '\n';        // Compile error: can't use operator. with pointers*/
    }

    // With normal variables or references, we can access objects directly.
    // However, because pointers hold addresses, we first need to dereference the pointer to get the object before we can do anything with it.
    // So one way to access a member from a pointer to a struct is as follows:
    {
        Employee joe{ .id = 1, .age = 34, .wage = 65000.0 };

        // Use member selection operator (.) to select a member from struct object
        joe.age++;                      // Joe had a birthday
        joe.wage += 3000.0;             // Joe got a promotion

        Employee* ptr{ &joe };
        std::cout << (*ptr).id << '\n';             // Not great but works: First dereference ptr, then use member selection
    }

    // However, this is a bit ugly, especially because we need to parenthesize the dereference operation so it will take precedence over the member selection operation.
    // To make for a cleaner syntax, C++ offers a member selection from pointer operator (->) (also sometimes called the arrow operator) that can be used to select members from a pointer to an object:
    {
        Employee joe{ .id = 1, .age = 34, .wage = 65000.0 };

        joe.age++;
        joe.wage += 3000.0;

        Employee* ptr{ &joe };
        std::cout << "Arrow operator: " << ptr->wage << '\n';
    }

    // This member selection from pointer operator (->) works identically to the member selection operator (.)
    // But does an implicit dereference of the pointer object before selecting the member. Thus ptr->id is equivalent to (*ptr).id.

    //---------------------------------------------------------------------------------------------

    // Mixing pointers and non-pointers to members
    // The member selection operator is always applied to the currently selected variable.
    // If you have a mix of pointers and normal member variables, you can see member selections where . and -> are both used in sequence:
    {
        Animal puma
        {
            .name = "Puma",
            .paw { .claws = 5 }
        };

        Animal* ptr{ &puma };

        // ptr is a pointer we should use ->
        // paw is not a pointer we should use (.)

        std::cout << ptr->paw.claws << '\n';
    }
}