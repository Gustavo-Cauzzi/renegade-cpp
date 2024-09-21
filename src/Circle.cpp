#include "Circle.h"

Circle::Circle()
{
    //ctor
}

Circle::Circle(SDL_Surface * window_surface, SDL_Renderer * pRenderer, int x, int y, int r, Color color) {
    this->point = Point(x, y);
    this->r = r;
    this->color = color;
    this->window_surface = window_surface;
    this->pRenderer = pRenderer;
    this->rotation = 0;
}

Circle::~Circle()
{
    //dtor
}

void Circle::rotate(float degrees) {
    this->rotation += degrees;
}

void Circle::draw() {
    int x = 0, y = r;
    int decisionParameter = 3 - 2 * this->r;
    displayBresenhamCircle(this->point.getX(), this->point.getY(), x, y);
    while (y >= x) {
        x++;
        if (decisionParameter > 0) {
            y--;
            decisionParameter = decisionParameter + 4 * (x - y) + 10;
        } else {
            decisionParameter = decisionParameter + 4 * x + 6;
        }
        displayBresenhamCircle(this->point.getX(), this->point.getY(), x, y);
    }

    int whellRimDegrees[6] = {0, 60, 120, 180, 240, 300};
    for (int whellRimDegree: whellRimDegrees) {
        Point whellRim = Point(this->point.getX() + r, this->point.getY());
        whellRim = this->rotatePointByOrigin(this->point, whellRim, this->rotation + whellRimDegree);

        Line line = Line(
             this->window_surface,
             this->pRenderer,
             this->point,
             whellRim,
             this->color
        );
        line.draw();
    }
}

int Circle::getX() {
    return this->point.getX();
}

int Circle::getY() {
    return this->point.getY();
}

void Circle::translate(float x, float y) {
    this->point.setX(this->point.getX() + x);
    this->point.setY(this->point.getY() + y);
}

void Circle::setPixel(int x, int y) {
    Uint32 color = this->color.getColor();
    int r = this->color.getColorComponent(color, 'r');
    int g = this->color.getColorComponent(color, 'g');
    int b = this->color.getColorComponent(color, 'b');
    SDL_SetRenderDrawColor(pRenderer, r, g, b, 255);
	SDL_RenderDrawPoint(pRenderer, x, y);
}

void Circle::displayBresenhamCircle(int xc, int yc, int x, int y) {
    // desenha todas as 8 coordenadas de(x,y)
    // uma para cada octante
    this->setPixel(xc+x, yc+y);
    this->setPixel(xc-x, yc+y);
    this->setPixel(xc+x, yc-y);
    this->setPixel(xc-x, yc-y);
    this->setPixel(xc+y, yc+x);
    this->setPixel(xc-y, yc+x);
    this->setPixel(xc+y, yc-x);
    this->setPixel(xc-y, yc-x);
}
