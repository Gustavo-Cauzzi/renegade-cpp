#ifndef COLOR_H
#define COLOR_H
#include<SDL2/SDL.h>


class Color
{
    public:
        Color();
        Color(SDL_Surface * window_surface, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        Color(SDL_Surface * window_surface, Uint8 r, Uint8 g, Uint8 b);
        Color(SDL_Surface * window_surface);
        Uint8 getColorComponent( Uint32 pixel, char component );
        Uint32 RGB(int r, int g, int b);
        Uint32 getColor();
        Uint32 getColor(int r, int g, int b);
        Uint8 getR();
        Uint8 getG();
        Uint8 getB();
        virtual ~Color();

    protected:

    private:
        SDL_Surface * window_surface;
        Uint8 r, g, b, a;
};

#endif // COLOR_H
