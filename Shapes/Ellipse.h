//
// Created by nikita on 19.02.23.
//

#ifndef PAINTERPOINT_ELLIPSE_H
#define PAINTERPOINT_ELLIPSE_H

#include "Circle.h"

class Ellipse : public Circle {
    void setPoints(QPoint *Now) override;
};


#endif //PAINTERPOINT_ELLIPSE_H
