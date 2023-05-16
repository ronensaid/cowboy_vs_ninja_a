#include "Character.hpp"
#include <iostream>

namespace ariel
{
    Character::Character() : name(""), location(Point(0, 0)), hitPoints(0)
    {
    }

    Character::Character(const std::string &name, const Point &location, int hitPoints)
        : name(name), location(location), hitPoints(hitPoints)
    {
    }
    bool Character::isAlive() const
    {
        return true;
    }

    double Character::distance(const Character &other) const
    {
        return location.distance(other.location);
    }

    void Character::hit(int damage)
    {
    }

    std::string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }
    std::string Character::print() const
    {
        return "";
    }
}