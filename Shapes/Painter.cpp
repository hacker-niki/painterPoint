//
// Created by nikita on 20.02.23.
//

#include "Painter.h"
#include <QDebug>
#include <QtMath>

inline double get_distance(QPointF p1, QPointF p2) {
    double dx = p1.x() - p2.x();
    double dy = p1.y() - p2.y();
    return sqrt(dx * dx + dy * dy);
}

void Painter::setStart(QPoint s) {
    line.push_back(s);
}

void Painter::setPoints(QPoint *Now) {
    static int minX = INT32_MAX, minY = INT32_MAX, maxX = 0, maxY = 0;
    line.push_back(*Now);
    minX = qMin(minX, line.last().x());
    minY = qMin(minY, line.last().y());
    maxX = qMax(maxX, line.last().x());
    maxY = qMax(maxY, line.last().y());
    Start = QPoint(minX + (maxX - minX) / 2, minY + (maxY - minY) / 2);
}

void Painter::draw(QPainter *painter) {
    for (int i = 1; i < line.size(); i++) {
        painter->drawLine(line[i - 1], line[i]);
    }
}

void Painter::rotateShape(const QPoint &point, double angle) {
    angle *= M_PI / 180;
    int minX = INT32_MAX, minY = INT32_MAX, maxX = 0, maxY = 0;
    for (auto &i: line) {
        qreal dx = i.x() - point.x();
        qreal dy = i.y() - point.y();
        qreal newX = dx * qCos(angle) - dy * qSin(angle) + point.x();
        qreal newY = dx * qSin(angle) + dy * qCos(angle) + point.y();
        i = QPoint(newX, newY);
        minX = qMin(minX, i.x());
        minY = qMin(minY, i.y());
        maxX = qMax(maxX, i.x());
        maxY = qMax(maxY, i.y());
        Start = QPoint(minX + (maxX - minX) / 2, minY + (maxY - minY) / 2);
    }
}

void Painter::moveShape(QPoint mouse) {
//    qDebug() << mouse;
    for (auto &i: line) {
//        qDebug() << i << "OLD";
//        i.setX(i.x() + mouse.x()- midX);
//        i.setY(i.y() + mouse.y()- midY);
        i += mouse - calculateCentroid();
//        qDebug() << i << "NEW";
    }
//    qDebug() << "\n\n\n\n\n";
    Start += mouse - Start;
}

void Painter::scaleShape(double k) {
    for (auto &i: line) {
        i += (-calculateCentroid() + i) * k;
    }
}

QPoint Painter::calculateCentroid() {
    return Start;
}

int Painter::calculatePerimeter() {
    int perimeter = 0;
    int n = line.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimeter += get_distance(line[i], line[j]);
    }
    return perimeter;
}
