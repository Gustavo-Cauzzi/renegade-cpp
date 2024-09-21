#ifndef RENEGADEBUILDER_H
#define RENEGADEBUILDER_H
#include <Point.h>
#include <vector>
#include <Color.h>
#include <Drawable.h>
#include <SDL2/SDL.h>
#include <Line.h>
#include <memory>
using namespace std;


class RenegadeBuilder
{
    public:
        Uint8 r, g, b, a;
        Color color;
        RenegadeBuilder();
        RenegadeBuilder(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Color color);
        vector<shared_ptr<Drawable>> build();
        Point getFirstPoint();
        virtual ~RenegadeBuilder();

    protected:

    private:
        Point firstPoint;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
        Point lastPoint;
        float scale;
        vector<shared_ptr<Drawable>> currentShape;
        void append(int x1, int y1, int x2, int y2);
        void append(int x, int y);
        //void appendCurve(int x, int y, int sla, int temqueve);
        shared_ptr<Drawable> createLine(Point start, Point end);
        void drawQuadraticBezier(Point p0, Point p1, Point p2);
        void setPixel(int x, int y, Uint32 color);
        void appendCurve(int x1, int y1, int cx, int cy, int x2, int y2);
        Point createPoint(float x, float y);
};

#endif // RENEGADEBUILDER_H
