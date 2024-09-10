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
        RenegadeBuilder();
        RenegadeBuilder(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Color color);
        vector<shared_ptr<Drawable>> build();
        virtual ~RenegadeBuilder();

    protected:

    private:
        Color color;
        SDL_Renderer * pRenderer;
        SDL_Surface * window_surface;
        Point lastPoint;
        float scale;
        vector<shared_ptr<Drawable>> currentShape;
        void append(int x1, int y1, int x2, int y2);
        void append(int x, int y);
        void appendCurve(int x, int y, int sla, int temqueve);
        shared_ptr<Drawable> createLine(Point start, Point end);
};

#endif // RENEGADEBUILDER_H
