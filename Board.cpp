//
// Created by nikita on 10.02.23.
//

#include <QInputDialog>
#include "Board.h"
#include "Shapes/Star.h"
#include "Shapes/Triangular.h"
#include "Shapes/Random.h"
#include "Shapes/Painter.h"

Board::Board(QWidget *par) : QWidget(par)/*, mousePressed(false)*/, drawing(false)/*, isDrawed(false)*/,
                             rotating(false), angle(0), cnt(0), newCenterM(0, 0), pressed(false),
                             moving(false), scaling(false), scaleCoef(0), movingVertex(false), vertex(0), mousePressed(false) {
    brush = new QBrush(Qt::BrushStyle::SolidPattern);
    shape = new Shape;
    resize(par->width(), par->height());
    startTimer(20);
//    setMouseTracking(true);
}

void Board::mousePressEvent(QMouseEvent *event) {
    mousePressed = true;
    currentMouse = event->pos();
    if (drawing) {
        shape->setStart(currentMouse);
    } else if (rotating) {
        if (currentMouse.x() < this->width() && currentMouse.y() < this->height()) {
            angle = QInputDialog::getInt(nullptr, "ANGLE", "DEG: ", 0, 0, 360);
            pressed = true;
        }
    } else if (moving) {
        if (currentMouse.x() < this->width() && currentMouse.y() < this->height()) {
            pressed = true;
        }
    } else if (!movingVertex && shape->polygon->size() != 0) {
        for (int i = 0; i < shape->polygon->size(); i++) {
            if (qAbs(currentMouse.x() - shape->polygon->at(i).x()) <= 10 &&
                qAbs(currentMouse.y() - shape->polygon->at(i).y()) <= 10) {
//                qDebug() << currentMouse.x() << ' ' << currentMouse.y();
                vertex = i;
                movingVertex = true;
            }
        }
    } else if (!movingVertex) {
        if ((qAbs(currentMouse.x() - shape->rect.topLeft().x()) <= 10 &&
             qAbs(currentMouse.y() - shape->rect.topLeft().y()) <= 10)) {
            vertex = 0;
            movingVertex = true;
        }
        if (qAbs(currentMouse.x() - shape->rect.topRight().x()) <= 10 &&
            qAbs(currentMouse.y() - shape->rect.topRight().y()) <= 10) {
            vertex = 1;
            movingVertex = true;
        }
        if (qAbs(currentMouse.x() - shape->rect.bottomLeft().x()) <= 10 &&
            qAbs(currentMouse.y() - shape->rect.bottomLeft().y()) <= 10) {
            vertex = 2;
            movingVertex = true;
        }
        if (qAbs(currentMouse.x() - shape->rect.bottomRight().x()) <= 10 &&
            qAbs(currentMouse.y() - shape->rect.bottomRight().y()) <= 10) {
            vertex = 3;
            movingVertex = true;
        }
    }
    pressedMouse = currentMouse;
}

void Board::mouseReleaseEvent(QMouseEvent *event) {
    mousePressed = false;
    currentMouse = event->pos();
    drawing = false;
    movingVertex = false;
//    isDrawed = true;
}

void Board::mouseMoveEvent(QMouseEvent *event) {
    currentMouse = event->pos();
}

void Board::paintEvent(QPaintEvent *event) {
    painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(*brush);
    if (drawing && mousePressed)
        shape->setPoints(&currentMouse);
//    if(isDrawed)
    shape->draw(painter);
    painter->end();
}

void Board::timerEvent(QTimerEvent *event) {
    update();
    if (rotating && pressed) {
        shape->rotateShape(currentMouse, angle / 20);
        cnt++;
        if (cnt == 20) {
//            setWindowModality(Qt::WindowModality::NonModal);
            rotating = !rotating;
            cnt = 0;
            angle = 0;
            pressed = !pressed;
        }
    } else if (moving && pressed) {
        if (newCenterM == QPoint(0, 0))
            newCenterM = QPoint(((-shape->calculateCentroid().x() + currentMouse.x()) / 20),
                                ((-shape->calculateCentroid().y() + currentMouse.y()) / 20));
        shape->moveShape(shape->calculateCentroid() + newCenterM);
        cnt++;
        if (cnt == 20) {
//            setWindowModality(Qt::WindowModality::NonModal);
            moving = !moving;
            cnt = 0;
            pressed = !pressed;
            newCenterM = QPoint(0, 0);
        }
    } else if (scaling/* && pressed*/) {
        if (scaleCoef == 0)
            scaleCoef = QInputDialog::getDouble(nullptr, "SCALE", "coefficient: ", 0.1, 0.1, 4);

        shape->scaleShape((scaleCoef - 1) / 20);
        cnt++;
        if (cnt == 20) {
            setWindowModality(Qt::WindowModality::NonModal);
            scaling = false;
            cnt = 0;
            scaleCoef = 0;
            pressed = false;
        }

    } else if (movingVertex && shape->polygon->size() != 0) {
        shape->polygon->replace(vertex, currentMouse);
    } else if (movingVertex) {
        if (vertex == 0)
            shape->rect.setCoords(currentMouse.x(), currentMouse.y(), shape->rect.bottomRight().x(),
                                  shape->rect.bottomRight().y());
        if (vertex == 1)
            shape->rect.setCoords(shape->rect.topLeft().x(), currentMouse.y(), currentMouse.x(),
                                  shape->rect.bottomRight().y());
        if (vertex == 2)
            shape->rect.setCoords(currentMouse.x(), shape->rect.topLeft().y(), shape->rect.bottomRight().x(),
                                  currentMouse.y());
        if (vertex == 3)
            shape->rect.setCoords(shape->rect.topLeft().x(), shape->rect.topLeft().y(), currentMouse.x(),
                                  currentMouse.y());
    }
//    shape->rotateShape()
}

void Board::setSquare() {
    delete shape;
    shape = new Square;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setRectangular() {
    delete shape;
    shape = new Rectangular;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setCircle() {
    delete shape;
    shape = new Circle;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setEllipse() {
    delete shape;
    shape = new Ellipse;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setStar() {
    delete shape;
    shape = new Star;
    shape->numRays = QInputDialog::getInt(nullptr, "STAR", "rays: ", 5, 3, 8);
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setTriangular(){
    delete shape;
    shape = new Triangular;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setRandom() {
    delete shape;
    shape = new Random;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setLine() {
    delete shape;
    shape = new Painter;
    drawing = true;
    currentMouse = {0, 0};
    pressedMouse = {0, 0};
}

void Board::setColor() {
    *shape->color = QColorDialog::getColor();
}

QPoint Board::shapeCenter() {
    return shape->calculateCentroid();
}

int Board::shapePerimeter() {
    return shape->calculatePerimeter();
}

int Board::shapeSpace() {
    return shape->calculateSpace();
}

void Board::rotateShape() {
//    setWindowModality(Qt::WindowModality::WindowModal);
    rotating = !rotating;
}

void Board::moveShape() {
    moving = !moving;
}

void Board::scaleShape() {
    scaling = !scaling;
}