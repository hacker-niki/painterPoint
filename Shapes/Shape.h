//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_SHAPE_H
#define PAINTERPOINT_SHAPE_H

#include <QObject>
#include <QColor>
#include <QPoint>
#include <QPainter>

class Shape : public QObject {
Q_OBJECT
protected:
    QPoint Start;
    bool drawingNow{};
    QBrush *brush;
    QPoint prev;
    QVector<QPoint> line;
public:
    QPolygonF *polygon;
    QRectF rect;
    int numRays{};

    Shape();

    QColor *color;

    virtual void setStart(QPoint s);

    virtual void setPoints(QPoint *Now) {}

    virtual void draw(QPainter *painter) {}

    virtual int calculateSpace() { return 0; }

    virtual int calculatePerimeter() { return 0; }

    virtual QPoint calculateCentroid() { return {0, 0}; }

    virtual void rotateShape(const QPoint &point, double angle) {}

    virtual void moveShape(QPoint mouse) {}

    virtual void scaleShape(double k) {}

//    virtual int &getRays() { return numRays; }
};


#endif //PAINTERPOINT_SHAPE_H
