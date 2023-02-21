//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_SQUARE_H
#define PAINTERPOINT_SQUARE_H
#include "Polygon.h"
#include <QPoint>

class Square: public Polygon{
public:
    Square();
    void setPoints(QPoint *Now) override;
};


#endif //PAINTERPOINT_SQUARE_H
