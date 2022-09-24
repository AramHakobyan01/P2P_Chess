#include "Board.h"

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    Board b(&w);
    w->show();
    b.Start(&w);
    return a.exec();
}
