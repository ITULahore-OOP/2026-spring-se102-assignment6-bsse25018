#include "Hero.h"
#include "Warrior.h"
#include "Knight.h"
#include "Guild.h"
#include "MagicalEntity.h"
#include "SpellBlade.h"
#define RESET "\033[0m"  // Color Codes/Ansii Escape codes for console colors
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
// In this assignment, I declared arrays to store the Hero objects and then assigned them to the pointer array in the Guild class.
// Previously, when two heroes were created, the second hero was printed for both due to pointer referencing.
// To fix this issue arrays are declared here so that each hero has its own separate object in memory.
int choice;
void guildMenu(Guild &guild) // Made a Menu FUNCTION for simplicity
{
    int a, b, choice;
    // Arrays are declared to store Hero, Warrior, Knight, and SpellBlade objects.
    // These objects are then passed as pointers to the Guild class.
    // This prevents overwriting objects when multiple heroes are created.
    Hero heroes[15];
    Warrior warriors[15];
    Knight knights[15];
    SpellBlade spellblade[15];

    int totalHeroes = 0;
    int totalWarriors = 0;
    int totalKnights = 0;
    int totalSpellBlades = 0;

    do
    {
        cout << CYAN
             << endl
             << "========================================" << endl;
        guild.displayGuildStats();
        cout << "========================================" << endl
             << RESET;

        cout << MAGENTA
             << endl
             << "========== GUILD MENU ==========" << endl
             << RESET;

        cout << GREEN
             << "1. Add Hero" << endl
             << "2. Add Warrior" << endl
             << "3. Add Knight" << endl
             << "4. Add SpellBlade" << endl
             << "5. Show Guild Status" << endl
             << "6. Give Damage" << endl
             << "7. Compare Two Heroes" << endl
             << "8. Add Powers of Two Heroes" << endl
             << "0. Exit Guild Menu" << endl
             << RESET;

        cout << YELLOW << endl
             << "Enter Choice: " << RESET;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string heroName;
            int health;
            int basePower;

            cout << BLUE << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin, heroName);
            cout << BLUE << "Enter Health: " << RESET;
            cin >> health;
            cout << BLUE << "Enter Base Power: " << RESET;
            cin >> basePower;

            heroes[totalHeroes] = Hero(heroName, health, basePower);
            guild += &heroes[totalHeroes];

            totalHeroes++;

            cout << GREEN << "Hero Added Successfully" << endl
                 << RESET;
            break;
        }

        case 2:
        {
            string heroName;
            int health;
            int basePower;
            int armor;

            cout << BLUE << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin, heroName);

            cout << BLUE << "Enter Health: " << RESET;
            cin >> health;

            cout << BLUE << "Enter Base Power: " << RESET;
            cin >> basePower;

            cout << BLUE << "Enter Armor Rating: " << RESET;
            cin >> armor;

            warriors[totalWarriors] =
                Warrior(heroName, health, basePower, armor);

            guild += &warriors[totalWarriors];
            cout << YELLOW << "Warrior's Special Abbility: " << RESET << endl;
            cout << CYAN
                 << "Effective Health: "
                 << warriors[totalWarriors].calculateEffectiveHealth()
                 << endl
                 << RESET;
            totalWarriors++;
            cout << GREEN << "Warrior Added Successfully" << endl
                 << RESET;
            break;
        }

        case 3:
        {
            string heroName;
            int health;
            int basePower;
            int armor;
            int charge;

            cout << BLUE << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin, heroName);

            cout << BLUE << "Enter Health: " << RESET;
            cin >> health;

            cout << BLUE << "Enter Base Power: " << RESET;
            cin >> basePower;

            cout << BLUE << "Enter Armor Rating: " << RESET;
            cin >> armor;

            cout << BLUE << "Enter Charge Bonus: " << RESET;
            cin >> charge;

            knights[totalKnights] =
                Knight(heroName, health, basePower, 10, 10);

            guild += &knights[totalKnights];
            cout << YELLOW << "Knight's Special Abbility: " << RESET << endl;
            cout << CYAN
                 << "Burst Damage: "
                 << knights[totalKnights].calculateBurstDamage()
                 << endl
                 << RESET;
            totalKnights++;
            cout << GREEN << "Knight Added Successfully" << endl
                 << RESET;
            break;
        }

        case 4:
        {
            string heroName;
            int health;
            int basePower;
            int armor;
            int mana;
            int spell;

            cout << BLUE << "Enter Name: " << RESET;
            cin.ignore();
            getline(cin, heroName);

            cout << BLUE << "Enter Health: " << RESET;
            cin >> health;

            cout << BLUE << "Enter Base Power: " << RESET;
            cin >> basePower;

            cout << BLUE << "Enter Armor Rating: " << RESET;
            cin >> armor;

            cout << BLUE << "Enter Mana Pool: " << RESET;
            cin >> mana;

            cout << BLUE << "Enter Spell Power: " << RESET;
            cin >> spell;

            spellblade[totalSpellBlades] =
                SpellBlade(heroName, health, basePower, 10, 10, 10);

            guild += &spellblade[totalSpellBlades];
            cout << YELLOW << "Spell Blade's Special Abbility: " << RESET << endl;
            cout << CYAN
                 << "Hybrid Damage: "
                 << spellblade[totalSpellBlades].calculateHybridDamage()
                 << endl
                 << RESET;
            totalSpellBlades++;
            cout << GREEN << "Warrior Added Successfully" << endl
                 << RESET;
            break;
        }

        case 5:
        {
            cout << CYAN;
            cout << guild;
            cout << RESET;
            break;
        }

        case 6:
        {
            if (guild.getMemberCount() == 0)
            {
                cout << RED
                     << "Add Heroes First!! Members: 0"
                     << endl
                     << RESET;
                break;
            }

            if (guild.getMemberCount() == 1)
            {
                cout << RED
                     << "At least Two Members Required"
                     << endl
                     << RESET;
                break;
            }

            cout << YELLOW << "Attacker Index: " << RESET;
            cin >> a;

            cout << YELLOW << "Defender Index: " << RESET;
            cin >> b;

            guild.getHero(b)->takeDamage(
                guild.getHero(a)->getPower());

            cout << RED
                 << guild.getHero(b)->getName()
                 << " took damage!"
                 << endl;

            cout << "Health Now: "
                 << guild.getHero(b)->getHealth()
                 << endl
                 << RESET;

            break;
        }

        case 7:
        {
            if (guild.getMemberCount() < 2)
            {
                cout << RED
                     << "Need Two Heroes"
                     << endl
                     << RESET;
                break;
            }

            cout << YELLOW << "First Index: " << RESET;
            cin >> a;

            cout << YELLOW << "Second Index: " << RESET;
            cin >> b;

            if (*guild.getHero(a) > *guild.getHero(b))
                cout << GREEN
                     << guild.getHero(a)->getName()
                     << " is stronger"
                     << endl
                     << RESET;
            else if (*guild.getHero(b) > *guild.getHero(a))
                cout << GREEN
                     << guild.getHero(b)->getName()
                     << " is stronger"
                     << endl
                     << RESET;
            else
                cout << CYAN
                     << "Both Equal"
                     << endl
                     << RESET;

            break;
        }

        case 8:
        {
            if (guild.getMemberCount() < 2)
            {
                cout << RED
                     << "Need Two Heroes"
                     << endl
                     << RESET;
                break;
            }

            cout << YELLOW << "First Index: " << RESET;
            cin >> a;

            cout << YELLOW << "Second Index: " << RESET;
            cin >> b;

            cout << MAGENTA
                 << "Combined Power: "
                 << (*guild.getHero(a) + *guild.getHero(b))
                 << endl
                 << RESET;

            break;
        }
        default:
        {
            cout << RED << "You Entered Wrong Option,Select from Given Options " << RESET << endl;
            break;
        }
        }

    } while (choice != 0);
}

int main()
{

    string name;
    int choice;

    cout << CYAN << "=========================================================" << endl;
    cout << GREEN
         << "\t\tHellloo Youu!!! " << endl;
    cout << YELLOW
         << "\tAssignment No:6 |Roll Number: BSSE-25018 " << endl;

    cout << CYAN << "=========================================================" << endl;

    cout << MAGENTA << "\tGuildd Build For Kingdom Of Eldoria " << endl;

    cout << CYAN << "=========================================================" << endl;
    cout << endl;
    cout << BLUE << "Create A New Guild." << endl;
    cout << YELLOW << "Enter Name of Guild: " << RESET;
    getline(cin, name);
    cout << CYAN << "Processing Please wait........" << endl;
    cout << CYAN << "Asking Newton for Help........" << endl;
    Guild guild(name);
    cout << GREEN
         << "Congratulations Guild with Name: " << guild.getName() << endl;

    cout << CYAN << "=========================================================" << endl;

    cout << MAGENTA << "Proceedingg to Main Menu " << endl;

    do
    {
        cout << GREEN
             << "1. Guild Menuu(to add heroes,warriors,knights,spellblade)"
             << endl;

        cout << GREEN
             << "2. Written text to tell implementation of Inheritance and Operator Overloading "
             << endl;

        cout << GREEN
             << "0. Exit Programm!!..."
             << endl;

        cout << YELLOW
             << "Enter Yourr Choiceee."
             << RESET << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            guildMenu(guild);
            break;
        }

        case 2:
        {
            cout << CYAN << "Inheritance:" << endl;

            cout << WHITE
                 << "Hero is the base class with common attributes like name, health, and power." << endl;

            cout << WHITE
                 << "Derived classes (Warrior, Knight, SpellBlade) extend Hero and implement special abilities such as armor, charge bonus, and hybrid damage." << endl;

            cout << CYAN
                 << "Operator OverLoading: " << endl;

            cout << WHITE
                 << "> operator is overloaded to compare heroes based on power or effective health." << endl;

            cout << WHITE
                 << "+ operator is overloaded to combine powers of two heroes."
                 << endl;

            cout << WHITE
                 << "+= operator is used to add Heroes,Knights,Warriors,Spell Blades "
                 << endl;

            break;
        }

        case 0:
        {
            cout << RED
                 << "Thankkk Youu Andd Gooodd Byeee Youuu!!!! "
                 << endl;
        }
        default:
        {
            cout << RED << "You Entered Wrong Option,Select from Given Options " << RESET << endl;
            break;
        }
        }
    } while (choice != 0);
    return 0;
}