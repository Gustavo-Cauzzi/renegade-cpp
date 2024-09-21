#ifndef CIRCLE_H
#define CIRCLE_H
#include <Point.h>
#include <vector>
#include <Color.h>
#include<Drawable.h>
#include<SDL2/SDL.h>
#include<Line.h>
#include<Utils.h>

class Circle: public Drawable, public Utils
{
    public:
        Circle();
        Circle(SDL_Surface * window_surface, SDL_Renderer * pRenderer, int x, int y, int r, Color color);
        void draw() override;
        void translate(float x, float y);
        void rotate(float degrees);
        int getX();
        int getY();
        virtual ~Circle();

    protected:

    private:
        void displayBresenhamCircle(int xc, int yc, int x, int y);
        void setPixel(int x, int y);
        Point point;
        int r;
        Color color;
        float rotation;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
};

#endif // CIRCLE_H
