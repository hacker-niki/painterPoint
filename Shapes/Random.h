//
// Created by nikita on 20.02.23.
//

#ifndef PAINTERPOINT_RANDOM_H
#define PAINTERPOINT_RANDOM_H

#include "Polygon.h"

class Random : public Polygon {
    void setPoints(QPoint *Now) override;
};


#endif //PAINTERPOINT_RANDOM_H
