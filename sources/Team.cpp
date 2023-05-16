#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *groupLeader) : leader(groupLeader)
    {
    }

    Team::~Team()
    {
    }

    void Team::add(Character *member)
    {
    }

    void Team::attack(Team *enemyGroup)
    {
    }

    int Team::stillAlive()
    {
        return 0;
    }

    std::string Team::print()
    {
        return "";
    }
}
