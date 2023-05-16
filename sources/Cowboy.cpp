#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(std::string name, Point location)
        : Character(name, location, 110), bullets(6) {}

    void Cowboy::shoot(Character *enemy)
    {
    }

    bool Cowboy::hasBullets() const
    {
        return true;
    }

    void Cowboy::reload()
    {
    }

    std::string Cowboy::print() const
    {
        return "";
    }
}
