#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QTcpSocket>

#include "Figur.h"
#include "Piece.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int color = 5;
    MainWindow(QWidget *parent = nullptr);
    void CanMove(std::vector<Coordinates> move);
    void MoveTo(Coordinates c, Coordinates new_c, Color color);
    void DeletePawn(Coordinates c, Color color);
    void CreateButton(std::vector<std::vector<Figur*>>& figur, Coordinates coord);
    Coordinates get(){
        return buttonC;
    }
    void set(){
        buttonC = {-1,-1};
    }
    ~MainWindow();
public slots:
    void ReadSocket();
    void ClickedSlot();
private:
    QTcpSocket* socket;
    QWidget* wid;
    int tBlack = 0;
    int tWhite = 0;
    std::vector<QPushButton*> black;
    std::vector<QPushButton*> white;
    Coordinates buttonC = {-1,-1};
    bool firstClick = true;
    bool first = true;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
