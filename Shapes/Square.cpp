//
// Created by nikita on 10.02.23.
//

#include "Square.h"

Square::Square() : Polygon() {

}

void Square::setPoints(QPoint *Now) {
    if (!polygon->isEmpty())
        polygon->erase(polygon->begin(), polygon->end());
    int m = qMin(qAbs(Now->x() - Start.x()), qAbs(Now->y() - Start.y()));
    polygon->append(Start);
    polygon->append(QPoint(Start.x() + m, Start.y()));
    polygon->append(QPoint(Start.x() + m, Start.y() + m));
    polygon->append(QPoint(Start.x(), Start.y() + m));
}