#include <iostream>

extern int g_x1{ 2 };									// non-constant globals have external linkage by default
extern const int g_y1{ 3 };								// this extern gives g_y external linkage

void sayHi()											// this function has external linkage, and can be seen by other files.
{
	std::cout << "Hi!!!" << '\n';
}