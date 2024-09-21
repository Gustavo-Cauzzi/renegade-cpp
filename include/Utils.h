#ifndef UTILS_H
#define UTILS_H
#include<Point.h>
#include<Color.h>
#include<SDL2/SDL.h>


class Utils
{
    public:
        Utils();
        Point rotatePoint(Point p, double degrees);
        Point rotatePointByOrigin(Point origin, Point pointToRotate, double degrees);
        double toRadians(double degrees);
        Uint32 getPixel(SDL_Surface* window_surface, int x, int y);
        void floodFill(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, Color newColor);
        void floodFill(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, Color newColor, Color backgroundColor);
        Uint32 RGB(SDL_Surface* window_surface, int r, int g, int b);
        void setPixel(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, int r, int g, int b);
        void setPixel(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, Color color);
        virtual ~Utils();

    protected:

    private:
};

#endif // UTILS_H
