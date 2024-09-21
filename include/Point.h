#ifndef POINT_H
#define POINT_H
#include<math.h>
#include<stdio.h>

class Point
{
    public:
        Point();
        Point(float x, float y);
        float getX();
        float getY();
        void setX(float x);
        void setY(float y);
        void rotate(int degrees);
        virtual ~Point();

    protected:

    private:
        float x, y;
};

#endif // POINT_H
