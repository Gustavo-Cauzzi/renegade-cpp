#include "RenegadeBuilder.h"
using namespace std;

RenegadeBuilder::RenegadeBuilder()
{
    //ctor
}

RenegadeBuilder::~RenegadeBuilder()
{
    //dtor
}

RenegadeBuilder::RenegadeBuilder(SDL_Surface * window_surface, SDL_Renderer * pRenderer, Color color) {
    this->color = color;
    this->window_surface = window_surface;
    this->pRenderer = pRenderer;

    this->scale = 2.5;

    this->append(189,208, 281,197);
    this->append(318,179);
    this->append(806,185);
    this->append(846,198);
    this->append(885,209);
    this->append(1037,330);
    this->append(1112,334);
    this->append(1291,366);
    this->append(1321,389);
    this->append(1327,441);
    this->append(1348,453);
    this->append(1352,403);
    this->append(1365,498);
    this->append(1365,538);
    this->append(1346,541);
    this->append(1282,597);
    this->append(1239,597);
    this->append(1211,477);
    this->append(1186,455);
    this->append(1033,455);
    this->append(1020,477);
    this->append(985,611);
    this->append(477,611);
    this->append(428,477);
    this->append(411,450);
    this->append(267,455);
    this->append(251,477);
    this->append(224,592);
    this->append(180,587);
    this->append(137,551);
    this->append(129,492);
    this->append(147,474);
    this->append(149,429);
    this->append(160,337);
    this->append(175,326);
    this->append(207,225);
    this->append(188,218);
    this->append(188,208);
}

shared_ptr<Drawable> RenegadeBuilder::createLine(Point start, Point end) {
    return shared_ptr<Drawable>(new Line(this->window_surface,this->pRenderer, start, end, this->color));
}

vector<shared_ptr<Drawable>> RenegadeBuilder::build(){
    return this->currentShape;
}

void RenegadeBuilder::append(int x1, int y1, int x2, int y2){
    Point p1 = Point((int) x1/this->scale, (int) y1/this->scale);
    Point p2 = Point((int) x2/this->scale, (int) y2/this->scale);
    this->lastPoint = p2;
    this->currentShape.push_back(this->createLine(p1, p2));
}
void RenegadeBuilder::append(int x, int y){
    Point point = Point((int) x/this->scale, (int) y/this->scale);
    this->currentShape.push_back(this->createLine(this->lastPoint, point));
    this->lastPoint = point;
}
void RenegadeBuilder::appendCurve(int x, int y, int sla, int temqueve){
    printf("TEMQUEVE");
}
