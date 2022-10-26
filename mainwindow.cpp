#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    first = true;
    firstClick = true;
    rev = 7;
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::Any,8080);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::ReadSocket);
    if(!socket->waitForConnected()){
        exit(EXIT_FAILURE);
    }
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::WindowTimer);
    timer->start(1000);
    whiteTime = new QTime(1,0,0);
    whiteTimeLabel = new QLabel(this);
    whiteTimeLabel->setText(whiteTime->toString("h:mm:ss"));
    whiteTimeLabel->move(48, 0);
    whiteTimeLabel->setStyleSheet("font-size: 30px");
    whiteTimeLabel->show();
    blackTime = new QTime(1,0,0);
    blackTimeLabel = new QLabel(this);
    blackTimeLabel->setText(blackTime->toString("h:mm:ss"));
    blackTimeLabel->move(650, 0);
    blackTimeLabel->setStyleSheet("font-size: 30px");
    blackTimeLabel->show();
    wid = new QWidget(this);
    wid->move(200,50);
    wid->resize(8 * 50, 8 * 50);
    wid->setStyleSheet("background-color: rgba(20, 85, 30, 0.5)");
    for(int i = 0; i < 10; i++){
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(i*50 + 150, 0);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        if(i != 0 && i!= 9){
            button->setText(QChar('a' + i - 1));
        }
    }
    for(int i = 0; i < 10; i++){
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(i*50 + 150, 450);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        if(i != 0 && i != 9){
            button->setText(QChar('a' + i - 1));
        }
    }
    QWidget* blackW = new QWidget(this);
    blackW->move(50,50);
    blackW->resize(2*50, 8*50);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
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
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            QPushButton* button = new QPushButton(whiteW);
            white.push_back(button);
            button->resize(50,50);
            button->move(i*50, j*50);
            button->setStyleSheet("background-color: rgb(255,255,255);");
        }
    }
}

void MainWindow::WindowTimer() {
    if (temp % 2 == 1) {
        *whiteTime = whiteTime->addSecs(-1);
        whiteTimeLabel->move(50, 0);
        whiteTimeLabel->setText(whiteTime->toString("mm:ss"));
        whiteTimeLabel->update();
        if (whiteTime->minute() == 0 && whiteTime->second() == 0) {
            GameOver();
        }
    } else if (temp % 2 == 0) {
        *blackTime = blackTime->addSecs(-1);
        blackTimeLabel->move(650, 0);
        blackTimeLabel->setText(blackTime->toString("mm:ss"));
        blackTimeLabel->update();
        if(blackTime->minute() == 0 && blackTime->second() == 0) {
            GameOver();
        }
    }
}

void MainWindow::AddWindowStyle() {
    for (int i = 0; i < 8; i++) {
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(600, i*50 + 50);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        button->setText(QString::number(abs(rev - i) + 1));
    }
    for (int i = 0; i < 8; i++) {
        QPushButton* button = new QPushButton(this);
        button->resize(50,50);
        button->move(150, i*50 + 50);
        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
        button->setText(QString::number(abs(rev - i) + 1 ));
    }
    startWid = new QWidget(this);
    startWid->resize(window()->size());
    startWid->setStyleSheet("background-color: rgba(255, 255, 255, 0.5)");
    QLabel* startLabel = new QLabel(startWid);
    startLabel->setText("WAIT FOR CONNECTION!");
    startLabel->setStyleSheet("font-size: 70px");
    startLabel->move(0, 200);
    startWid->hide();
    if (temp == PAUSE) {
        startWid->show();
    }
}

void MainWindow::ClickedSlot() {
    QPushButton* button = (QPushButton*)sender();
    if (socket) {
        if (socket->isOpen()) {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_3);
            if (temp % 2 == 1) {
                out << abs(rev - (button->pos().y()) / 50) << (button->pos().x()) / 50;
                qDebug() << abs(rev - (button->pos().y()) / 50) << (button->pos().x()) / 50;
                socket->write(block);
            }
        }
    }
}

void MainWindow::CreateButton(std::vector<std::vector<Figur*>>& figur, Coordinates coord) {
    QPushButton* button = new QPushButton(wid);
    if (temp == 0) {
        qDebug() << temp;
        rev = 0;
    }
    button->resize(50,50);
    button->move(coord.y*50, abs(rev - coord.x)*50);
    if(((coord.x + coord.y)%2) == 0){
        button->setStyleSheet(QString("border: 0 ;background-color: rgb(239,218,181);"));
    }else{
        button->setStyleSheet(QString("border: 0 ;background-color: rgb(180,137,99);"));
    }
    QPixmap a(figur[coord.x][coord.y]->GetPath());
    QIcon b(a);
    button->setIcon(b);
    button->setIconSize(button->size());
    connect(button, &QPushButton::clicked, this, &MainWindow::ClickedSlot);
}

void MainWindow::CanMove(std::vector<Coordinates> move, Coordinates clickButton){
    if (!move.empty()) {
        if (temp % 2 == 1) {
            QList<QPushButton*> pButton = wid->findChildren<QPushButton*>();
            for (auto k = pButton.begin(); k != pButton.end(); k++) {
                for (int i = 0; i < (int)move.size(); i++) {
                    if (abs(rev - ((*k)->y())/50) == clickButton.x && ((*k)->x())/50 == clickButton.y) {
                        if (firstClick) {
                            (*k)->setStyleSheet("border: 0; background-color: rgba(20, 85, 30, 0.5);");
                        } else {
                            if(((clickButton.x + clickButton.y)%2) == 0){
                                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(239,218,181);"));
                            } else {
                                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(180,137,99);"));
                            }
                        }
                    }
                    if (abs(rev - ((*k)->y())/50) == move[i].x && ((*k)->x())/50 == move[i].y) {
                        if (firstClick) {
                            QString cs1;
                            if ((*k)->icon().isDetached()) {
                                cs1 = "QPushButton {" + (*k)->styleSheet() + "image: url(:/image/ket.png);}"
                                              "QPushButton:hover {background-color: rgba(20, 85, 30, 0.5); image: 0;}";
                            } else {
                                cs1 = "QPushButton {" + (*k)->styleSheet() + "border-radius: 20px}"
                                              "QPushButton:hover {background-color: rgba(20, 85, 30, 0.5); image: 0;}";
                            }
                            (*k)->setStyleSheet(cs1);
                        } else {
                            if (((move[i].x + move[i].y)%2) == 0) {
                                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(239,218,181);"));
                            } else {
                                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(180,137,99);"));
                            }
                        }
                    }
                }
            }
        }
        firstClick = !firstClick;
    }
}

void MainWindow::MoveTo(Coordinates c, Coordinates new_c, Color color) {
    QList<QPushButton*> button = wid->findChildren<QPushButton*>();
    for (auto k = button.begin(); k != button.end(); k++) {
        if (((*k)->pos().x() / 50) == c.y && abs(rev - (*k)->pos().y() / 50) == c.x) {
            (*k)->setGeometry(1000, 1000, 50, 50);
        }
    }
    for (auto k = button.begin(); k != button.end(); k++) {
        if (((*k)->pos().x() / 50) == new_c.y && abs(rev - (*k)->pos().y() / 50) == new_c.x) {
            (*k)->setGeometry(c.y * 50, abs(rev - c.x) * 50, 50, 50);
            if (((c.x + c.y) %2 ) == 0) {
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(239,218,181);"));
            } else {
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(180,137,99);"));
            }
            if (color == Color::Black) {
                black[tBlack]->setIcon((*k)->icon());
                black[tBlack]->setIconSize(black[tBlack]->size());
                tBlack++;
            } else if(color == Color::White) {
                white[tWhite]->setIcon((*k)->icon());
                white[tWhite]->setIconSize(white[tWhite]->size());
                tWhite++;
            }
            (*k)->setIcon(QIcon());
        }
        if (((*k)->pos().x()) == 1000 && ((*k)->pos().y()) == 1000) {
            (*k)->setGeometry(new_c.y * 50, abs(rev - new_c.x) * 50, 50, 50);
            if(((new_c.x + new_c.y)%2) == 0){
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(239,218,181);"));
            } else {
                (*k)->setStyleSheet(QString("border: 0 ;background-color: rgb(180,137,99);"));
            }
        }
    }
}

void MainWindow::DeletePawn(Coordinates c, Color color) {
    QList<QPushButton*> button = wid->findChildren<QPushButton*>();
    for (auto k = button.begin(); k != button.end(); k++) {
        if (((*k)->pos().x() / 50) == c.y && abs(rev - (*k)->pos().y() / 50) == c.x) {
            if (color == Color::Black) {
                black[tBlack]->setIcon((*k)->icon());
                black[tBlack]->setIconSize(black[tBlack]->size());
                tBlack++;
            } else if (color == Color::White) {
                white[tWhite]->setIcon((*k)->icon());
                white[tWhite]->setIconSize(white[tWhite]->size());
                tWhite++;
            }
            (*k)->setIcon(QIcon());
        }
    }
}

void MainWindow::ChangePawnClick() {
    QPushButton* button = (QPushButton*)sender();
    QWidget* widget = button->parentWidget();
    if (socket) {
        if (socket->isOpen()) {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_3);
            out  << PAUSE;
            if (button->pos().x() == 0 && button->pos().y() == 0) {
                out << 1;
            } else if (button->pos().x() == 0 && button->pos().y() == 25) {
                out << 2;
            } else if (button->pos().x() == 25 && button->pos().y() == 0) {
                out << 3;
            } else if (button->pos().x() == 25 && button->pos().y() == 25) {
                out << 4;
            }
            out << abs(rev - ((widget->pos().y() - 50) / 50)) << (widget->pos().x() - 200) / 50;
            qDebug() << abs(rev - ((widget->pos().y() - 50) / 50)) << (widget->pos().x() - 200) / 50;
            socket->write(block);
        }
    }
    while (widget->findChild<QPushButton*>()) {
        delete widget->findChild<QPushButton*>();
    }
    delete widget;
}

void MainWindow::ChangePawn(Coordinates c, Color color) {
    QWidget* widget = new QWidget(this);
    widget->move(200 + c.y * 50, 50 + abs(rev - c.x) * 50);
    widget->resize(50, 50);
    if (color == Color::Black) {
        QPushButton* b = new QPushButton(widget);
        b->resize(25, 25);
        b->move(0, 0);
        b->setIcon(QIcon(QString(":/image/Bishop.png")));
        b->setIconSize(b->size());
        if (temp % 2 != 1) {
            connect(b, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
        QPushButton* q = new QPushButton(widget);
        q->resize(25, 25);
        q->move(0, 25);
        q->setIcon(QIcon(QString(":/image/Queen.png")));
        q->setIconSize(q->size());
        if (temp % 2 != 1) {
            connect(q, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
        QPushButton* r = new QPushButton(widget);
        r->resize(25, 25);
        r->move(25, 0);
        r->setIcon(QIcon(QString(":/image/Rook.png")));
        r->setIconSize(r->size());
        if (temp % 2 != 1) {
            connect(r, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
        QPushButton* k = new QPushButton(widget);
        k->resize(25, 25);
        k->move(25, 25);
        k->setIcon(QIcon(QString(":/image/Knight.png")));
        k->setIconSize(k->size());
        if (temp % 2 != 1) {
            connect(k, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
    } else {
        QPushButton* b = new QPushButton(widget);
        b->resize(25, 25);
        b->move(0, 0);
        b->setIcon(QIcon(QString(":/image/Bishop1.png")));
        b->setIconSize(b->size());
        if (temp % 2 != 1) {
            connect(b, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
        QPushButton* q = new QPushButton(widget);
        q->resize(25, 25);
        q->move(0, 25);
        q->setIcon(QIcon(QString(":/image/Queen1.png")));
        q->setIconSize(q->size());
        if (temp % 2 != 1) {
            connect(q, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
        QPushButton* r = new QPushButton(widget);
        r->resize(25, 25);
        r->move(25, 0);
        r->setIcon(QIcon(QString(":/image/Rook1.png")));
        r->setIconSize(r->size());
        if (temp % 2 != 1) {
            connect(r, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
        QPushButton* k = new QPushButton(widget);
        k->resize(25, 25);
        k->move(25, 25);
        k->setIcon(QIcon(QString(":/image/Knight1.png")));
        k->setIconSize(k->size());
        if (temp % 2 != 1) {
            connect(k, &QPushButton::clicked, this, &MainWindow::ChangePawnClick);
        }
    }
    if (socket) {
        if (socket->isOpen()) {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_3);
            out << PAUSE;
            socket->write(block);
        }
    }
    widget->show();
}

void MainWindow::GameOver(){
    timer->stop();
    QWidget* k = new QWidget(this);
    QLabel* f = new QLabel(k);
    if (temp % 2 == 1) {
            f->setText("YOU LOSE");
            f->move(wid->pos().x() + 1, wid->pos().y() + 140);
        } else {
            f->setText("YOU WIN");
            f->move(wid->pos().x() + 12.5, wid->pos().y() + 140);
        }
    k->resize(window()->size());
    k->setStyleSheet("font-size: 85px; background-color: rgba(255, 255, 255, 0.08); color: rgba(10, 60, 50, 0.7);");
    k->show();

}

MainWindow::~MainWindow(){
    if (socket->isOpen()) {
        socket->close();
    }
    delete ui;
}

