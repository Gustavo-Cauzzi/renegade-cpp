#ifndef DRAWABLE_H
#define DRAWABLE_H
#include<SDL2/SDL.h>


class Drawable
{
    public:
        virtual ~Drawable() = default;
        virtual void draw() = 0;

    protected:

    private:
};

#endif // DRAWABLE_H
