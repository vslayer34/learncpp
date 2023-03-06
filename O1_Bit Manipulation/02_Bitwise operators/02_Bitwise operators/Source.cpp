#include <iostream>
#include <bitset>

int main()
{
	// The bitwise operators

	// Operator			Symbol		Form		Operation
	// left shift		<<			x << y		all bits in x shifted left y bits
	// right shift		>>			x >> y		all bits in x shifted right y bits
	// bitwise NOT		~			~x			all bits in x flipped
	// bitwise AND		&			x & y		each bit in x AND each bit in y
	// bitwise OR		|			x | y		each bit in x OR each bit in y
	// bitwise XOR		^			x ^ y		each bit in x XOR each bit in y


	//-------------------------------------------------------------------------------------------------------

	// Bitwise left shift (<<) and bitwise right shift (>>) operators

	// The bitwise left shift (<<) operator shifts bits to the left.
	// The left operand is the expression to shift the bits of, and the right operand is an integer number of bits to shift left by.
	
	// So when we say x << 1, we are saying “shift the bits in the variable x left by 1 place”.
	// New bits shifted in from the right side receive the value 0.

	// So when we say x << 1, we are saying “shift the bits in the variable x left by 1 place”. New bits shifted in from the right side receive the value 0.

	// 0011 << 1 is 0110
	// 0011 << 2 is 1100
	// 0011 << 3 is 1000

	// Note that in the third case, we shifted a bit off the end of the number! Bits that are shifted off the end of the binary number are lost forever.
	// 
	// The bitwise right shift (>>) operator shifts bits to the right.

	// 1100 >> 1 is 0110
	// 1100 >> 2 is 0011
	// 1100 >> 3 is 0001
	// 
	// Note that in the third case we shifted a bit off the right end of the number, so it is lost.

	// Here’s an example of doing some bit shifting:
	std::bitset<4> x1{ 0b1100 };

	std::cout << x1 << '\n';
	std::cout << (x1 >> 1) << '\n';											// shift right by 1, yielding 0110
	std::cout << (x1 << 1) << '\n';											// shift left by 1, yielding 1000
	std::cout << '\n';

	//-------------------------------------------------------------------------------------------------------
	
	// Bitwise NOT
	// The bitwise NOT operator (~) is perhaps the easiest to understand of all the bitwise operators.
	// It simply flips each bit from a 0 to a 1, or vice versa.
	// Note that the result of a bitwise NOT is dependent on what size your data type is.

	// Flipping 4 bits:
	// ~0100 is 1011

	// Flipping 8 bits:
	// ~0000 0100 is 1111 1011

	// In both the 4-bit and 8-bit cases, we start with the same number (binary 0100 is the same as 0000 0100 in the same way that decimal 7 is the same as 07),
	// but we end up with a different result.

	// We can see this in action in the following program:
	std::cout << std::bitset<4>{ 0b0100 } << ' ' << ~std::bitset<8> { 0b0100 } << '\n';
	std::cout << '\n';

	//-------------------------------------------------------------------------------------------------------

	// Bitwise OR
	// Bitwise OR (|) works much like its logical OR counterpart.
	// However, instead of applying the OR to the operands to produce a single result, bitwise OR applies to each bit! 
	// For example, consider the expression 0b0101 | 0b0110.
	
	// To do (any) bitwise operations, it is easiest to line the two operands up like this:
	// 0 1 0 1 OR
	// 0 1 1 0
	
	// If you remember, logical OR evaluates to true (1) if either the left, right, or both operands are true (1), and 0 otherwise.
	// Bitwise OR evaluates to 1 if either the left, right, or both bits are 1, and 0 otherwise. 
	// Consequently, the expression evaluates like this:
	// 0 1 0 1 OR
	// 0 1 1 0
	// -------
	// 0 1 1 1

	// Our result is 0111 binary.
	std::cout << (std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 }) << '\n';

	// We can do the same thing to compound OR expressions, such as 0b0111 | 0b0011 | 0b0001.
	// If any of the bits in a column are 1, the result of that column is 1.
	// 0 1 1 1 OR
	// 0 0 1 1 OR
	// 0 0 0 1
	// --------
	// 0 1 1 1

	// Here’s code for the above:
	std::cout << (std::bitset<4>{ 0b0111 } | std::bitset<4>{ 0b0011 } | std::bitset<4>{ 0b0001 }) << '\n';
	std::cout << '\n';

	//-------------------------------------------------------------------------------------------------------

	// Bitwise AND
	// Bitwise AND (&) works similarly to the above. 
	// Logical AND evaluates to true if both the left and right operand evaluate to true. 
	// Bitwise AND evaluates to true (1) if both bits in the column are 1.
	// Consider the expression 0b0101 & 0b0110.
	// Lining each of the bits up and applying an AND operation to each column of bits:
	
	// 0 1 0 1 AND
	// 0 1 1 0
	// --------
	// 0 1 0 0

	std::cout << (std::bitset<4>{ 0b0101 } &std::bitset<4>{ 0b0110 }) << '\n';

	// Similarly, we can do the same thing to compound AND expressions, such as 0b0001 & 0b0011 & 0b0111.
	// If all of the bits in a column are 1, the result of that column is 1.
	// 0 0 0 1 AND
	// 0 0 1 1 AND
	// 0 1 1 1
	// --------
	// 0 0 0 1
	std::cout << (std::bitset<4>{ 0b0001 } &std::bitset<4>{ 0b0011 } &std::bitset<4>{ 0b0111 }) << '\n';
	std::cout << '\n';

	//-------------------------------------------------------------------------------------------------------

	// Bitwise XOR
	// When evaluating two operands, XOR evaluates to true (1) if one and only one of its operands is true (1). 
	// If neither or both are true, it evaluates to 0. 
	// Consider the expression 0b0110 ^ 0b0011:
	// 0 1 1 0 XOR
	// 0 0 1 1
	// -------
	// 0 1 0 1

	// It is also possible to evaluate compound XOR expression column style, such as 0b0001 ^ 0b0011 ^ 0b0111. 
	// If there are an even number of 1 bits in a column, the result is 0.
	// If there are an odd number of 1 bits in a column, the result is 1.
	// 0 0 0 1 XOR
	// 0 0 1 1 XOR
	// 0 1 1 1
	// --------
	// 0 1 0 1

	//-------------------------------------------------------------------------------------------------------

	// Bitwise assignment operators
	// Similar to the arithmetic assignment operators, C++ provides bitwise assignment operators in order to facilitate easy modification of variables.

	// Operator					Symbol	Form		Operation
	// Left shift assignment	<<=		x <<= y		Shift x left by y bits
	// Right shift assignment	>>=		x >>= y		Shift x right by y bits
	// Bitwise OR assignment	|=		x |= y		Assign x | y to x
	// Bitwise AND assignment	&=		x &= y		Assign x & y to x
	// Bitwise XOR assignment	^=		x ^= y		Assign x ^ y to x

	// For example, instead of writing x = x >> 1;, you can write x >>= 1;.
	std::bitset<4> bits{ 0b0100 };
	bits >>= 1;
	std::cout << bits << '\n';
	std::cout << '\n';

	
	return 0;
}