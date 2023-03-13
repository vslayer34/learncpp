#pragma once

// define your own namespace to hold constants
namespace constants
{
	// constants have internal linkage by default
	constexpr double pi{ 3.14159 };
	constexpr double avogadro{ 6.0221413e23 };
	constexpr double myGravity{ 9.2 };										// m/s^2 -- gravity is light on this planet
	// ... other related constants
}

// Then use the scope resolution operator (::) with the namespace name to the left, and your variable name to the right in order to access your constants in.cpp files :