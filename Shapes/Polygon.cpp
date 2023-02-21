//
// Created by nikita on 10.02.23.
//

#include "Polygon.h"

Polygon::Polygon() : Shape() {
    polygon = new QPolygonF;
}

inline double get_distance(QPointF p1, QPointF p2) {
    double dx = p1.x() - p2.x();
    double dy = p1.y() - p2.y();
    return sqrt(dx * dx + dy * dy);
}

//void Polygon::poligonUpdate() {
//    auto *p = new QPolygon;
//    for (int i = 0; i < polygon->size(); i++) {
//        p->append(QPoint(polygon->at(i).x() - center.x() + newCenter.x(),
//                         polygon->at(i).y() - center.y() + newCenter.y()));
//    }
//    delete polygon;
//    polygon = p;
//}

int Polygon::calculateSpace() {
    /*double ans = 0;
    for (int i = 0; i < polygon->size() - 1; i++) {
        ans += polygon->at(i).x() * polygon->at(i + 1).y();
        ans -= polygon->at(i + 1).x() * polygon->at(i).y();
    }
    ans += polygon->at(polygon->size() - 1).x() * polygon->at(0).y();
    ans -= polygon->at(polygon->size() - 1).y() * polygon->at(0).x();
    return qAbs(ans / 2);*/

    double area = 0.0;
    int n = polygon->size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += polygon->at(i).x() * polygon->at(j).y() - polygon->at(j).x() * polygon->at(i).y();
    }
    area /= 2.0;
    return qAbs(area);
}

int Polygon::calculatePerimeter() {
    /*int perimeter = 0;
    int pointCount = polygon->size();

    for (int i = 0; i < pointCount - 1; i++) {
        QPointF point1 = polygon->at(i);
        QPointF point2 = polygon->at(i + 1);
        int dx = point2.x() - point1.x();
        int dy = point2.y() - point1.y();
        perimeter += qSqrt(dx * dx + dy * dy);
    }
    QPointF point1 = polygon->at(pointCount - 1);
    QPointF point2 = polygon->at(0);
    int dx = point2.x() - point1.x();
    int dy = point2.y() - point1.y();
    perimeter += qSqrt(dx * dx + dy * dy);
    return perimeter;*/

    int perimeter = 0;
    int n = polygon->size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimeter += get_distance(polygon->at(i), polygon->at(j));
    }
    return perimeter;
}

QPoint Polygon::calculateCentroid() {
    int area = 0.0;
    int cx = 0.0;
    int cy = 0.0;
    int n = polygon->size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int cross = polygon->at(i).x() * polygon->at(j).y() - polygon->at(j).x() * polygon->at(i).y();
        area += cross;
        cx += (polygon->at(i).x() + polygon->at(j).x()) * cross;
        cy += (polygon->at(i).y() + polygon->at(j).y()) * cross;
    }
    area /= 2;
    if (area == 0)
        return {0, 0};
    cx /= (6 * area);
    cy /= (6 * area);
    return {cx, cy};

//    return {0,0};

//    if (area == 0)
//        return {0, 0};
//    area /= 2;
//    return {sumX / (6 * area), sumY / (6 * area)};
//    return {0, 1};
}

void Polygon::draw(QPainter *painter) {
    brush->setColor(*color);
    painter->setBrush(*brush);
    painter->drawPolygon(*polygon);
    if (polygon->size() > 1 && polygon->at(0) != polygon->at(1))
        for (int i = 0; i < polygon->size(); ++i) {
            painter->drawEllipse(polygon->at(i), 5, 5);
        }
//    painter->save();
//    painter->restore();
}

void Polygon::rotateShape(const QPoint &p, double angle) {
    QPolygonF result;
    angle *= M_PI / 180;
    QTransform transform;
    transform.translate(p.x(), p.y()); // сдвигаем точку вращения в p(x, y)
    transform.rotateRadians(angle); // вращаем полигон на заданный угол
    transform.translate(-p.x(), -p.y()); // возвращаем точку вращения на исходную позицию

    // преобразуем полигон с помощью матрицы преобразования
    result = transform.map(*polygon);

    *polygon = result;
}

void Polygon::moveShape(QPoint mouse) {
    int pointCount = polygon->size();
    QPolygonF result;
    for (int i = 0; i < pointCount; i++) {
        result << polygon->at(i) + mouse - calculateCentroid();
        qDebug() << mouse;
    }
    *polygon = result;
}

void Polygon::scaleShape(double k) {
    int pointCount = polygon->size();
    QPolygonF result;
    for (int i = 0; i < pointCount; i++) {
        result << QPointF(polygon->at(i).x() + (polygon->at(i).x() - calculateCentroid().x()) * k,
                          polygon->at(i).y() + (polygon->at(i).y() - calculateCentroid().y()) * k);
    }
    *polygon = result;
}
