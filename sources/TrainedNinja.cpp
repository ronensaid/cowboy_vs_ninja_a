#include "Ninja.hpp"
#include "TrainedNinja.hpp"

namespace ariel
{

    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name, location,  12,  120)
    {
    }

    void TrainedNinja::move(Character *enemy)
    {
    }

    void TrainedNinja::slash(Character *enemy)
    {
    }
    std::string TrainedNinja::print() const
    {

        return "";
    }
} 
