//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_CIRCLE_H
#define PAINTERPOINT_CIRCLE_H


#include "Shape.h"
#include "cmath"

class Circle : public Shape {
public:
    Circle();

    virtual void setPoints(QPoint *Now) override;

    void draw(QPainter *painter) override;

    int calculateSpace() override;

    int calculatePerimeter() override;

    QPoint calculateCentroid() override;

    void rotateShape(const QPoint &p, double angle) override;

    void moveShape(QPoint mouse) override;

    void scaleShape(double k) override;
};


#endif //PAINTERPOINT_CIRCLE_H
