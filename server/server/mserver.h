#ifndef MSERVER_H
#define MSERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QPixmap>


class mServer: public QObject
{
    Q_OBJECT
public:
   explicit  mServer(QString,qint16,QObject *parent = nullptr);
    ~mServer() override;
public slots:
    void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    QPixmap pic;
    qint16     m_nNextBlockSize=-1;
    QByteArray ba;

signals:
     void sendPix(QPixmap pix);


 };

#endif // MSERVER_H
