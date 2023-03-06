#include <iostream>
#include <bitset>												// for std::bitset

int main()
{
	std::bitset<8> mybitset{};
	
	std::bitset<8> bitset{ 0b0000'0101 };						// we need 8 bits, start with bit pattern 0000 0101
	bitset.set(3);												// set bit position 3 to 1 (now we have 0000 1101)
	bitset.flip(4);												// flip bit 4 (now we have 0001 1101)
	bitset.reset(4);											// set bit 4 back to 0 (now we have 0000 1101)

	std::cout << "All the bits: " << bitset << '\n';
	std::cout << "bit 3 has value: " << bitset.test(3) << '\n';
	std::cout << "bit 4 has value: " << bitset.test(4) << '\n';

	//-----------------------------------------------------------------------------------------------------------

	// The size of std::bitset
	// One potential surprise is that std::bitset is optimized for speed, not memory savings. 
	// The size of a std::bitset is typically the number of bytes needed to hold the bits, rounded up to the nearest sizeof(size_t),
	// which is 4 bytes on 32-bit machines, and 8-bytes on 64-bit machines.

	// Thus, a std::bitset<8> will typically use either 4 or 8 bytes of memory,
	// even though it technically only needs 1 byte to store 8 bits.
	// Thus, std::bitset is most useful when we desire convenience, not memory savings.

	
	return 0;
}