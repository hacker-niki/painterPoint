//
// Created by nikita on 20.02.23.
//

#ifndef PAINTERPOINT_TRIANGULAR_H
#define PAINTERPOINT_TRIANGULAR_H

#include <QPoint>
#include "Polygon.h"

class Triangular: public Polygon {
    void setPoints(QPoint *Now) override;
};


#endif //PAINTERPOINT_TRIANGULAR_H
