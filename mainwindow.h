#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <iostream>

#include "Figur.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void ShowMove(std::vector<Coordinates> move);
    void CreateButton(std::vector<std::vector<Figur*>>& figur, Coordinates coord){
        QPushButton* button_ = new QPushButton(wid);
        button_->resize(50,50);
        button_->move(coord.y*50, coord.x*50);


//        if(((coord.x + coord.y)%2) == 0){
//        }else{
//            button_->setStyleSheet(QString("background-color: rgb(255,255,255);"));
//        }

        QPixmap a(figur[coord.x][coord.y]->getPath());
        QIcon b(a);
        button_->setIcon(b);
        button_->setIconSize(button_->size());
        //QObject::connect(button_, SIGNAL(clicked()),this, SLOT(ClickedSlot()));
       // button->show();
       // wid->show();
        //wid->show();
        connect(button_, &QPushButton::clicked, this, &MainWindow::ClickedSlot);
    }
    Coordinates get(){
        return buttonC;
    }
    void set(){
        buttonC = {-1,-1};
    }
    void move();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void ClickedSlot();

private:
    QWidget* wid ;
    Coordinates buttonC = {-1,-1};
    bool click = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
