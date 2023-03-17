#include <iostream>
#include "constants.h"

bool passOrFail()
{
	static int s_user{ 3 };
	s_user--;
	if (s_user >= 0)
		return true;

	return false;
}

int main()
{
	// Question #1
	// Fix the following program:
	{
		std::cout << "Enter a positive number: ";
		int num{};
		std::cin >> num;


		if (num < 0)
		{
			std::cout << "Negative number entered, Making it positive" << '\n';
			// fix
			num *= -1;
		}

		std::cout << "you entered: " << num << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//----------------------------------------------------------------------------------------------------------------------

	// Question #2
	// Write a file named constants.h that makes the following program run.
	// If your compiler is C++17 capable, use inline constexpr variables.
	// Otherwise, use normal constexpr variables. 
	// max_class_size should be 35.

	{
		std::cout << "How many students are in your class?" << '\n';
		int students{};
		std::cin >> students;
		std::cout << '\n';

		if (students > constants::max_class_size)
			std::cout << "Tere are too many students in this class." << '\n';
		else
			std::cout << "This class isn't too large." << '\n';
	}
	std::cout << std::string(50, '-') << '\n';

	//----------------------------------------------------------------------------------------------------------------------

	// Question #3
	// Complete the following program by writing the passOrFail() function, which should return true for the first 3 calls, and false thereafter. 
	// Do this without modifying the main() function.

	{
		std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
		std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");
	}
	
	return 0;
}