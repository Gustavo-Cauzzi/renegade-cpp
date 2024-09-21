#ifndef RENEGADE_H
#define RENEGADEBUILDER_H
#include <Point.h>
#include <vector>
#include <Color.h>
#include <Circle.h>
#include <Drawable.h>
#include <SDL2/SDL.h>
#include <Line.h>
#include <memory>
#include <Utils.h>
using namespace std;


class Renegade: public Drawable, public Utils
{
    public:
        Renegade();
        Renegade(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Color color);
        Point firstPoint;
        void draw() override;
        void update();
        virtual ~Renegade();

    protected:

    private:
        Color color;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;

        Point velocityVector;
        float scale;
        double degrees;

        Point previousPoint;
        Point createPoint(int x, int y);
        Point createPoint(int x, int y, bool scaling);
        int scaling(int value);
        Point rotating(Point value);
        void append(int x1, int y1, int x2, int y2);
        void append(int x, int y);
        void createCircle(int x, int y, int r);
        void translate(float x, float y);
        shared_ptr<Line> createLine(Point start, Point end);
        vector<shared_ptr<Circle>> tires;
        vector<shared_ptr<Line>> lines;
};

#endif // RENEGADE_H
