#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wid = new QWidget(this);
    wid->move(200,50);
    wid->resize(8 * 50, 8 * 50);
    for(int i = 0; i < 10; i++){
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(i*50 + 150, 0);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        if(i != 0 && i!= 9){
            button->setText(QChar('a'+i));
        }
    }
    for(int i = 0; i < 8; i++){
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(150, i*50 + 50);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        button->setText(QString::number(i + 1));
    }
    for(int i = 0; i < 10; i++){
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(i*50 + 150, 450);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        if(i != 0 && i!= 9){
            button->setText(QChar('a'+i));
        }
    }
    for(int i = 0; i < 8; i++){
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(600, i*50 + 50);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        button->setText(QString::number(i + 1));
    }
    QWidget* blackW = new QWidget(this);
    blackW->move(50,50);
    blackW->resize(2*50, 8*50);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            QPushButton* button = new QPushButton(blackW);
            black.push_back(button);
            button->resize(50,50);
            button->move(i*50, j*50);
            button->setStyleSheet("background-color: rgb(255,255,255);");
        }
    }
    QWidget* whiteW = new QWidget(this);
    whiteW->move(650,50);
    whiteW->resize(2*50, 8*50);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            QPushButton* button = new QPushButton(whiteW);
            white.push_back(button);
            button->resize(50,50);
            button->move(i*50, j*50);
            button->setStyleSheet("background-color: rgb(255,255,255);");
        }
    }
}

void MainWindow::ClickedSlot(){
    QPushButton* button = (QPushButton*)sender();
    buttonC.x = (button->pos().y()) / 50;
    buttonC.y = (button->pos().x()) / 50;
}

void MainWindow::CreateButton(std::vector<std::vector<Figur*>>& figur, Coordinates coord){
    QPushButton* button = new QPushButton(wid);
    button->resize(50,50);
    button->move(coord.y*50, coord.x*50);
    if(((coord.x + coord.y)%2) == 0){
        button->setStyleSheet(QString("border: 0 ;background-color: rgb(0,0,0);"));
    }else{
        button->setStyleSheet(QString("border: 0 ;background-color: rgb(255,255,255);"));
    }
    QPixmap a(figur[coord.x][coord.y]->getPath());
    QIcon b(a);
    button->setIcon(b);
    button->setIconSize(button->size());
    connect(button, &QPushButton::clicked, this, &MainWindow::ClickedSlot);
}

void MainWindow::Move(std::vector<Coordinates> move){
    QList<QPushButton*> pButton = wid->findChildren<QPushButton*>();
    for(auto k = pButton.begin(); k != pButton.end(); k++){
        for(int i = 0; i < (int)move.size(); i++){
            if(((*k)->y())/50 == move[i].x && ((*k)->x())/50 == move[i].y){
                if(!click){
                    (*k)->setStyleSheet("border: 0; background-color: rgb(255,0,0);");
                }else{
                    if(((move[i].x + move[i].y)%2) == 0){
                        (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(0,0,0);"));
                    }else{
                        (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(255,255,255);"));
                    }
                }
            }
        }
    }
    click = !click;
}

void MainWindow::MoveTo(Coordinates c, Coordinates new_c, Color color){
    QList<QPushButton*> button = wid->findChildren<QPushButton*>();
    for(auto k = button.begin(); k != button.end(); k++){
        if(((*k)->pos().x() / 50) == c.y && ((*k)->pos().y() / 50) == c.x){
            (*k)->setGeometry(1000, 1000, 50, 50);
        }
    }
    for(auto k = button.begin(); k != button.end(); k++){
        if(((*k)->pos().x() / 50) == new_c.y && ((*k)->pos().y() / 50) == new_c.x){
            (*k)->setGeometry(c.y * 50, c.x * 50, 50, 50);
            if(((c.x + c.y)%2) == 0){
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(0,0,0);"));
            }else{
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(255,255,255);"));
            }
            if(color == Color::Black){
                black[tBlack]->setIcon((*k)->icon());
                black[tBlack]->setIconSize(black[tBlack]->size());
                tBlack++;
            }else if(color == Color::White){
                white[tWhite]->setIcon((*k)->icon());
                white[tWhite]->setIconSize(white[tWhite]->size());
                tWhite++;
            }
            (*k)->setIcon(QIcon());
        }
        if(((*k)->pos().x()) == 1000 && ((*k)->pos().y()) == 1000){
            (*k)->setGeometry(new_c.y * 50, new_c.x * 50, 50, 50);
            if(((new_c.x + new_c.y)%2) == 0){
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(0,0,0);"));
            }else{
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(255,255,255);"));
            }
        }
    }
}

void MainWindow::DeletePawn(Coordinates c, Color color){
    QList<QPushButton*> button = wid->findChildren<QPushButton*>();
    for(auto k = button.begin(); k != button.end(); k++){
        if(((*k)->pos().x() / 50) == c.y && ((*k)->pos().y() / 50) == c.x){
            if(color == Color::Black){
                black[tBlack]->setIcon((*k)->icon());
                black[tBlack]->setIconSize(black[tBlack]->size());
                tBlack++;
            }else if(color == Color::White){
                white[tWhite]->setIcon((*k)->icon());
                white[tWhite]->setIconSize(white[tWhite]->size());
                tWhite++;
            }
            (*k)->setIcon(QIcon());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

