#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
namespace ariel
{

    class Point
    {
    private:
        double pointx;
        double pointy;

    public:
        Point(double pointx, double pointy);

        double distance(const Point &other) const;

        void print() const;

        Point moveTowards(const Point &destination, double distance);
    };
}
#endif /*POINT_HPP */