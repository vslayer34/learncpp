#include <iostream>
#include <utility>              // for std::pair


// define our own Pair type
// Just like function parameters can have default arguments
// Tmplate parameters can be given default values.
// These will be used when the template parameter isn’t explicitly specified and can’t be deduced.
// Here’s a modification of our Pair<T, U> class template program above, with type template parameters T and U defaulted to type int:
template <typename T1 = int, typename T2 = int>
struct Pair
{
	T1 first{ };
	T2 second{ };
};

// Here's a deduction guide for our Pair (needed in C++17)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
template <typename T1, typename T2>
Pair(T1, T2) -> Pair<T1, T2>;

// CTAD doesn’t work with non-static member initialization
// When initializing the member of a class type using non-static member initialization, CTAD will not work in this context.
// All template arguments must be explicitly specified:
struct Foo
{
	std::pair<int, int> p1{ 1, 2 };							// ok, template arguments explicitly specified
	/*std::pair p2{3, 4};									// compile error, CTAD can't be used in this context*/
};

int main()
{
	{
		std::pair<int, int> p1{ 1, 2 };						// explicitly specify class template std::pair<int, int> (C++11 onward)
		std::pair p2{ 3, 4 };								// CTAD used to deduce std::pair<int, int> from the initializers (C++17)
	}

	// CTAD is only performed if no template argument list is present. Therefore, both of the following are errors:

	{
		/*
		std::pair<> p1{ 1, 2 };								// error: too few template arguments, both arguments not deduced
		std::pair<int> p2{ 3, 4 };							// error: too few template arguments, second argument not deduced
		*/
	}

	//---------------------------------------------------------------------------------------------

	// Template argument deduction guides C++17 
	// In most cases, CTAD works right out of the box.
	// However, in certain cases, the compiler may need a little extra help understanding how to deduce the template arguments properly.
	// You may be surprised to find that the following program (which is almost identical to the example that uses std::pair above) doesn’t compile in C++17:
	{
		Pair<int, int> p1{ .first = 1, .second = 2 };		// ok: we're explicitly specifying the template arguments
		/*Pair p2{3, 4};									// compile error in C++17*/
	}
	// If you compile this in C++17, you’ll likely get some error about “class template argument deduction failed” or “cannot deduce template arguments” or “No viable constructor or deduction guide”.
	// This is because in C++17, CTAD doesn’t know how to deduce the template arguments for aggregate class templates.
	// To address this, we can provide the compiler with a deduction guide, which tells the compiler how to deduce the template arguments for a given class template.

	// Here’s the same program with a deduction guide:
	{
		Pair<int, int> p1{ .first = 1, .second = 2 };		// explicitly specify class template Pair<int, int> (C++11 onward)
		Pair p2{ 3, 4 };									// CTAD used to deduce Pair<int, int> from the initializers (C++17)

		Pair p3{ };											// uses default Pair<int, int>
	}
	// This example should compile under C++17.
}