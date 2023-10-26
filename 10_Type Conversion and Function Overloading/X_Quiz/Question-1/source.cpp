#include <iostream>



int main()
{
    // Question I.
    // What type of conversion happens in each of the following cases?
    // Valid answers are: No conversion needed, numeric promotion, numeric conversion, won’t compile due to narrowing conversion.
    // Assume int and long are both 4 bytes.
    {
        int a { 5 };                            // 1a:      No Conversion Needed
        int b { 'a' };                          // 1b:      Numeric Promotion
        /*int c { 5.4 };                          // 1c:      Won't Compile due to Narrowing Conversion*/
        int d { true };                         // 1d:      Numeric Promotion
        int e { static_cast<int>(5.4) };        // 1e:      Numeric Conversion

        double f { 5.0f };                      // 1f:      Numeeric Promotion
        double g { 5.0 };                       // 1g:      No Conversion Needed

        // Extra credit section
        long h { 5 };                           // 1h:      Numeric Promotion

        /*float i { f };                          // 1i (uses previously defined variable f): Won't Compile due to Narrowing Conversion*/
        float j { 5.0 };                        // 1j:      Numeric Conversion
    }

    //---------------------------------------------------------------------------------------------
}