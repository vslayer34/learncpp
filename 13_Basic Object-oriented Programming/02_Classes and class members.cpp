#include <iostream>
#include <string>

struct DateStruct
{
    int day {};
    int month {};
    int year {};
};

void print(const DateStruct &date)
{
    std::cout << date.day << " - " << date.month << " - " << date.year << std::endl;
}

// Same but as a class
class DateClass
{
    public:
        int m_day {};
        int m_month {};
        int m_year {};

        void print()
        {
            std::cout << m_day << " / " << m_month << " / " << m_year << std::endl;
        }
};

class Employee
{
public:
    std::string m_name {};
    int m_id {};
    double m_wage {};

    void printInfo()
    {
        std::cout << "Name: " << m_name << std::endl;
        std::cout << "ID: " << m_id << std::endl;
        std::cout << "Wage: " << m_wage << "$" << std::endl;
        std::cout << "***********************" << std::endl;
    }
};

int main()
{
    // DateStruct today { 28, 10, 2022 };
    // print(today);
    // today.day = 29;
    // print(today);

    DateClass today { 29, 10, 2022 };
    today.print();

    Employee alex { "Alex", 1, 25.0 };
    Employee joe { "Joe", 2, 22.25 };

    alex.printInfo();
    joe.printInfo();

    return 0;
}