#include <iostream>


int main()
{
    // We’ve made much use of these fundamental types in our programs so far, especially the int data type.
    // And while these fundamental types are extremely useful for straightforward uses.
    // They don’t cover our full range of needs as we begin to do more complicated things.

    // For example, imagine you were writing a math program to multiply two fractions.
    // How would you represent a fraction in your program? You might use a pair of integers (one for the numerator, one for the denominator), like this:
    {
        // our first fraction
        int num1 { };
        int dem1 { };

        // our second fraction
        int num2 { };
        int dem2 { };

        // used to eat (remove) to slash between the numrator and denominator
        char ignor { };

        std::cout << "Enter a fraction: ";
        std::cin >> num1 >> ignor >> dem1;

        std::cout << "Enter a fraction: ";
        std::cin >> num2 >> ignor >> dem2;
        
        std::cout << "The two fraction multiplied: " << num1 * num2 << '/' << dem1 * dem2 << '\n';
    }
    std::cout << std::string(70, '-') << '\n';

    // While this program works, it introduces a couple of challenges for us to improve upon.
    // First, each pair of integers is only loosely linked -- outside of comments and the context of how they are used in the code,
    // there’s little to suggest that each numerator and denominator pair are related.
    // Second, following the DRY (don’t repeat yourself) principle, we should create a function to handle the user inputting a fraction (along with some error handling).
    // However, functions can only return a single value, so how would we return the numerator and denominator back to the caller?

    // Now imagine another case where you’re writing a program that needs to keep a list of employee IDs. How might you do so? You might try something like this:
    {
        int id1 { 42 };
        int id2 { 57 };
        int id3 { 162 };
        // and so on
    }

    // But what if you had 100 employees? First, you’d need to type in 100 variable names.
    // And what if you needed to print them all? Or pass them to a function? We’d be in for a lot of typing. This simply doesn’t scale.
}