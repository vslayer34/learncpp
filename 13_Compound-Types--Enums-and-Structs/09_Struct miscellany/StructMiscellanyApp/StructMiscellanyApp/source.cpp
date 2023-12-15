#include <iostream>

// Structs with program-defined members
// In C++, structs (and classes) can have members that are other program-defined types. There are two ways to do this.
// First, we can define one program-defined type (in the global scope) and then use it as a member of another program-defined type:
struct Employee
{
	int id{ };
	int age{ };
	double wage{};
};


struct Company
{
	int numOfEmployees{ };
	Employee cEO{ };			// Employee is a struct within the Company struct
};

// Second, types can also be nested inside other types, so if an Employee only existed as part of a Company, the Employee type could be nested inside the Company struct:
struct Company2
{
	struct Employee2			// accessed via Company::Employee
	{
		int id{ };
		int age{ };
		double wage{ };
	};

	int numberOfEmployees{ };
	Employee2 cEO{ };			// Employee2 is a struct within the Company2 struct
};

struct Foo
{
	short a{ };
	int b{ };
	double c{ };
};

int main()
{
	{
		Company myCompany
		{
			.numOfEmployees = 7,
			.cEO
			{
				.id = 1,
				.age = 32,
				.wage = 55000.0
			}
		};												// Nested initialzation

		std::cout << myCompany.cEO.wage << '\n';		// print CEO wage
	}
	std::cout << std::string(70, '=') << '\n';

	//-------------------------------------------------------------------------------------------------

	{
		Company2 myCompany
		{
			.numberOfEmployees = 7,
			.cEO =
			{
				.id = 1,
				.age = 32,
				.wage = 55000.0
			}
		};

		std::cout << "Second example CEO wage: " << myCompany.cEO.wage << '\n';
	}
	std::cout << std::string(70, '=') << '\n';

	//-------------------------------------------------------------------------------------------------

	// Struct size and data structure alignment
	// Typically, the size of a struct is the sum of the size of all its members, but not always!
	{
		std::cout << "The size of short is:      " << sizeof(short) << '\n';
		std::cout << "The size of int is:        " << sizeof(int) << '\n';
		std::cout << "THe size of double is:     " << sizeof(double) << '\n';

		std::cout << "The size of Foo struct is: " << sizeof(Foo) << '\n';
	}
	std::cout << std::string(70, '=') << '\n';

	// Note that the size of short + int + double is 14 bytes, but the size of Foo is 16 bytes!
	// It turns out, we can only say that the size of a struct will be at least as large as the size of all the variables it contains.
	// But it could be larger! For performance reasons, the compiler will sometimes add gaps into structures (this is called padding).

	//------------------------------------------------------------------------------------------------


}