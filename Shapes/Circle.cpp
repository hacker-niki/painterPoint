//
// Created by nikita on 10.02.23.
//

#include "Circle.h"
#include <QDebug>

void Circle::setPoints(QPoint *Now) {
    int radius = qMin(qAbs(Now->x() - Start.x()), qAbs(Now->y() - Start.y()));
    rect.setHeight(radius);
    rect.setWidth(radius);
    rect.moveCenter(Start);
}

void Circle::draw(QPainter *painter) {
    brush->setColor(*color);
    painter->setBrush(*brush);
    painter->drawEllipse(rect);
    if (rect.topLeft() != rect.bottomRight()) {
        painter->drawEllipse(rect.topLeft(), 5, 5);
        painter->drawEllipse(rect.topRight(), 5, 5);
        painter->drawEllipse(rect.bottomLeft(), 5, 5);
        painter->drawEllipse(rect.bottomRight(), 5, 5);
    }
}

Circle::Circle() : Shape() {

}

int Circle::calculateSpace() {
    return qAbs(rect.height() * M_PI * rect.width());
}

int Circle::calculatePerimeter() {
    return 2 * rect.height() * M_PI;
}

QPoint Circle::calculateCentroid() {
    return QPoint(rect.center().x(), rect.center().y());
}

void Circle::rotateShape(const QPoint &p, double angle) {
    QPolygonF result;
    angle *= M_PI / 180;
    QTransform transform;
    transform.translate(p.x(), p.y()); // сдвигаем точку вращения в p(x, y)
    transform.rotateRadians(angle); // вращаем полигон на заданный угол
    transform.translate(-p.x(), -p.y()); // возвращаем точку вращения на исходную позицию
    QPolygonF pol;
    QSizeF s = rect.size();
    pol << rect.topLeft();
    pol << rect.topRight();
    pol << rect.bottomRight();
    pol << rect.bottomLeft();
    // преобразуем полигон с помощью матрицы преобразования
    pol = transform.map(pol);

    rect = pol.boundingRect();
    QPointF c = rect.center();
    rect.setSize(s);
    rect.moveCenter(c);

}

void Circle::moveShape(QPoint mouse) {
    rect.moveCenter(mouse);
}

void Circle::scaleShape(double k) {

    rect.setTopLeft(QPointF(rect.topLeft().x() + (rect.topLeft().x() - calculateCentroid().x()) * k,
                            rect.topLeft().y() + (rect.topLeft().y() - calculateCentroid().y()) * k));
    rect.setBottomRight(QPointF(rect.bottomRight().x() + (rect.bottomRight().x() - calculateCentroid().x()) * k,
                            rect.bottomRight().y() + (rect.bottomRight().y() - calculateCentroid().y()) * k));

}
