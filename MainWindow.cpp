//
// Created by nikita on 10.02.23.
//
#include "MainWindow.h"

MainWindow::MainWindow() : QWidget() {

    startTimer(20);
    resize(1000, 600);
    setMinimumSize(1000, 600);

    hBoxLayout = new QHBoxLayout;
    vBoxLayout = new QVBoxLayout;
    inVBoxLayout = new QHBoxLayout;
//    values = new Values;

    auto colorButton = new QPushButton("SET COLOR");

    auto colorDialog = new QColorDialog;

    label = new QLabel;
    board = new Board(this);
    hBoxLayout->addWidget(board, 2);
    setLayout(hBoxLayout);

    vBoxLayout->setSpacing(2);
    auto *square = new QPushButton("Square");
    vBoxLayout->addWidget(square);
    auto *rectangular = new QPushButton("Rect");
    vBoxLayout->addWidget(rectangular);
    auto *circle = new QPushButton("Circle");
    vBoxLayout->addWidget(circle);
    auto *ellipse = new QPushButton("Ellipse");
    vBoxLayout->addWidget(ellipse);
    auto *star = new QPushButton("Star");
    vBoxLayout->addWidget(star);
    auto *triangular = new QPushButton("Triangular");
    vBoxLayout->addWidget(triangular);
    auto *painter = new QPushButton("Painter");
    vBoxLayout->addWidget(painter);
    auto *random = new QPushButton("Random");
    vBoxLayout->addWidget(random);
    auto *rotate = new QPushButton("Rotate");
    vBoxLayout->addWidget(rotate);
    auto *move = new QPushButton("Move");
    vBoxLayout->addWidget(move);
    auto *scale = new QPushButton("Scale");
    vBoxLayout->addWidget(scale);
    vBoxLayout->addWidget(colorButton);
    vBoxLayout->addWidget(label);

    connect(square, SIGNAL(released()), board, SLOT(setSquare()));
    connect(rectangular, SIGNAL(released()), board, SLOT(setRectangular()));
    connect(circle, SIGNAL(released()), board, SLOT(setCircle()));
    connect(star, SIGNAL(released()), board, SLOT(setStar()));
    connect(ellipse, SIGNAL(released()), board, SLOT(setEllipse()));
    connect(triangular, SIGNAL(released()), board, SLOT(setTriangular()));
    connect(painter, SIGNAL(released()), board, SLOT(setLine()));
    connect(random, SIGNAL(released()), board, SLOT(setRandom()));
    connect(colorButton, SIGNAL(released()), board, SLOT(setColor()));
    connect(rotate, SIGNAL(released()), board, SLOT(rotateShape()));
    connect(move, SIGNAL(released()), board, SLOT(moveShape()));
    connect(scale, SIGNAL(released()), board, SLOT(scaleShape()));

    hBoxLayout->addLayout(vBoxLayout);
}

void MainWindow::timerEvent(QTimerEvent *event) {
    label->setText(
            "CENTER\nX:" + QString::number(board->shapeCenter().x()) + " Y:" +
            QString::number(board->shapeCenter().y()) + "\nPERIMETER: " + QString::number(board->shapePerimeter()) +
            "\nSPACE: " + QString::number(board->shapeSpace()));
}

void MainWindow::stopValueUpdate() {
//    valueUpdate = false;
}

void MainWindow::startValueUpdate() {
//    valueUpdate = true;
//    inputCenterX->setValue(values->center.x());
//    inputCenterY->setValue(values->center.y());
}

