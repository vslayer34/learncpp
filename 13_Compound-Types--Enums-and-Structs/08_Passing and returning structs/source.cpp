#include <iostream>
#include <string>

void printEmployee(int id, int age, double wage)
{
    std::cout << "ID: " << id << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Wage: " << wage << '\n';
}

struct Employee
{
    std::string_view name { };
    int id { };
    int age { };
    double wage { };
};

struct Point3d
{
    double x { };
    double y { };
    double z { };
};

Point3d getOriginPoint()
{
    return Point3d { };
    // we can also return
    // return { .x = 0.0, .y = 0.0, .z = 0.0 };
    // return { 0.0, 0.0, 0.0 };
    // return { };
}

// note pass by reference here
void printEmployee(const Employee& employee)
{
    std::string_view title = "Employee Details";
    
    std::cout << title << '\n';
    std::cout << std::string(title.size(), '=') << '\n';

    std::cout << "Name: " << employee.name << '\n';
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

struct AdvertisingRevenue
{
    int howManyAds { };
    double adsClickedPercentage { };
    double averageEarningPerAd { };
};

struct Fraction
{
    int numerator { };
    int denominator { };
};

AdvertisingRevenue getAdvertisingAnalytics()
{
    AdvertisingRevenue adsData { };

    std::cout << "How many ads were watched: ";
    std::cin >> adsData.howManyAds;

    std::cout << "What percentage of users clicked on an ad: ";
    std::cin >>  adsData.adsClickedPercentage;

    std::cout << "The average earnings per clicked ad: ";
    std::cin >> adsData.averageEarningPerAd;

    return adsData;
}

double getRevenueMade(AdvertisingRevenue data)
{
    return data.howManyAds * data.adsClickedPercentage * data.averageEarningPerAd;
}

void displayAdsReport(AdvertisingRevenue data)
{
    std::cout << "Number of ads shown: " << data.howManyAds << '\n';
    std::cout << "Click rate: " << data.adsClickedPercentage << '\n';
    std::cout << "Average earning per ad: " << data.averageEarningPerAd << "$" << '\n';

    std::cout << "Total Earnings: " << getRevenueMade(data) << '\n';
}

int main()
{
    // Consider an employee represented by 3 loose variables:
    {
        int id { 1 };
        int age { 24 };
        double wage { 52400.0 };

        // If we want to pass this employee to a function, we have to pass three variables:
        printEmployee(id, age, wage);
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Passing structs (by reference)
    {
        Employee joe { .name = "Joe", .id = 14, .age = 32, .wage = 24.15 };
        Employee frank { .name = "Frank", .id = 15, .age = 28, .wage = 18.17 };

        // prints Joe's information
        printEmployee(joe);

        std::cout << '\n';

        // print frank's information
        printEmployee(frank);
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Returning structs
    // Consider the case where we have a function that needs to return a point in 3-dimensional Cartesian space.
    // Such a point has 3 attributes: an x-coordinate, a y-coordinate, and a z-coordinate.
    // But functions can only return one value. So how do we return all 3 coordinates back the user?

    // One common way is to return a struct:
    {
        Point3d originPoint { getOriginPoint() };

        if (originPoint.x == 0.0 && originPoint.y == 0.0 && originPoint.z == 0.0)
        {
            std::cout << "This is the origin point" << '\n';
        }
        else
        {
            std::cout << "This anyother point but the origin point" << '\n';
        }
    }
    std::cout << std::string(70, '=') << '\n';

    // quiz time
    // Question #1
    // You are running a website, and you are trying to calculate your advertising revenue. Write a program that allows you to enter 3 pieces of data:
    //    How many ads were watched.
    //    What percentage of users clicked on an ad.
    //    The average earnings per clicked ad.

    // Store those 3 values in a struct.
    // Pass that struct to a function that prints each of the values.
    // The function should then calculate how much you made for that day (multiply the 3 fields together) and prints that value.
    {
        displayAdsReport(getAdvertisingAnalytics());
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Question #2

    // Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.
    // Write a function to read in a Fraction from the user, and use it to read-in two fraction objects.
    // Write another function to multiply two Fractions together and return the result as a Fraction (you don’t need to reduce the fraction).
    // Write another function that prints a fraction.
    {
        Fraction fraction1 { }, fraction2 { };
        
        std::cout << "Enter a value for the first numerator:   ";
        std::cin >> fraction1.numerator;
        std::cout << "Enter a value for the first denominator: ";
        std::cin >> fraction1.denominator;

        std::cout << "Enter a value for the second numerator:   ";
        std::cin >> fraction2.numerator;
        std::cout << "Enter a value for the second denominator: ";
        std::cin >> fraction2.denominator;

        Fraction resultFraction
        {
            .numerator = fraction1.numerator * fraction2.numerator,
            .denominator = fraction1.denominator * fraction2.denominator 
        };

        std::cout << "Your fractions multiplied together: " << resultFraction.numerator << "/" << resultFraction.denominator << '\n';
    }
}