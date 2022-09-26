#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>

#include "Figur.h"
#include "Piece.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void Move(std::vector<Coordinates> move);
    void MoveTo(Coordinates c, Coordinates new_c, Color color);
    void DeletePawn(Coordinates c, Color color);
    void CreateButton(std::vector<std::vector<Figur*>>& figur, Coordinates coord);
    static Coordinates get(){
        return buttonC;
    }
    static void set(){
        buttonC = {-1,-1};
    }
    ~MainWindow();
public slots:
    void ClickedSlot();
private:
     QWidget* wid;
     int tBlack = 0;
     int tWhite = 0;
     std::vector<QPushButton*> black;
     std::vector<QPushButton*> white;
     static inline Coordinates buttonC = {-1,-1};
     static inline bool click = false;
     Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
