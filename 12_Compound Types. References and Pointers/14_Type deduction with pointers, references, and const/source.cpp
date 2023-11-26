#include <iostream>

int getVal()                        // some fuction that returns an int
{
    return 6;
}

const double foo()
{
    return 5.6;
}

std::string& getRef()           // some function that returns a reference
{
    std::string name { "Rana" };
    return name;
}

const std::string& getConstRef()            // some function that returns a reference to a const
{
    return "Palestine";
}

constexpr std::string_view rana { "Rana" };

constexpr const std::string_view& getConstRef2()
{
    return rana;
}

std::string* getPtr();                      // some function that returns a pointer

int main()
{
    // In lesson 10.8 -- Type deduction for objects using the auto keyword, we discussed how the auto keyword can be used to have the compiler deduce the type of a variable from the initializer:
    {
        auto val { getVal() };      // val deduced as of type int
    }
    
    // We also noted that by default, type deduction will drop const (and constexpr) qualifiers:
    {
        const double cd { 7.8 };

        auto x { cd };              // double (const dropped)
        auto y { foo() };           // double (const dropped)
    }

    // Const (or constexpr) can be (re)applied by adding the const (or constexpr) qualifier in the definition:
    {
        constexpr double cd { 7.8 };

        const auto x { foo() };                     // const double (const dropped then reapplied)
        constexpr auto y { cd };                    // constexpr double (constexpr dropped then reapplied)
        const auto z { cd };                        // const double (constexpr dropped then const applied)
    }

    //---------------------------------------------------------------------------------------------

    // Type deduction drops references
    
    // In addition to dropping const qualifiers, type deduction will also drop references:
    {
        auto ref { getRef() };                      // type deduced as std::string (not std::strin&)
    }
    // In the above example, variable ref is using type deduction.
    // Although function getRef() returns a std::string&, the reference qualifier is dropped, so the type of ref is deduced as std::string.

    // Just like with the dropped const qualifier, if you want the deduced type to be a reference, you can reapply the reference at the point of definition:
    {
        auto ref1 { getRef() };                     // std::string (reference dropped)
        auto& ref2 { getRef() };                    // std::string& (reference dropped then reapplied)
    }

    //---------------------------------------------------------------------------------------------

    // Top-level const and low-level const
    // A top-level const is a const qualifier that applies to an object itself. For example:
    {
        const int x { };                            // this const applies to x, so it's top level
        int* const ptr { };                         // this const applies to ptr, so it is a top level
    }

    // In contrast, a low-level const is a const qualifier that applies to the object being referenced or pointed to:
    {
        const int& ref { };                         // this const applies to the object being referenced, so it's low level
        const int* ptr { };                         // this const applies to the object beomg pointer to, so it's low level
    }

    // A reference to a const value is always a low-level const. A pointer can have a top-level, low-level, or both kinds of const:
    {
        const int* const ptr { };                   // the left const is low level the right one is high level
    }

    // When we say that type deduction drops const qualifiers, it only drops top-level consts. Low-level consts are not dropped.

    //---------------------------------------------------------------------------------------------

    // Type deduction and const references

    // If the initializer is a reference to const (or constexpr), the reference is dropped first (and then reapplied if applicable)0
    // And then any top-level const is dropped from the result.
    {
        auto ref1 { getConstRef() };                // std::string (reference dropped then top-level const is dropped from the result)
    }

    // In the above example, since getConstRef() returns a const std::string&, the reference is dropped first, leaving us with a const std::string.
    // This const is now a top-level const, so it is also dropped, leaving the deduced type as std::string.

    // We can reapply either or both of these:
    {
        auto ref1 { getConstRef() };                // std::string (reference and top level const dropped)
        const auto ref2 { getConstRef() };          // const std::string (reference dropped, const reapplied)

        auto& ref3 { getConstRef() };               // const std::string& (reference reapplied, low level const didtn't drop)
        const auto& ref4 { getConstRef() };         // const std::string& (const and reference reapplied)
    }

    //---------------------------------------------------------------------------------------------

    // What about constexpr references?
    
    // These work the same way as const references:
    {
        auto ref1 { getConstRef2() };               // std::string_view (top level const and reference dropped)
        constexpr auto ref2 { getConstRef2() };     // constexpr std::string_view (constexpr reapplied, reference dropped)

        auto& ref3 { getConstRef2() };              // const std::string_view& (reference reapplied, top level const didn't drop)
        constexpr auto& ref4 { getConstRef2() };    // constexpr std::string_view& (reference reapplied, low level const not dropped constexpr reapplied)
    }

    //---------------------------------------------------------------------------------------------

    // Type deduction and pointers
    
    // Unlike references, type deduction does not drop pointers:
    {
        auto ptr1 { getPtr() };                     // std::string*
    }

    // We can also use an asterisk in conjunction with pointer type deduction:
    {
        auto ptr1 { getPtr() };                     // std::string*
        auto* ptr2 { getPtr() };                    // std::string*
    }
}