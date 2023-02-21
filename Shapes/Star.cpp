//
// Created by nikita on 13.02.23.
//

#include "Star.h"

void Star::setPoints(QPoint *Now) {
    QPolygonF p;
    double radius = sqrt(
            ((Now->x() - Start.x()) * (Now->x() - Start.x())) + ((Now->y() - Start.y()) * (Now->y() - Start.y())));
    double angleStep = 360.0 / (double) numRays;
    for (int i = 0; i < numRays; ++i) {
        double angle = angleStep * i;
        double x = radius * cos(angle * M_PI / 180.0);
        double y = radius * sin(angle * M_PI / 180.0);

        p << QPointF(x + Start.x(), y + Start.y());

        angle += angleStep / 2.0;
        x = (radius / 2) * cos(angle * M_PI / 180.0);
        y = (radius / 2) * sin(angle * M_PI / 180.0);

        p << QPointF(x + Start.x(), y + Start.y());
    }
    *polygon = p;
}
