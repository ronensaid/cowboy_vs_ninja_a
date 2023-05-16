#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <string>
namespace ariel
{

    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(std::string name, Point location);

        void shoot(Character *enemy) override;
        bool hasBullets() const;
        void reload() override;
        std::string print() const override;
    };

}

#endif /* COWBOY_HPP */
