//
// Created by nikita on 10.02.23.
//

#include "Rectangular.h"

void Rectangular::setPoints(QPoint *Now) {
    if (!polygon->isEmpty())
        polygon->erase(polygon->begin(), polygon->end());
//    int m = qMin(qAbs(Now->x() - Start.x()), qAbs(Now->y() - Start.y()));
    polygon->append(Start);
    polygon->append(QPoint(Now->x(), Start.y()));
    polygon->append(QPoint(Now->x(), Now->y()));
    polygon->append(QPoint(Start.x(), Now->y()));
}