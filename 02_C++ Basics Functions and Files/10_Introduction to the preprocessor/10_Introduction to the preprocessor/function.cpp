#include <iostream>

void doSomething()
{
#ifdef PRINT
	std::cout << "Printing" << "\n";
#endif // PRINT

#ifndef PRINT
	std::cout << "Not Printing" << "\n";
#endif // !PRINT


}