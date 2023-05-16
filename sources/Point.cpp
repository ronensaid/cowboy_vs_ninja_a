#include <cmath>
#include "Point.hpp"
using namespace ariel;

// Constructor
Point::Point(double pointx, double pointy) : pointx(pointx), pointy(pointy) {}

double Point::distance(const Point &other) const
{

    return 0;
}

void Point::print() const
{
}

Point Point::moveTowards(const Point &destination, double distance)
{
    return Point(0, 0);
}