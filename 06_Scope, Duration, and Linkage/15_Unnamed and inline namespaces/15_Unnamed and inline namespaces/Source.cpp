#include <iostream>

// Unnamed (anonymous) namespaces
// An unnamed namespace (also called an anonymous namespace) is a namespace that is defined without a name, like so:

namespace																// unnamed namespace
{
	void doSomething()													// can only be accessed in this files
	{
		std::cout << "V1" << '\n';
	}
}

namespace v2															// declare an inline namespace named v2
{
	void doSomething()
	{
		std::cout << "V2" << '\n';
	}
}

namespace v3															// declare an inline namespace named v3
{
	void doSomething()
	{
		std::cout << "V3" << '\n';
	}
}

int main()
{
	{
		doSomething();													// now we can call doSomething() without the namespace prefix
	}
	std::cout << std::string(50, '-') << '\n';
	// All content declared in an unnamed namespace is treated as if it is part of the parent namespace.
	// So even though function doSomething is defined in the unnamed namespace, 
	// the function itself is accessible from the parent namespace (which in this case is the global namespace),
	// which is why we can call doSomething from main without any qualifiers.

	// This might make unnamed namespaces seem useless.
	// But the other effect of unnamed namespaces is that all identifiers inside an unnamed namespace are treated as if they had internal linkage, 
	// which means that the content of an unnamed namespace can’t be seen outside of the file in which the unnamed namespace is defined.

	// Unnamed namespaces are typically used when you have a lot of content that you want to ensure stays local to a given file,
	//  as it’s easier to cluster such content in an unnamed namespace than individually mark all declarations as static.
	// Unnamed namespaces will also keep user-defined types (something we’ll discuss in a later lesson) local to the file, 
	// something for which there is no alternative equivalent mechanism to do.

	//---------------------------------------------------------------------------------------------------------------------------------------------------

	// Inline namespaces
	
	{
		doSomething();													// calls the inline version of doSomething() (which is v1)
		v2::doSomething();												// calls the v2 version of doSomething()
		v3::doSomething();												// calls the v3 version of doSomething()
	}
	std::cout << std::string(50, '-') << '\n';

	// In the above example, 
	// callers to doSomething will get the v1(the inline version) of doSomething.Callers who want to use the newer version can explicitly call v2::dosomething().
	// This preserves the function of existing programs while allowing newer programs to take advantage of newer / better variations.


	return 0;
}