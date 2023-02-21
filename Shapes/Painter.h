//
// Created by nikita on 20.02.23.
//

#ifndef PAINTERPOINT_PAINTER_H
#define PAINTERPOINT_PAINTER_H

#include "Shape.h"

class Painter : public Shape {
public:
    Painter() : Shape() {}

    void setStart(QPoint s) override;

    void setPoints(QPoint *Now) override;

    void draw(QPainter *painter) override;

    int calculateSpace() override { return -1; }

    int calculatePerimeter() override;

    QPoint calculateCentroid() override;

    void rotateShape(const QPoint &point, double angle) override;

    void moveShape(QPoint mouse) override;

    void scaleShape(double k) override;
};


#endif //PAINTERPOINT_PAINTER_H
