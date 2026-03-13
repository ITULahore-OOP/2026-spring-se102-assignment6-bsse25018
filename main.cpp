#include "Hero.h"
#include "Warrior.h"
#include "Knight.h"
#include "Guild.h"
#include "MagicalEntity.h"
#include "SpellBlade.h"
#define RESET   "\033[0m"  
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
int choice;
void guildMenu(Guild &guild)
{
    int a, b, choice;
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
        cout << "=====================================" << endl;
        guild.displayGuildStats();
        cout << "=====================================" << endl;
        cout << "========Guild Menu==========" << endl;
        cout << "1.Add Hero " << endl;
        cout << "2.Add Warrior " << endl;
        cout << "3.Add Knight " << endl;
        cout << "4.Add Spellblade " << endl;
        cout << "5.Show Guild Status " << endl;
        cout << "6.Give Damage " << endl;
        cout << "7.Compare Two Heroes " << endl;
        cout << "8.Add Powers of two Heroes " << endl;
        cout << "0.Exit Guild Menu " << endl;
        cout << "Enter Yourr choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string heroName;
            int health;
            int basePower;
            cout << "Enterr Name: " << endl;
            cin.ignore();
            getline(cin, heroName);
            cout << "Enterr Health: " << endl;
            cin >> health;
            cout << "Enterr Basee Powerr: " << endl;
            cin >> basePower;
            heroes[totalHeroes] = Hero(heroName, health, basePower); // store in array
            guild += &heroes[totalHeroes];                           // add pointer to guild
            totalHeroes++;

            cout << "Hero Created Successfully " << endl;
            break;
        }
        case 2:
        {
            string heroName;
            int health;
            int basePower;
            int armor;
            cout << "Enterr Name: " << endl;
            cin.ignore();
            getline(cin, heroName);
            cout << "Enterr Health: " << endl;
            cin >> health;
            cout << "Enterr Basee Powerr: " << endl;
            cin >> basePower;
            cout << "Enterr Armor Rating: " << endl;
            cin >> armor;
            warriors[totalWarriors] = Warrior(heroName, health, basePower, armor);
            guild += &warriors[totalWarriors];

            cout << "Effective Healthh: " << warriors[totalWarriors].calculateEffectiveHealth() << endl;
            totalWarriors++;
            break;
        }
        case 3:
        {
            string heroName;
            int health;
            int basePower;
            int armor;
            int charge;
            cout << "Enterr Name: " << endl;
            cin.ignore();
            getline(cin, heroName);
            cout << "Enterr Health: " << endl;
            cin >> health;
            cout << "Enterr Basee Powerr: " << endl;
            cin >> basePower;
            cout << "Enterr Armor Rating: " << endl;
            cin >> armor;
            cout << "Enterr Charge Bonus : " << endl;
            cin >> charge;
            knights[totalKnights] = Knight(heroName, health, basePower, 10, 10);
            guild += &knights[totalKnights];

            cout << "Burst Damagee: " << knights[totalKnights].calculateBurstDamage() << endl;
            totalKnights++;
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
            cout << "Enterr Name: " << endl;
            cin.ignore();
            getline(cin, heroName);
            cout << "Enterr Health: " << endl;
            cin >> health;
            cout << "Enterr Basee Powerr: " << endl;
            cin >> basePower;
            cout << "Enterr Armor Rating: " << endl;
            cin >> armor;
            cout << "Enterr Manaa Pool: " << endl;
            cin >> mana;
            cout << "Enterr Spell Power: " << endl;
            cin >> spell;
            spellblade[totalSpellBlades] = SpellBlade(heroName, health, basePower, 10, 10, 10);
            guild += &spellblade[totalSpellBlades];
            cout << "Hybrid Damagee: " << spellblade[totalSpellBlades].calculateHybridDamage() << endl;
            totalSpellBlades++;
            break;
        }
        case 5:
        {
            cout << guild;
            break;
        }

        case 6:
        { // takeDamage
            if (guild.getMemberCount() == 0)
            {
                cout << "Add Heroes First!! Members:0 " << endl;
                break;
            }
            if (guild.getMemberCount() == 1)
            {
                cout << "Atleast Two Members are Required: " << endl;
                break;
            }
            cout << "Enter attacker index:(0-14) ";
            cin >> a;
            while (a > (guild).getMemberCount())
            {
                cout << "Slott Emptyy,Enter Again " << endl;
                cin >> a;
            }
            cout << "Enter defender index:(0-14) ";
            cin >> b;
            while (b > (guild).getMemberCount())
            {
                cout << "Slott Emptyy,Enter Again " << endl;
                cin >> b;
            }
            guild.getHero(b)->takeDamage(
                guild.getHero(a)->getPower());

            cout << guild.getHero(b)->getName()
                 << " took damage!" << endl;
            cout << "Health Now: " << guild.getHero(b)->getHealth();
            break;
        }

        case 7:
        { // operator >
            if (guild.getMemberCount() == 0)
            {
                cout << "Add Heroes First!! Members:0 " << endl;
                break;
            }
            if (guild.getMemberCount() == 1)
            {
                cout << "Atleast Two Members are Required: " << endl;
                break;
            }
            cout << "Enter first hero index:(0-14) ";
            cin >> a;
            while (a > (guild).getMemberCount())
            {
                cout << "Slott Emptyy,Enter Again " << endl;
                cin >> a;
            }
            cout << "Enter second hero index:(0-14) ";
            cin >> b;
            while (b > (guild).getMemberCount())
            {
                cout << "Slott Emptyy,Enter Again " << endl;
                cin >> b;
            }

            if (*guild.getHero(a) > *guild.getHero(b))
                cout << guild.getHero(a)->getName()
                     << " is stronger" << endl;
            else if (*guild.getHero(b) > *guild.getHero(a))
                cout << guild.getHero(b)->getName()
                     << " is stronger" << endl;
            else
            {
                cout << "Both Are Equall " << endl;
            }
            break;
        }

        case 8:
        { // operator +
            if (guild.getMemberCount() == 0)
            {
                cout << "Add Heroes First!! Members:0 " << endl;
                break;
            }
            if (guild.getMemberCount() == 1)
            {
                cout << "Atleast Two Members are Required: " << endl;
                break;
            }
            cout << "Enter first hero index:(0-14) ";
            cin >> a;
            while (a > (guild).getMemberCount())
            {
                cout << "Slott Emptyy,Enter Again " << endl;
                cin >> a;
            }
            cout << "Enter second hero index:(0-14) ";
            cin >> b;
            while (b > (guild).getMemberCount())
            {
                cout << "Slott Emptyy,Enter Again " << endl;
                cin >> b;
            }

            cout << "Combined Power: "
                 << (*guild.getHero(a) + *guild.getHero(b))
                 << endl;

            break;
        }
        }

    } while (choice != 0);
}

int main()
{
    string name;
    int choice;
    cout << "=========================================================" << endl;
    cout << "\t\tHellloo Youu!!! " << endl;
    cout << "\tAssignment No:6 |Roll Number: BSSE-25018 " << endl;
    cout << "=========================================================" << endl;
    cout << "\tGuildd Build For Kingdom Of Eldoria " << endl;
    cout << "=========================================================" << endl;
    cout << endl;
    cout << "Create A New Guild." << endl;
    cout << "Enter Name of Guild: " << endl;
    getline(cin, name);
    cout << "Processing Please wait........" << endl;
    cout << "Asking Newton for Help........" << endl;
    Guild guild(name);
    cout << "Congratulations Guild with Name: " << guild.getName() << endl;
    cout << "=========================================================" << endl;
    cout << "Proceedingg to Main Menu " << endl;

    do
    {
        cout << "1.Guild Menuu(to add heroes,warriors,knights,spellblade)" << endl;
        cout << "2. Written text to tell implementation of Inheritance and Operator Overloading " << endl;
        cout << "0. Exit Programm!!..." << endl;
        cout << "Enter Yourr Choiceee." << endl;
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
            cout << "Inheritance:" << endl;
            cout << "Hero is the base class with common attributes like name, health, and power." << endl;
            cout << "Derived classes (Warrior, Knight, SpellBlade) extend Hero and implement special abilities such as armor, charge bonus, and hybrid damage." << endl;
            cout << "Operator OverLoading: " << endl;
            cout << "> operator is overloaded to compare heroes based on power or effective health." << endl;
            cout << "+ operator is overloaded to combine powers of two heroes." << endl;
            cout << "+= operator is used to add Heroes,Knights,Warriors,Spell Blades "<<endl;
            break;
        }
        case 0:
        {
            cout << "Thankkk Youu Andd Gooodd Byeee Youuu!!!! " << endl;
        }
        default:
            break;
        }

    } while (choice != 0);

    return 0;
}