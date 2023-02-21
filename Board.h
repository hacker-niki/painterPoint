//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_BOARD_H
#define PAINTERPOINT_BOARD_H

#include <QWidget>
#include "Shapes/Shape.h"
#include "Shapes/Square.h"
#include <QMouseEvent>
#include <QPainter>
#include "Shapes/Rectangular.h"
#include "Shapes/Circle.h"
#include <QColorDialog>
#include <QPoint>
#include "Shapes/Ellipse.h"

class Board : public QWidget {
Q_OBJECT
    Shape *shape;
    QPainter *painter{};
    QBrush *brush;
    QPoint currentMouse;
    QPoint pressedMouse;
    bool drawing;
    double angle;
    int cnt;
    bool rotating;
    bool moving;
    bool pressed;
    bool scaling;
    bool movingVertex;
    bool mousePressed;
    double scaleCoef;
    int vertex;
    QPoint newCenterM;
    enum Tools {
        sq, rq, rd, el, st5, st6, st7, st8, tri, rm
    };
    short int currentTool{};

public:
    explicit Board(QWidget *par);

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;

    void timerEvent(QTimerEvent *event) override;

    QPoint shapeCenter();

    int shapeSpace();

    int shapePerimeter();

    bool isDrawing() { return drawing; }


public slots:

    void setSquare();

    void setRectangular();

    void setCircle();

    void setColor();

    void setStar();

    void rotateShape();

    void moveShape();

    void scaleShape();

    void setEllipse();

    void setTriangular();

    void setRandom();

    void setLine();
};


#endif //PAINTERPOINT_BOARD_H
