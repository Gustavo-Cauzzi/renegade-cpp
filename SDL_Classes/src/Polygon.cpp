#include "Polygon.h"

Polygon::Polygon()
{
    //ctor
}

Polygon::~Polygon()
{
    //dtor
}

Polygon::Polygon(SDL_Surface * window_surface, SDL_Renderer * pRenderer, vector<Drawable*> components, Color color) {
    this->components = components;
    this->color = color;
    this->window_surface = window_surface;
    this->pRenderer = pRenderer;
}

void Polygon::draw(){
    //for (int i = 0; i < this->points.size(); i++) {
    //    Point start = this->points.at(i);
    //    Point end = this->points.at(i==this->points.size()-1 ? 0 : i+1);
    //    Line line = Line(
    //        this->window_surface,
    //        this->pRenderer,
    //        start,
    //        end,
    //        this->color,
    //        1
    //    );
    //    line.draw();
    //
    //}
}
