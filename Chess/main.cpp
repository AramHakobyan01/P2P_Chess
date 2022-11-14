#include "mainwindow.h"
#include "Board.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board b;
    return a.exec();
}
