#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PAUSE -1

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QTcpSocket>
#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>
#include <QTime>

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
    ~MainWindow();
public slots:
    void WindowTimer();
    void ChangePawnClick();
    void ClickedSlot();
    virtual void ReadSocket() = 0;
private:
    int tBlack = 0;
    int tWhite = 0;
    QTimer* timer;
    QTime* blackTime;
    QTime* whiteTime;
    QLabel* whiteTimeLabel;
    QLabel* blackTimeLabel;
    std::vector<QPushButton*> black;
    std::vector<QPushButton*> white;
    Ui::MainWindow *ui;
protected:
    int temp;
    int rev;
    bool first;
    bool firstClick;
    Coordinates prev_buttonCoord;
    Coordinates buttonCoord;
    QWidget* wid;
    QWidget* startWid;
    QTcpSocket* socket;    
protected:
    void CreateButton(std::vector<std::vector<Figur*>>& figur, Coordinates coord);
    void CanMove(std::vector<Coordinates> move, Coordinates clickButton);
    void MoveTo(Coordinates c, Coordinates new_c, Color color);
    void ChangePawn(Coordinates c, Color color);
    void DeletePawn(Coordinates c, Color color);
    void AddWindowStyle();
    void GameOver();
};
#endif // MAINWINDOW_H
