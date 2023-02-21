//
// Created by nikita on 10.02.23.
//

#include "Shape.h"

Shape::Shape() {
    color = new QColor(Qt::gray);
    brush = new QBrush(*color);
    polygon = new QPolygonF;
}

void Shape::setStart(QPoint s) {
    Start = s;
}
