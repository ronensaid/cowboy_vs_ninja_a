#include "OldNinja.hpp"

namespace ariel
{

    OldNinja::OldNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 8, 150)
    {
    }

    void OldNinja::move(Character *enemy)
    {
    }

    void OldNinja::slash(Character *enemy)
    {

    } 
    std::string OldNinja::print() const
    {
        return "";
    }
}