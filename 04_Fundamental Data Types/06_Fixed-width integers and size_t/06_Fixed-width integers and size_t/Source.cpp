#include <cstdint>											// for fixed-width integers
#include <iostream>

int main()
{
	// C++ officially adopted these fixed - width integers as part of C++11.
	// They can be accessed by including the <cstdint> header, where they are defined inside the std namespace.
	// Here�s an example :

	std::int16_t i{ 5 };
	std::cout << "i: " << i << "\n";
	

	// Fast and least integers:
	std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	
	std::cout << "\n";

	std::cout << "fast 8: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";


	return 0;
}