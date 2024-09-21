#ifndef UTILS_H
#define UTILS_H
#include<Point.h>


class Utils
{
    public:
        Utils();
        Point rotatePoint(Point p, double degrees);
        Point rotatePointByOrigin(Point origin, Point pointToRotate, double degrees);
        double toRadians(double degrees);
        virtual ~Utils();

    protected:

    private:
};

#endif // UTILS_H
