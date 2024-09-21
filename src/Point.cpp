#include "Point.h"

Point::Point()
{
    //ctor
}

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    //dtor
}


float Point::getX()
{
    return this->x;
}

float Point::getY()
{
    return this->y;
}

void Point::setX(float x)
{
    this->x = x;
}

void Point::setY(float y)
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

