#include "mserver.h"

mServer::mServer(QString adr,qint16 port,QObject* parent):QObject(parent)
{

    mTcpServer=new QTcpServer(this);
  connect(mTcpServer, &QTcpServer::newConnection, this, &mServer::slotNewConnection);
    QHostAddress h(adr);
     qDebug() << "server listen = " << mTcpServer->listen(h, port);

}

mServer::~mServer()
{
    delete mTcpServer;
    delete mTcpSocket;
}

void mServer::slotNewConnection()
{
    ba.clear();
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead, this,  &mServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this,  &mServer::slotClientDisconnected);
}

void mServer::slotServerRead()
{
    QTcpSocket* m_ptcpSocket = (QTcpSocket*)sender();

QByteArray buffer;
while (m_ptcpSocket->bytesAvailable() > 0)
   {
        buffer =  m_ptcpSocket->readAll();
       ba.append(buffer);
   }
            pic.loadFromData(ba,"PNG");
            emit sendPix(pic);

}

void mServer::slotClientDisconnected()
{
 mTcpSocket->close();
}






