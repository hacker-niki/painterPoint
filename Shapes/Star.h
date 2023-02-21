//
// Created by nikita on 13.02.23.
//

#ifndef PAINTERPOINT_STAR_H
#define PAINTERPOINT_STAR_H

#include "Polygon.h"

class Star : public Polygon {
    void setPoints(QPoint *Now) override;

public:
    Star() : Polygon() {}

//    int &getRays() override { return numRays; }
};


#endif //PAINTERPOINT_STAR_H
