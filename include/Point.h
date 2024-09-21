#ifndef POINT_H
#define POINT_H
#include<math.h>
#include<stdio.h>

class Point
{
    public:
        Point();
        Point(double x, double y);
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
        void rotate(int degrees);
        virtual ~Point();

    protected:

    private:
        double x, y;
};

#endif // POINT_H
