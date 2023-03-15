#include <iostream>

int foo{};

int main()
{
	// You’ve probably seen this program in a lot of textbooks and tutorials:
	{
		using namespace std;

		cout << "Hello World!" << '\n';
	}
	std::cout << std::string(55, '-') << '\n';

	//------------------------------------------------------------------------------------------------------

	// Qualified and unqualified names
	// A qualified name is a name that includes an associated scope.
	// Most often, names are qualified with a namespace using the scope resolution operator (::). 
	// For example:
	{
		std::cout;												// identifier cout is qualified by namespace std
		::foo;													// identifier foo is qualified by the global namespace
	}

	// An unqualified name is a name that does not include a scoping qualifier. 
	// For example, cout and x are unqualified names, as they do not include an associated scope.

	//------------------------------------------------------------------------------------------------------

	// Using declarations
	// One way to reduce the repetition of typing std:: over and over is to utilize a using declaration statement.
	// A using declaration allows us to use an unqualified name (with no scope) as an alias for a qualified name.

	// Here’s our basic Hello world program, using a using declaration:
	{
		using std::cout;										// this using declaration tells the compiler that cout should resolve to std::cout
		cout << "Hello World!" << '\n';							// so no std:: prefix is needed here

	}	// the using declaration expires here

	std::cout << std::string(55, '-') << '\n';

	//------------------------------------------------------------------------------------------------------

	// Using directives
	// Another way to simplify things is to use a using directive. 
	// Slightly simplified, a using directive imports all of the identifiers from a namespace into the scope of the using directive.

	// Here’s our Hello world program again, with a using directive on line 5:
	{
		// his using directive tells the compiler to import all names from namespace std into the current namespace without qualification
		using namespace std;

		cout << "Hello World!!!" << '\n';						// so no std:: prefix is needed here
	}
	
	return 0;
}