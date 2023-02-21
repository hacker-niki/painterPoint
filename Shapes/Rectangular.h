//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_RECTANGULAR_H
#define PAINTERPOINT_RECTANGULAR_H

#include <QPoint>
#include <QPolygon>
#include "Polygon.h"

class Rectangular : public Polygon {
    void setPoints(QPoint *Now) override;

public:
    Rectangular():Polygon(){}
};


#endif //PAINTERPOINT_RECTANGULAR_H
