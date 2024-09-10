#ifndef LINE_H
#define LINE_H
#include <Point.h>
#include <Color.h>
#include <Drawable.h>
#include<SDL2/SDL.h>

class Line: public Drawable
{
    public:
        Line();
        Line(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Point start, Point end, Color color);
        Line(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Point start, Point end, Color color, int antialias);
        void draw() override;
        virtual ~Line();

    protected:

    private:
        Point start;
        Point end;
        Color color;
        int antialias = 0;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
        void setPixel(int x, int y, int r, int g, int b);
        void setPixel(int x, int y, Color color);
        void setPixel(int x, int y, Uint32 cor);
        Uint32 getPixel(int x, int y);
        void bresenham(int x1, int y1, int x2, int y2, int r, int g, int b);
        void drawWuLine(int x0, int y0, int x1, int y1, Color color);

};

#endif // LINE_H
