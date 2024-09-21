#include "Renegade.h"
using namespace std;

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

    this->scale = 0.33;
    this->degrees = -30;
    Point vel = Point(0.04f, 0);
    vel.rotate(-35);
    this->velocityVector = vel;

    this->firstPoint=Point(189, 208);

    this->append(this->firstPoint.getX(), this->firstPoint.getY(), 281,197);
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
    this->createCircle(345, 575, 100);
    this->createCircle(1112, 575, 100);

    this->translate(-200, 300);
}

void Renegade::draw() {
    for (const auto &line: this->lines) {
        line->draw();
    }
    for (const auto &circle: this->tires) {
        circle->draw();
    }
}

void Renegade::update(){
    printf("Update %f %f\n", this->velocityVector.getX(), this->velocityVector.getY());
    this->translate(this->velocityVector.getX(), this->velocityVector.getY());
    for (const auto &circle: this->tires) {
        circle->rotate(0.1);
    }
}

shared_ptr<Line> Renegade::createLine(Point start, Point end) {
    return shared_ptr<Line>(new Line(this->window_surface,this->pRenderer, start, end, this->color));
}

void Renegade::createCircle(int x, int y, int r){
    Point circleOrigin = this->createPoint(x, y);
    Circle* circle = new Circle(
        this->window_surface,
        this->pRenderer,
        circleOrigin.getX(),
        circleOrigin.getY(),
        this->scaling(r),
        this->color
    );
    this->tires.push_back(shared_ptr<Circle>(circle));
}

void Renegade::append(int x1, int y1, int x2, int y2){
    Point p1 = this->createPoint(x1, y1);
    Point p2 = this->createPoint(x2, y2);
    this->previousPoint = p2;
    this->lines.push_back(this->createLine(p1, p2));
}

void Renegade::append(int x, int y){
    Point point = this->createPoint(x, y);
    this->lines.push_back(this->createLine(this->previousPoint, point));
    this->previousPoint = point;
}

int Renegade::scaling(int value){
    return (int) value * this->scale;
}

Point Renegade::rotating(Point point){
    return this->rotatePointByOrigin(this->firstPoint, point, this->degrees);
}

void Renegade::translate(float x, float y){
    for (const auto &line: this->lines) {
        line->translate(x, y);
    }
    for (const auto &circle: this->tires) {
        circle->translate(x, y);
    }
}

Point Renegade::createPoint(int x, int y){
    return this->createPoint(x, y, true);
}

Point Renegade::createPoint(int x, int y, bool scaling){
    x = scaling ? this->scaling(x) : x;
    y = scaling ? this->scaling(y) : y;
    Point p = Point(x, y);
    return this->rotating(p);
}
