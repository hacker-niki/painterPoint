//
// Created by nikita on 19.02.23.
//

#include "Ellipse.h"

void Ellipse::setPoints(QPoint *Now) {
    int radius1 = Now->x() - Start.x();
    int radius2 = Now->y() - Start.y();
    rect.setHeight(radius2);
    rect.setWidth(radius1);
    rect.moveCenter(Start);
}