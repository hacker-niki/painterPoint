#include "MainWindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    auto *win = new MainWindow;
    win->show();

    return QApplication::exec();

}
