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


    // Desenho das portas
    this->append(953, 586, 951, 337);
    this->append(951, 337, 841, 209);
    this->append(466, 578, 991, 589);
    this->append(672, 580, 664, 405);
    this->append(664, 405, 653, 345);
    this->append(653, 345, 630, 205);

    //janelas
    this->append(347,196, 840, 208);
    this->append(347,196, 347, 294);
    this->append(347, 294, 487,337);
    this->append(487,337,878, 354);
    this->append(878, 354,951, 337);
    this->append(884, 212, 879, 218);
    this->append(879, 218, 1003, 330);
    this->append(1003, 330,1031, 335);
    this->append(1031, 335, 884, 212);
    this->append(383, 451, 388, 361);
    this->append(388, 361, 408, 317);
    this->append(408, 317, 412, 201);
    this->append(951, 337,988, 321);
    //detalhe janela retrovisor
    this->append(873, 301, 858, 230);
    this->append(858, 230, 868, 243);
    this->append(868, 246, 881, 302);
    //detalhes janelas
    this->append(443, 321, 435, 200);
    this->append(627, 339, 613, 205);
    this->append(678, 341, 650, 205);
    //janela traseira
    this->append(207, 225, 234, 232);
    this->append(234, 232, 225, 290);
    this->append(225, 290, 174, 324);

    //bagulho de gasolina
    this->append(307, 404, 307, 364);
    this->append(307, 364, 364, 366);
    this->append(364, 366, 364, 405);
    this->append(364, 405, 307, 404);

    //lanterna traseira
    this->append(167, 334, 220, 334);
    this->append(220, 334, 215, 377);
    this->append(215, 377, 188, 403);
    this->append(188, 403, 153, 404);

    //lanterna frontal
    this->append(1319, 390, 1301, 393);
    this->append(1301, 393, 1305, 440);
    this->append(1305, 440, 1323, 449);
    this->append(1323, 449 , 1327, 436);
    this->append(1327, 436, 1319, 390);

    //capo
    this->append(1301, 393, 1282, 382);
    this->append(1282, 382, 1065, 356);
    this->append(1065, 356, 1030, 333);

    //espelho retrovisor
    this->append(870, 364, 870, 353);
    this->append(870, 353, 846, 345);
    this->append(846, 345, 846, 301);
    this->append(846, 301, 886, 303);
    this->append(886, 303, 910, 317);
    this->append(910, 317, 901, 348);
    this->append(901, 348, 908, 354);
    this->append(908, 354, 908, 361);
    this->append(908, 361, 870, 364);

    //relevo legal
    this->append(150, 474, 160, 483);
    this->append(160, 483, 163, 503);
    this->append(163, 503, 205, 506);
    this->append(205, 506, 228, 439);
    this->append(228, 439, 253, 424);
    this->append(253, 424, 418, 426);
    this->append(418, 426, 456, 450);
    this->append(456, 450, 491, 540);
    this->append(491, 540, 965, 546);
    this->append(965, 546, 998, 451);
    this->append(998, 451, 1037, 426);
    this->append(1037, 426, 1204, 433);
    this->append(1204, 433, 1234, 458);
    this->append(1234, 458, 1261, 540);
    this->append(1261, 540, 1289, 539);
    this->append(1289, 539, 1304, 499);
    this->append(1304, 499, 1365, 496);

    //linhas que conectam pontos aleat�rios
    this->append(1237, 467, 1304, 439);
    this->append(230, 436, 195, 397);
    this->append(234, 232, 273, 197);

    //tro�o de segurar bike
    this->append(279, 200, 319, 179);
    this->append(319, 179, 802, 183);
    this->append(802, 183, 851, 204);
    this->append(851, 204, 830, 204);
    this->append(830, 204, 805, 196);
    this->append(805, 196, 322, 189);
    this->append(322, 189, 301, 199);
    this->append(301, 199, 279, 200);

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
    this->translate(this->velocityVector.getX(), this->velocityVector.getY());
    for (const auto &circle: this->tires) {
        circle->rotate(0.05);
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
