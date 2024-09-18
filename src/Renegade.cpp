#include "Renegade.h"
#include <RenegadeBuilder.h>

Renegade::Renegade()
{
    //ctor
}

Renegade::~Renegade()
{
    //dtor
}

Renegade::Renegade(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Color color) {
    this->color = color;
    this->window_surface = window_surface;
    this->pRenderer = pRenderer;
    RenegadeBuilder jeepFactory = RenegadeBuilder(window_surface, pRenderer, color);
    this->components = jeepFactory.build();
    this->firstPoint = jeepFactory.getFirstPoint();
}

Uint32 Renegade::getPixel(int x, int y)
{
    int width = this->window_surface->w;
    int height = this->window_surface->h;
    if((x>=0 && x<=width) && (y>=0 && y<=height))
        return this->window_surface->pixels[x + width * y];
    else
        return -1;
}


Uint32 Renegade::RGB(int r, int g, int b) {
    return SDL_MapRGBA(this->window_surface->format, r, g, b, 255);
}

void floodFill(int x, int y, Uint32 newColor, Uint32 oldColor)
{
    int width = window_surface->w;
    int height = window_surface->h;
    if(y<0 || y < height - 1 || x < 0 || x > width -1)
        return;
    if(getPixel(x,y, this->window_surface)==oldColor)
    {
        setPixel(x,y, newColor);
        floodFill(x+1, y, newColor, oldColor);
        floodFill(x-1, y, newColor, oldColor);
        floodFill(x, y+1, newColor, oldColor);
        floodFill(x, y-1, newColor, oldColor);
    }
}

void Renegade::draw() {
    for (const auto& drawable: this->components) {
        drawable->draw();
    }
    Point firstPoint = this->firstPoint;
    Uint32 carColor = this->color.getColor();
    Uint32 backgroundColor = RGB(255, 255, 255);
    floodFill(firstPoint.getX(), firstPoint.getY(), carColor, backgroundColor);
}
