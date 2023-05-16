#ifndef NINJA_HPP
#define NINJA_HPP

#include <string>
#include "Character.hpp" // Assuming there's a Character base class

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja();
        Ninja(const std::string &name, const Point &location, int speed, int hitPoints);
        void move(const Character *enemy);
        void slash(Character *enemy) override;
        std::string print() const override;
    };

}

#endif /* NINJA_HPP */
