#include "RenegadeBuilder.h"
using namespace std;

double toRadians(double degrees)
{
    return degrees * 0.017453293;
}

Point rotatePoint(Point p, double radians)
{
    return Point(
        p.getX() * cos(radians) - p.getY() * sin(radians),
        p.getX() * sin(radians) + p.getY() * cos(radians));
}

Point rotatePolygonByOrigin(Point origin, Point pointToRotate, double degrees)
{
    int newX = pointToRotate.getX() - origin.getX();
    int newY = pointToRotate.getY() - origin.getY();
    Point newPoint = rotatePoint(Point(newX, newY), toRadians(degrees));
    newPoint.setX(newPoint.getX() + origin.getX());
    newPoint.setY(newPoint.getY() + origin.getY());
    return newPoint;
}

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
    this->degrees = -30;

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
    this->createCircle(138, 230, 40);
    this->createCircle(445, 230, 40);

    //this->currentShape.push_back(this->createLine(p1, p2));
}

shared_ptr<Drawable> RenegadeBuilder::createLine(Point start, Point end) {
    Line* line = new Line(this->window_surface,this->pRenderer, start, end, this->color);
    this->lines.push_back(*line);
    return shared_ptr<Drawable>(line);
}
void RenegadeBuilder::createCircle(int x, int y, int r){
    Point circleOrigin = this->createPoint(x, y, false);
    Circle* circle = new Circle(
        this->window_surface,
        this->pRenderer,
        circleOrigin.getX(),
        circleOrigin.getY(),
        r,
        this->color
    );
    this->tires.push_back(*circle);
    this->currentShape.push_back(
        shared_ptr<Drawable>(circle)
    );
}

vector<shared_ptr<Drawable>> RenegadeBuilder::build(){
    return this->currentShape;
}

void RenegadeBuilder::update(){
    // TODO
}

void RenegadeBuilder::append(int x1, int y1, int x2, int y2){
    Point p1 = this->createPoint(x1, y1);
    Point p2 = this->createPoint(x2, y2);
    this->previousPoint = p2;
    this->currentShape.push_back(this->createLine(p1, p2));
}
void RenegadeBuilder::append(int x, int y){
    Point point = this->createPoint(x, y);
    this->currentShape.push_back(this->createLine(this->previousPoint, point));
    this->previousPoint = point;
}


int RenegadeBuilder::scaling(int value){
    return (int) value / this->scale;
}
Point RenegadeBuilder::rotating(Point point){
    return rotatePolygonByOrigin(this->firstPoint, point, this->degrees);
}

Point RenegadeBuilder::createPoint(int x, int y){
    return this->createPoint(x, y, true);
}
Point RenegadeBuilder::createPoint(int x, int y, bool scaling){
    x = scaling ? this->scaling(x) : x;
    y = scaling ? this->scaling(y) : y;
    Point p = Point(x, y);
    return this->rotating(p);
}

void RenegadeBuilder::appendCurve(int x, int y, int sla, int temqueve){
    printf("TEMQUEVE");
}
