#ifndef POLYGON_H
#define POLYGON_H
#include <Point.h>
#include <vector>
#include <Color.h>
#include<Drawable.h>
#include<SDL2/SDL.h>
#include<Line.h>
using namespace std;


class Polygon: public Drawable
{
    public:
        Polygon();
        Polygon(SDL_Surface * window_surface, SDL_Renderer * pRenderer, vector<Drawable*> components, Color color);
        void draw() override;
        virtual ~Polygon();

    protected:

    private:
        vector<Drawable*> components;
        Color color;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
};

#endif // POLYGON_H
