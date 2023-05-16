#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"
#include <string>
namespace ariel
{

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location);

        void move(Character *enemy) override;
        void slash(Character *enemy) override;

        std::string print() const override;
    };
}

#endif /* YOUNGNINJA_HPP */