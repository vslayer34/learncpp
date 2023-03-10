#include <iostream>
#include "foo.cpp"
#include "goo.cpp"
#include "circle.h"														// for basicMath::pi
#include "growth.h"														// for basicMath::e
#include "add.h"														// for basicMath::add()

int doSomething(int x, int y);											// forward declaration for doSomething

void print()															// this print lives in the global namespace
{
	std::cout << " there\n";
}

int main()
{
	//std::cout << doSomething(4, 3) << '\n';							// which doSomething will we get?

	// If this project contains only foo.cpp or goo.cpp (but not both), it will compile and run without incident.
	// However, by compiling both into the same program, 
	// we have now introduced two different functions with the same name and parameters into the same scope (the global scope), 
	// which causes a naming collision. 
	// As a result, the linker will issue an error.

	// One way to resolve this would be to rename one of the functions, so the names no longer collide.
	// But this would also require changing the names of all the function calls, which can be a pain, and is subject to error.
	// A better way to avoid collisions is to put your functions into your own namespaces. 
	// For this reason the standard library was moved into the std namespace.

	//-------------------------------------------------------------------------------------------------------------------------

	// Defining your own namespaces
	// In this case, the compiler was satisfied (by our forward declaration), but the linker could not find a definition for doSomething in the global namespace.
	// This is because both of our versions of doSomething are no longer in the global namespace!

	// There are two different ways to tell the compiler which version of doSomething() to use,
	// via the scope resolution operator, or via using statements(which we’ll discuss in a later lesson in this chapter).

	//-------------------------------------------------------------------------------------------------------------------------

	// Accessing a namespace with the scope resolution operator (::)

	
	std::cout << foo::doSomething(3, 4) << '\n';				// use the doSomething() that exists in namespace foo
	// If we wanted to use the version of doSomething() that lives in goo instead:
	std::cout << goo::doSomething(4, 3) << '\n';				// use the doSomething() that exists in namespace goo

	//-------------------------------------------------------------------------------------------------------------------------

	// Using the scope resolution operator with no name prefix
	// The scope resolution operator can also be used in front of an identifier without providing a namespace name (e.g. ::doSomething).
	// In such a case, the identifier (e.g. doSomething) is looked for in the global namespace.
	foo::print();													// call print() in foo namespace
	::print();														// call print() in global namespace (same as just calling print() in this case)
	std::cout << '\n';

	// In the above example, the ::print() performs the same as if we’d called print() with no scope resolution, 
	// so use of the scope resolution operator is superfluous in this case. 
	// But the next example will show a case where the scope resolution operator with no namespace can be useful.

	//-------------------------------------------------------------------------------------------------------------------------

	// Multiple namespace blocks are allowed
	// It’s legal to declare namespace blocks in multiple locations (either across multiple files, or multiple places within the same file).
	// All declarations within the namespace are considered part of the namespace.

	std::cout << basicMath::pi << '\n';
	std::cout << basicMath::e << '\n';
	std::cout << '\n';

	std::cout << basicMath::add(6, 3) << '\n';
	std::cout << '\n';
	
	// If the namespace is omitted in the source file, the linker won’t find a definition of basicMath::add, because the source file only defines add (global namespace).
	// If the namespace is omitted in the header file, “main.cpp” won’t be able to use basicMath::add, because it only sees a declaration for add (global namespace).

	//-------------------------------------------------------------------------------------------------------------------------

	// Nested namespaces
	// Namespaces can be nested inside other namespaces. For example:

	std::cout << foo::moo::add(4, 2) << '\n';
	std::cout << '\n';

	//-------------------------------------------------------------------------------------------------------------------------

	// Namespace aliases
	// Because typing the qualified name of a variable or function inside a nested namespace can be painful,
	// C++ allows you to create namespace aliases, which allow us to temporarily shorten a long sequence of namespaces into something shorter:

	namespace active = foo::moo;										// active now refers to foo::moo

	std::cout << active::add(1, 2) << '\n';						// This is really foo::moo::add()
	std::cout << '\n';

	return 0;
}																		// The active alias ends here

