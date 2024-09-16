#ifndef CIRCLE_H
#define CIRCLE_H
#include <Point.h>
#include <vector>
#include <Color.h>
#include<Drawable.h>
#include<SDL2/SDL.h>
#include<Line.h>

class Circle: public Drawable
{
    public:
        Circle();
        Circle(SDL_Surface * window_surface, SDL_Renderer * pRenderer, int x, int y, int r, Color color);
        void draw() override;
        virtual ~Circle();

    protected:

    private:
        void displayBresenhamCircle(int xc, int yc, int x, int y);
        void setPixel(int x, int y);
        int x, y, r;
        Color color;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
};

#endif // CIRCLE_H
