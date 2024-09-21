#include "Utils.h"

Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}

double Utils::toRadians(double degrees)
{
    return degrees * 0.017453293;
}

Point Utils::rotatePoint(Point p, double degrees)
{
    double radians = degrees * 0.017453293;
    return Point(
        p.getX() * cos(radians) - p.getY() * sin(radians),
        p.getX() * sin(radians) + p.getY() * cos(radians));
}

Point Utils::rotatePointByOrigin(Point origin, Point pointToRotate, double degrees)
{
    int newX = pointToRotate.getX() - origin.getX();
    int newY = pointToRotate.getY() - origin.getY();
    Point newPoint = rotatePoint(Point(newX, newY), degrees);
    newPoint.setX(newPoint.getX() + origin.getX());
    newPoint.setY(newPoint.getY() + origin.getY());
    return newPoint;
}
/*
Uint32 Utils::getPixel(SDL_Surface* window_surface, int x, int y)
{
    int bpp = window_surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *) window_surface->pixels + y * window_surface->pitch + x * bpp;

    switch (bpp)
    {
        case 1:
            return *p;
            break;

        case 2:
            return *(Uint16 *)p;
            break;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
            break;

            case 4:
                return *(Uint32 *)p;
                break;

            default:
                return 0;
      }
}
*/

Uint32 Utils::getPixel(SDL_Surface* window_surface, int x, int y)
{
    int width = window_surface->w;
    int height = window_surface->h;
    if((x>=0 && x< width) && (y>=0 && y< height)) {
        Uint32 *pixels = (Uint32 *) window_surface->pixels;
        return pixels[y * width + x];
    }
    return -1;
}

Uint32 Utils::RGB(SDL_Surface* window_surface, int r, int g, int b) {
    return SDL_MapRGBA(window_surface->format, r, g, b, 255);
}

void Utils::setPixel(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, Color color) {
	this->setPixel(window_surface, pRenderer, x, y, color.getR(),color.getG(),color.getB());
}

void Utils::setPixel(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, int r, int g, int b)
{
    int width = window_surface->w;
    int height = window_surface->h;
    if (x >= 0 && x < width && y >= 0 && y < height) {
        //SDL_SetRenderDrawColor(pRenderer, r, g, b, 255);
        //SDL_RenderDrawPoint(pRenderer, x, y);

        Uint32 test = this->getPixel(window_surface, x, y);
        printf("r, g, b %d %d %d | antes: %ld \n", r, g, b, test);
        Uint32 *pixels = (Uint32 *) window_surface->pixels;
        pixels[x + y * width] = SDL_MapRGBA(window_surface->format, r, g, b, 255);
        test = this->getPixel(window_surface, x, y);
        printf("depois: %d \n", r, g, b, test);
    }
}

void Utils::floodFill(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, Color newColor)
{
    return this->floodFill(window_surface, pRenderer, x, y, newColor, Color(window_surface, 255, 255, 255));
}

void Utils::floodFill(SDL_Surface* window_surface, SDL_Renderer* pRenderer, int x, int y, Color newColor, Color backgroundColor)
{
    int width = window_surface->w;
    int height = window_surface->h;

    // Check for out-of-bounds coordinates
    if (x < 0 || x >= width || y < 0 || y >= height) return;

    Uint32 currentColor = this->getPixel(window_surface, x, y);
    printf("Flood fill at (%d, %d): backgroundColor=%ld, newColor=%ld currentColor=%ld\n", x, y, backgroundColor.getColor(), newColor.getColor(), currentColor);

    // Only proceed if the current color matches the oldColor or is transparent
    if (currentColor != backgroundColor.getColor()) return;

    // Set the new color
    this->setPixel(window_surface, pRenderer, x, y, newColor);

    // Recursively fill neighboring pixels
    printf("flood1 ");
    this->floodFill(window_surface, pRenderer, x + 1, y, newColor, backgroundColor);
    printf("flood2 ");
    this->floodFill(window_surface, pRenderer, x - 1, y, newColor, backgroundColor);
    printf("flood3 ");
    this->floodFill(window_surface, pRenderer, x, y + 1, newColor, backgroundColor);
    printf("flood4 ");
    this->floodFill(window_surface, pRenderer, x, y - 1, newColor, backgroundColor);
}
