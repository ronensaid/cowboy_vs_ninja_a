#include "YoungNinja.hpp"

namespace ariel
{

    YoungNinja::YoungNinja(const std::string &name, const Point &location)
        : Ninja(name, location,  14,  100)
    {
    }

    void YoungNinja::move(Character *enemy)
    {
    }

    void YoungNinja::slash(Character *enemy)
    {
    }
    std::string YoungNinja::print() const
    {

        return "";
    }
} 
