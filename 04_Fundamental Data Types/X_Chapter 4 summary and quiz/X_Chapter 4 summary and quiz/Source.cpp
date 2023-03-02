#include <iostream>

float inputFloatNumber()
{
	std::cout << "Enter a double value: ";
	float input{};
	std::cin >> input;
	return input;
}

float add(float num1, float num2)
{
	return num1 + num2;
}

float subtract(float num1, float num2)
{
	return num1 - num2;
}

float multiply(float num1, float num2)
{
	return num1 * num2;
}

float divide(float num1, float num2)
{
	return num1 / num2;
}

char inputCharacter()
{
	std::cout << "Enter one of the following (+, -, *, or /): ";
	char inputOperator{};
	std::cin >> inputOperator;

	return inputOperator;
}

void printResult(float num1, float num2, char operation, float result)
{
	std::cout << num1 << " " << operation << " is " << result << '\n';
}

void questionThree()
{
	// Enter first two numbers
	float input1{ inputFloatNumber() };
	float input2{ inputFloatNumber() };

	// enter the operator
	char operation{ inputCharacter() };

	// check the operator
	// if invalid print nothing
	float result{};

	if (operation == '+')
		result = add(input1, input2);

	else if (operation == '-')
		result = subtract(input1, input2);

	else if (operation == '*')
		result = multiply(input1, input2);

	else if (operation == '/')
		result = divide(input1, input2);

	else
		return;

	printResult(input1, input2, operation, result);

}

int main()
{
	// Question #3
	//Write the following program :
	//The user is asked to enter 2 floating point numbers(use doubles).
	// The user is then asked to enter one of the following mathematical symbols : +, -, *, or /.
	// The program computes the answer on the two numbers the user entered and prints the results.
	// If the user enters an invalid symbol, the program should print nothing.

	questionThree();

	
	return 0;
}