#include "Guild.h"
Guild::Guild(string name) : guildName(name)
{
    memberCount = 0;
    for (int i = 0; i < 15; i++)
    {
        roster[i] = nullptr; // Initializing with nullptr
    }
}
Guild::~Guild()
{
    //  delete here because  we were asked to do in docx otherwise it will not work
    //  cozz there is no memory allocation it will give segmentation fault
    // for (int i = 0; i < memberCount; i++) {
    //      delete roster[i];
    //}

    cout << "The guild " << guildName << " has been disbanded!" << endl;
};
int Guild::calculateTotalGuildPower()
{
    int totalpower = 0;

    for (int i = 0; i < memberCount; i++)
    {
        totalpower += roster[i]->getPower();
    }

    return totalpower;
};
void Guild::displayGuildStats()
{

    cout << "Guild Name: " << guildName << endl;
    cout << "Total Members: " << memberCount << "/15" << endl;
    cout << "Total Guild Power: " << calculateTotalGuildPower() << endl;
}
void Guild::operator+=(Hero *newHero)
{
    if (memberCount < 15)
    {
        roster[memberCount] = newHero;
        memberCount++;
    }
    else
    {
        cout << "Guild is at full capacity!" << endl;
    }
};
ostream &operator<<(ostream &os, Guild &g)
{

    os << "Guild: " << g.guildName << endl;
    os << "Members: " << g.memberCount << endl;

    for (int i = 0; i < g.memberCount; i++)
    {
        os << "- " << g.roster[i]->getName()
           << " (Power: "
           << g.roster[i]->getPower()
           << ")" << endl;
    }

    return os;
}
string Guild::getName()
{
    return guildName;
}
// This is an extra getter i made to get the value stored at the particular index in roster array
Hero *Guild::getHero(int index)
{
    if (index >= 0 && index < memberCount)
        return roster[index];

    return NULL;
}

int Guild::getMemberCount()
{
    return memberCount;
}