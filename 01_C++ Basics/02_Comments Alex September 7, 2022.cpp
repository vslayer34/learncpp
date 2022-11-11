#include <iostream>

int main()
{
    std::cout << "Hello World!"; // Everything from here to the end of the line is ignored


    std::cout << "Hello World!\n"; // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n"; // these comments make the code hard to read
    std::cout << "yeah!"; // especially when lines are different lengths

    std::cout << "Hello World!\n";                  // std::cout lives in the iostream library
    std::cout << "It is very nice to meet you!\n";  // this is much easier to read
    std::cout << "yeah!";                           // don't you think so?

    // std::cout lives in the iostream library
    std::cout << "Hello world!\n";

    // this is much easier to read
    std::cout << "It is very nice to meet you!\n";

    // don't you think so?
    std::cout << "Yeah!\n";

    /*  This is a multi-line comment.
        This line will be ignored.
    So will this one. */

    /* This is a multi-line comment.
     * the matching asterisks to the left
     * can make this easier to read
     */
    
    // This program calculates the student's final grade based on their test and homework scores.
    // This function uses Newton's method to approximate the root of a given equation.
    // The following lines generate a random item based on rarity, level, and a weight factor.
    
    
    return 0;
}