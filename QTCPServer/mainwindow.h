#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PAUSE -1

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

struct  Coordinates
{
    int x;
    int y;
};

class MainWindow : public QObject
{
    Q_OBJECT

public:
    explicit MainWindow(QObject *parent = nullptr);
    ~MainWindow();
private slots:
    void newConnection();
    void readSocket();
    void DeleteDisconnect();
private:
    int color = 1;
    int temp = 0;
    Coordinates coord;
    QTcpSocket* socket;
    QTcpSocket* previousSocket;
    QTcpServer* m_server;
    std::unordered_map<QTcpSocket*, QTcpSocket*> players;
};

#endif // MAINWINDOW_H
