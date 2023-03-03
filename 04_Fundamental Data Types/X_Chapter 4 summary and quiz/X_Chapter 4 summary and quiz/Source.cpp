#include <iostream>

//--------------------------------------------------------------------------------------------------------------
// Question III
//--------------------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
// Question IV
//--------------------------------------------------------------------------------------------------------------

double enterHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height;
	std::cin >> height;

	return height;
}

double calculateDistanceToGround(double height, int time)
{
	const double gravity{ 9.8 };
	double distanceToGround{};

	// get distance fallen
	double distanceFallen = gravity * (time * time) / 2;

	// get distance to ground
	distanceToGround = height - distanceFallen;

	// prevent distance to ground from being greater than the original height
	if (distanceFallen > height)
		return 0.0;
	else
		return distanceToGround;
}

void printResults(int time, double height)
{
	double distanceToGround{ calculateDistanceToGround(height, time) };

	if (distanceToGround == 0.0)
		std::cout << "At " << time << " seconds, the ball is on the ground.\n";
	else
		std::cout << "At " << time << " seconds, the ball is at height: " << calculateDistanceToGround(height, time) << " meters.\n";
}

void questionFour()
{
	double height{ enterHeight() };

	printResults(0, height);
	printResults(1, height);
	printResults(2, height);
	printResults(3, height);
	printResults(4, height);
	printResults(5, height);
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
	std::cout << "--------------------------------------------------------------------------------------------------------------\n";

	//--------------------------------------------------------------------------------------------------------------

	// Question #4
	// Write a short program to simulate a ball being dropped off of a tower.
	// To start, the user should be asked for the height of the tower in meters.
	// Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
	// Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
	// The ball should not go underneath the ground (height 0).

	// Use a function to calculate the height of the ball after x seconds.
	// The function can calculate how far the ball has fallen after x seconds using the following formula:
	// distance fallen = gravity_constant * x_seconds2 / 2

	questionFour();
	
	return 0;
}