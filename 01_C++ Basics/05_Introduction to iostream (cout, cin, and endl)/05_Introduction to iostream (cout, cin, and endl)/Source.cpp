#include <iostream>

int main()
{
	int x{ 5 };

	std::cout << "Hey Dell G5" << std::endl;
	std::cout << 4 << std::endl;
	std::cout << x << std::endl;
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << "x is equal to " << x << std::endl;

	std::cout << "Hi!";
	std::cout << "My name is Mohamed";
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;

	std::cout << "Hi!" << std::endl;				// std::endl will cause the cursor to move to the next line of the console
	std::cout << "My name is Alex." << std::endl;

	std::cout << "x is equal to: " << x << '\n'; // Using '\n' standalone
	std::cout << "And that's all, folks!\n"; // Using '\n' embedded into a double-quoted piece of text (note: no single quotes when used this 

	std::cout << "Please, Enter a number: ";	// ask the user for a number
	int answer{};								// define a variable to hold the user input
	std::cin >> answer;							// Get the input from the user

	std::cout << "You've entered: " << answer << "\n";

	std::cout << "please enter two numbers seperated by space: ";		// aske the user for two numbers
	int num1{}, num2{};													// define two variables to take the input
	std::cin >> num1 >> num2;
	std::cout << "You've entered: " << num1 << " & " << num2 << ". And there sum is: " << num1 + num2 << "\n";

	
	std::cout << std::endl;
	return 0;
}