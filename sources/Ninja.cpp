#include "Ninja.hpp"

namespace ariel
{

    Ninja::Ninja() : Character(), speed(0)
    {
    }

    Ninja::Ninja(const std::string &name, const Point &location, int speed, int hitPoints)
        : Character(name, location, hitPoints), speed(speed)
    {
    }

    void Ninja::move(const Character *enemy)
    {
    }

    void Ninja::slash(Character *enemy)
    {
    }
    std::string Ninja::print() const
    {
        return "";
    }

} 