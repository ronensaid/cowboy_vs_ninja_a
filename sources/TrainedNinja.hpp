#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"
#include <string>
namespace ariel
{

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location);

        void move(Character *enemy) override;
        void slash(Character *enemy) override;
        
        std::string print() const override;
    };
}

#endif /* TRAINEDNINJA_HPP */
