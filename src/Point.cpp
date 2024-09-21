#include "Point.h"

Point::Point()
{
    //ctor
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    //dtor
}


double Point::getX()
{
    return this->x;
}

double Point::getY()
{
    return this->y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

double toRadians(double degrees)
{
    return degrees * 0.017453293;
}

void Point::rotate(int degrees)
{
    double radians = toRadians(degrees);
    printf("this->x %f\n", this->x);
    printf("this->y %f\n", this->y);
    this->x = this->x * cos(radians) - this->y * sin(radians);
    this->y = this->x * sin(radians) + this->y * cos(radians);
    printf("this->x %f\n", this->x);
    printf("this->y %f\n", this->y);
    printf("--=---=--=-=-=", this->y);
}

