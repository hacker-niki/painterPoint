//
// Created by nikita on 20.02.23.
//

#include "Random.h"

void Random::setPoints(QPoint *Now) {
    QPolygonF p;
    int tri = random() % 7 + 3;
    double radius = sqrt(
            ((Now->x() - Start.x()) * (Now->x() - Start.x())) + ((Now->y() - Start.y()) * (Now->y() - Start.y())));
    double angleStep = 360.0 / (double) tri;
    for (int i = 0; i < tri; ++i) {
        double angle = angleStep * i;
        double x = radius * cos(angle * M_PI / 180.0);
        double y = radius * sin(angle * M_PI / 180.0);

        p << QPointF(x + Start.x(), y + Start.y());
    }
    *polygon = p;
}
