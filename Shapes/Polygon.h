//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_POLYGON_H
#define PAINTERPOINT_POLYGON_H

#include "Shape.h"
#include <QtMath>
#include <QPainter>
#include <QDebug>
#include <QPolygon>

class Polygon : public Shape {
public:

    Polygon();

    int calculateSpace() override;

    void draw(QPainter *painter) override;

    int calculatePerimeter() override;

//    void poligonUpdate();

    QPoint calculateCentroid() override;

    void rotateShape(const QPoint &p, double angle) override;

    void moveShape(QPoint mouse) override;

    void scaleShape(double k) override;
};


#endif //PAINTERPOINT_POLYGON_H
