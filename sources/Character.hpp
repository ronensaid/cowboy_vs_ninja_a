#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>
namespace ariel
{
    class Character
    {
    private:
        std::string name;
        Point location;
        int hitPoints;

    public:
        Character(); // Default constructor
        Character(const std::string &name, const Point &location, int hitPoints);
        virtual ~Character() = default;
        Character(const Character &other) = default;            // copy constructor
        Character &operator=(const Character &other) = default; // copy assignment operator
        Character(Character &&other) = default;                 // move constructor
        Character &operator=(Character &&other) = default;      // move assignment operator

        bool isAlive() const;
        double distance(const Character &other) const;
        void hit(int damage);
        std::string getName() const;
        Point getLocation() const;
        virtual std::string print() const;
        // Pure virtual functions for Cowboy and Ninja
        virtual void shoot(Character *enemy){};
        virtual void reload(){};
        virtual void move(Character *enemy){};
        virtual void slash(Character *enemy){};
    };
}
#endif
