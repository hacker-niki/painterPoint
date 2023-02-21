//
// Created by nikita on 10.02.23.
//

#ifndef PAINTERPOINT_MAINWINDOW_H
#define PAINTERPOINT_MAINWINDOW_H


#include <QtWidgets>
#include <QLabel>
#include "Board.h"
#include <QColorDialog>
#include "Shapes/Shape.h"

class MainWindow : public QWidget {
Q_OBJECT
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
    QHBoxLayout *inVBoxLayout;

    QSpinBox *inputCenterX;
    QSpinBox *inputCenterY;
    Board *board;
    QLabel *label;

public:
    MainWindow();

    void timerEvent(QTimerEvent *event) override;

public slots:

    void stopValueUpdate();

    void startValueUpdate();

//    void setColor();
};

#endif //PAINTERPOINT_MAINWINDOW_H
