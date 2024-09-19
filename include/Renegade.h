#ifndef RENEGADE_H
#define RENEGADE_H
#include<Point.h>
#include<vector>
#include<memory>
#include<Color.h>
#include<Drawable.h>
#include<SDL2/SDL.h>
#include<Line.h>
using namespace std;


class Renegade: public Drawable
{
    public:
        Renegade();
        Renegade(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Color color);
        void draw() override;
        virtual ~Renegade();


    protected:

    private:
        Color color;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
        vector<shared_ptr<Drawable>> components;
        Point firstPoint;
        Uint32 RGB(int r, int g, int b);
        Uint32 getPixel(int x, int y);
        void floodFill(int x, int y, Uint32 newColor, Uint32 backgroundColor);
        void setPixel(int x, int y, Uint32 color);

};

#endif // RENEGADE_H
