#include "Utils.h"

Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

double Utils::toRadians(double degrees)
{
    return degrees * 0.017453293;
}

Point Utils::rotatePoint(Point p, double degrees)
{
    double radians = degrees * 0.017453293;
    return Point(
        p.getX() * cos(radians) - p.getY() * sin(radians),
        p.getX() * sin(radians) + p.getY() * cos(radians));
}

Point Utils::rotatePointByOrigin(Point origin, Point pointToRotate, double degrees)
{
    int newX = pointToRotate.getX() - origin.getX();
    int newY = pointToRotate.getY() - origin.getY();
    Point newPoint = rotatePoint(Point(newX, newY), degrees);
    newPoint.setX(newPoint.getX() + origin.getX());
    newPoint.setY(newPoint.getY() + origin.getY());
    return newPoint;
}
