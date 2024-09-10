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
}

void Renegade::draw() {
    for (const auto& drawable: this->components) {
        drawable->draw();
    }
}
