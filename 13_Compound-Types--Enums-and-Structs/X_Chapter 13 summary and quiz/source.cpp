#include <iostream>

enum class MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime
};

struct Enemy
{
    std::string name { };
    MonsterType type { };
    int health { };
};

std::ostream& operator<<(std::ostream& out, MonsterType enemy)
{
    switch (enemy)
    {
        case MonsterType::Ogre:             return out << "Ogre";
        case MonsterType::Dragon:           return out << "Dragon";
        case MonsterType::Orc:              return out << "Orc";
        case MonsterType::GiantSpider:      return out << "Giant Spider";
        case MonsterType::Slime:            return out << "Slime";
        default:                            return out << "??????";
    }
}

void printMonster(Enemy& enemyUnit)
{
    std::cout << "This " << enemyUnit.type << " is named " << enemyUnit.name << " and has " << enemyUnit.health << " health." << '\n';
}

template <typename T>
struct Triad
{
    T first { };
    T second { };
    T third { };
};

template <typename T>
Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& t)
{
    std::cout << "[" << t.first << ", " << t.second << ", " << t.third << "]" << '\n';
}

int main()
{
    // Question I
    // In designing a game, we decide we want to have monsters, because everyone likes fighting monsters.
    // Declare a struct that represents your monster.
    // The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime.
    // Use an enum class for this.

    // Each individual monster should also have a name (use a std::string or std::string_view), as well as an amount of health that represents how much damage they can take before they die.
    // Write a function named printMonster() that prints out all of the struct’s members.
    // Instantiate an ogre and a slime, initialize them using an initializer list, and pass them to printMonster().

    // Your program should produce the following output:
    // // // This Ogre is named Torg and has 145 health.
    // // // This Slime is named Blurp and has 23 health.
    {
        Enemy ogre
        {
            .name = "Torg",
            .type = MonsterType::Ogre,
            .health = 145
        };

        Enemy slime
        {
            .name = "Blurp",
            .type = MonsterType::Slime,
            .health = 23
        };

        printMonster(ogre);
        printMonster(slime);
    }
    std::cout << std::string(70, '=') << '\n';

    //---------------------------------------------------------------------------------------------

    // Question III
    // Create a class template named Triad that has 3 members of the same template type.
    // Also create a function template named print that can print a Triad. The following program should compile:
    {
        Triad<int> t1 { .first = 1, .second = 2, .third = 3 };
        print(t1);

        Triad<float> t2 { .first = 1.2f, .second = 3.4f, .third = 5.6f };
        print(t2);
    }
}