#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QObject *parent) : QObject(parent)
{
    m_server = new QTcpServer();
    if(m_server->listen(QHostAddress::Any, 8080))
    {
       connect(m_server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
    }
}

MainWindow::~MainWindow() {
    for (auto a = players.begin(); a != players.end(); a++) {
        (a->first)->close();
        (a->second)->close();
        (a->first)->deleteLater();
        (a->second)->deleteLater();
        a++;
    }
    m_server->close();
    m_server->deleteLater();
}

void MainWindow::newConnection()
{
    while (m_server->hasPendingConnections()){
        socket = m_server->nextPendingConnection();
        if (color == 0) {
            players[previousSocket] = socket;
            players[socket] = previousSocket;
            QByteArray block;
            QDataStream out2(&block, QIODevice::WriteOnly );
            out2.setVersion(QDataStream::Qt_6_3);
            out2 << color;
            socket->write(block);
            qDebug() << color;
            QDataStream out1(&block, QIODevice::WriteOnly );
            out1.setVersion(QDataStream::Qt_6_3);
            out1 << (color + 1) % 2;
            qDebug() << (color + 1) % 2;
            previousSocket->write(block);
        } else {
            connect(socket, &QTcpSocket::disconnected, this, &MainWindow::DeleteDisconnect);
            players[socket] = nullptr;
            previousSocket = socket;
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly );
            out.setVersion(QDataStream::Qt_6_3);
            out << PAUSE;
            qDebug() << PAUSE;
            socket->write(block);
        }
        color = (color + 1) % 2;
        connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
    }
}

void MainWindow::DeleteDisconnect() {
    if(color == 0) {
        players.erase(previousSocket);
        color = (color + 1) % 2;
        previousSocket = nullptr;
    }
}

void MainWindow::readSocket() {
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_6_3);
    socketStream.startTransaction();
    Coordinates ntemp = {};
    socketStream >> coord.x >> coord.y ;
    if(coord.x == PAUSE){
        if(temp == PAUSE){
            socketStream >> ntemp.x >> ntemp.y;
        } else{
            temp = PAUSE;
            socketStream.abortTransaction();
            return;
        }
    }else if(temp == PAUSE) {
        socketStream.abortTransaction();
        return;
    }
    socketStream.abortTransaction();
    if(players[socket] != nullptr){
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly );
        out.setVersion(QDataStream::Qt_6_3);
        if(coord.x == PAUSE){
            out << coord.x << coord.y << ntemp.x << ntemp.y;
            temp = 0;
        } else {
            out << coord.x << coord.y;
            qDebug() << coord.x << coord.y;
        }
        players[socket]->write(block);
        socket->write(block);
    }
}

