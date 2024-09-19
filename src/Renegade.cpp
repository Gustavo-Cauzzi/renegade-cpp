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
    //printf("WIDTH GET PIXEL %d", width);
    //printf("HEIGHT GET PIXEL %d", height);
    if((x>=0 && x< width) && (y>=0 && y< height)) {
    Uint32 *pixels = (Uint32 *)window_surface->pixels;
    //printf("SOMA %d", pixels[y * width + x]);
    return pixels[y * width + x];
    }
    return -1;
}

void Renegade::setPixel(int x, int y, Uint32 color)
{
    int width = this->window_surface->w;
    int height = this->window_surface->h;
    if (x >= 0 && x < width && y >= 0 && y < height) {
        Uint32 *pixels = (Uint32 *)this->window_surface->pixels;
        pixels[y * width + x] = color;
    }

}

    //if((x>=0 && x<=width) && (y>=0 && y<=height))
      //  Uint32* pixels = static_cast<Uint32*>(this->window_surface->pixels);
        //return pixels[x + width * y];


Uint32 Renegade::RGB(int r, int g, int b) {
    return SDL_MapRGBA(this->window_surface->format, r, g, b, 255);
}

void Renegade::floodFill(int x, int y, Uint32 newColor, Uint32 backgroundColor) {
    int width = this->window_surface->w;
    int height = this->window_surface->h;

    // Check for out-of-bounds coordinates
    if (x < 0 || x >= width || y < 0 || y >= height) return;

    Uint32 currentColor = getPixel(x, y);
    //printf("Flood fill at (%d, %d): currentColor=%u, newColor=%u\n", x, y, currentColor, newColor);

    // Only proceed if the current color matches the oldColor or is transparent
    if (currentColor != backgroundColor) return;

    // Set the new color
    setPixel(x, y, newColor);

    // Recursively fill neighboring pixels
    floodFill(x + 1, y, newColor, backgroundColor);
    floodFill(x - 1, y, newColor, backgroundColor);
    //SDL_Delay(5000);
    floodFill(x, y + 1, newColor, backgroundColor);
    //SDL_Delay(5000);
    floodFill(x, y - 1, newColor, backgroundColor);
    //SDL_Delay(5000);
}

void Renegade::draw() {
    for (const auto& drawable : this->components) {
        drawable->draw();
    }

    Point firstPoint = this->firstPoint;
    Uint32 carColor = this->color.getColor();
    //printf("%d", carColor);
    Uint32 backgroundColor = RGB(255, 255, 255);

    // Get the initial color
    Uint32 initialColor = getPixel(firstPoint.getX(), firstPoint.getY());
    //printf("Initial color at (%d, %d): %u\n", firstPoint.getX(), firstPoint.getY(), initialColor);
    //printf("Background color: %u\n", backgroundColor);

    // Start flood fill only if the initial color is transparent or matches the background
    if (initialColor == 0 || initialColor == backgroundColor) {
        floodFill(firstPoint.getX(), firstPoint.getY(), carColor, backgroundColor);
    } else {
        printf("Flood fill won't proceed as initial color is neither transparent nor background.\n");
    }

    // Update the window to reflect changes
    //SDL_UpdateWindowSurface(SDL_GetWindowFromID(window_surface->format->format)); // or your specific window handling
    //SDL_Delay(5000);
}
