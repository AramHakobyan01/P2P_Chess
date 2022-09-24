#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wid = new QWidget(this);
    wid->move(200,50);
    wid->resize(8 * 50, 8 * 50);
    wid->show();
}
void MainWindow::ClickedSlot(){
    QPushButton* button = (QPushButton*)sender();
    buttonC.x = (button->pos().y()) / 50;
    buttonC.y = (button->pos().x()) / 50;
}
void MainWindow::ShowMove(std::vector<Coordinates> move){
    QList<QPushButton*> pButton = this->findChildren<QPushButton*>();
    for(auto k = pButton.begin(); k != pButton.end(); k++){
        for(int i = 0; i < (int)move.size(); i++){
            if(((*k)->y())/50 == move[i].x && ((*k)->x())/50 == move[i].y){
                (*k)->setStyleSheet("border: 0; background-color: rgb(255,0,0);");
            }
        }
    }
}
//void MainWindow::Butten(std::vector<std::vector<Figur*>>& figur){
//    int rows = 8, columns = 8;

//    pButton.clear();
//    //chackButton.clear();
//    QWidget* w = new QWidget(this);
//    w->move(200,50);
//    w->resize(rows * 50, columns * 50);
//    QLabel* num = new QLabel(this);
//    num->move(150,50);
//    num->resize(50, 8 * 50);
//    for(int i = 0; i < 8; i++){
//        QPushButton* button = new QPushButton(num);
//        button->resize(50,50);
//        button->move(0, i*50);
//        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
//        button->setText(QString::number(i + 1));
//    }
//    QWidget* ch = new QWidget(this);
//    ch->move(150,0);
//    ch->resize(10*50, 50);
//    for(int i = 0; i < 10; i++){
//        QPushButton* button = new QPushButton(ch);
//        button->resize(50,50);
//        button->move(i*50, 0);
//        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
//        if(i != 0 && i!= 9){
//            button->setText(QChar(96+i));
//        }
//    }
//    QWidget* num1 = new QWidget(this);
//    num1->move(600,50);
//    num1->resize(50, 8 * 50);
//    for(int i = 0; i < 8; i++){
//        QPushButton* button = new QPushButton(num1);
//        button->resize(50,50);
//        button->move(0, i*50);
//        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
//        button->setText(QString::number(i + 1));
//    }
//    QWidget* ch1 = new QWidget(this);
//    ch1->move(150,450);
//    ch1->resize(10*50, 50);
//    for(int i = 0; i < 10; i++){
//        QPushButton* button = new QPushButton(ch1);
//        button->resize(50,50);
//        button->move(i*50, 0);
//        button->setStyleSheet("border: 0; background-color: rgb(200,200,200);");
//        if(i != 0 && i!= 9){
//            button->setText(QChar(96+i));
//        }
//    }
//    QWidget* chack = new QWidget(this);
//    chack->move(50,50);
//    chack->resize(2*50, 8*50);
//    for(int i = 0; i < 2; i++){
//        for(int j = 0; j < 8; j++){
//            QPushButton* button = new QPushButton(chack);
//            chackButton.push_back(button);
//            button->resize(50,50);
//            button->move(i*50, j*50);
//            button->setStyleSheet("background-color: rgb(255,255,255);");
//        }
//    }
//    QWidget* chack1 = new QWidget(this);
//    chack1->move(650,50);
//    chack1->resize(2*50, 8*50);
//    for(int i = 0; i < 2; i++){
//        for(int j = 0; j < 8; j++){
//            QPushButton* button = new QPushButton(chack1);
//            chack1Button.push_back(button);
//            button->resize(50,50);
//            button->move(i*50, j*50);
//            button->setStyleSheet("background-color: rgb(255,255,255);");
//        }
//    }
//    for(int i = 0; i < rows; i++) {
//        for(int j = 0; j < columns; j++){
//            QPushButton* button = new QPushButton(w);
//            pButton.push_back(button);
//            button->resize(50,50);
//            button->move(i*50, j*50);
//            button->setProperty("piece", 0);
//            if((i + j) % 2 != 0){
//                button->setStyleSheet("border: 0; background-color: rgb(0,0,0);");
//            }else{
//                button->setStyleSheet("border: 0; background-color: rgb(255,255,255);");
//            }
//            if(figur[j][i]->getP().name == PieceName::Pawn && figur[j][i]->getP().color == Color::White){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Pawn1.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "pawn");
//            }
//            if(figur[j][i]->getP().name == PieceName::Pawn && figur[j][i]->getP().color == Color::Black){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Pawn.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "pawn");
//            }
//            if(figur[j][i]->getP().name == PieceName::Knight && figur[j][i]->getP().color == Color::White){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Knight1.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "knight");
//            }
//            if(figur[j][i]->getP().name == PieceName::Knight && figur[j][i]->getP().color == Color::Black){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Knight.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "knight");
//            }
//            if(figur[j][i]->getP().name == PieceName::Bishop && figur[j][i]->getP().color == Color::White){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Bishop1.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "bishop");
//            }
//            if(figur[j][i]->getP().name == PieceName::Bishop && figur[j][i]->getP().color == Color::Black){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Bishop.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "bishop");
//            }
//            if(figur[j][i]->getP().name == PieceName::Rook && figur[j][i]->getP().color == Color::White){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Rook1.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "rook");
//            }
//            if(figur[j][i]->getP().name == PieceName::Rook && figur[j][i]->getP().color == Color::Black){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Rook.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "rook");
//            }
//            if(figur[j][i]->getP().name == PieceName::Queen && figur[j][i]->getP().color == Color::White){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Queen1.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "queen");
//            }
//            if(figur[j][i]->getP().name == PieceName::Queen && figur[j][i]->getP().color == Color::Black){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Queen.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "queen");
//            }
//            if(figur[j][i]->getP().name == PieceName::King && figur[j][i]->getP().color == Color::White){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/King1.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "king");
//            }
//            if(figur[j][i]->getP().name == PieceName::King && figur[j][i]->getP().color == Color::Black){
//                QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/King.png");
//                QIcon icon(imagedisplay);
//                button->setIcon(icon);
//                button->setIconSize(button->size());
//                button->setProperty("piece", "king");
//            }
//            QObject::connect(button, SIGNAL(clicked()),this, SLOT(ClickedSlot()));
//        }
//    }

//    w->show();
//    ch->show();
//    ch1->show();
//    num->show();
//    num1->show();
//    chack->show();
//    chack1->show();
//}
//void MainWindow::ClickedSlot()
//{
    //std::cout << "kkk";
//    QPushButton* button = (QPushButton*)sender();
//    Board b;
//    std::vector<Coordinates> move = b.get();
//    int i = 0;
//    int j = 0;
//    for(auto k = pButton.begin(); k != pButton.end(); k++){
//        if(i == 8){
//            i = 0;
//            j++;
//        }
//        if((j + i) % 2 != 0){
//            (*k)->setStyleSheet("border: 0; background-color: rgb(0,0,0);");
//        }else{
//            (*k)->setStyleSheet("border: 0; background-color: rgb(255,255,255);");
//        }
//        i++;
//    }

//    buttonCoord = { button->pos().y() / 50,button->pos().x() / 50 };
//    if(button->property("piece") != 0){
//        button->setStyleSheet("border: 0; background-color: rgb(255,0,0);");
//    }
//}
//void MainWindow::ChackFigur(Figur& figur){
//    QPixmap imagedisplay("/home/aramhakobyan/Desktop/Qt/untitled1/image/Pawn1.png");
//    QIcon icon(imagedisplay);
//    chackButton[0]->setIcon(icon);
//    chackButton[0]->setIconSize(chackButton[0]->size());
//}
MainWindow::~MainWindow()
{
    delete ui;
}



