
//#include<QTcpSocket>
//#include<QBuffer>
//Client::Client(int desc, myServer *serv,MainWindow* mWin, QObject *parent)
//{
// _serv = serv;
// _blockSize = 0;
// _sok = new QTcpSocket(this);
// _sok->setSocketDescriptor(desc);
// connect(_sok, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
// connect(this,SIGNAL(sendPic()),mWin,SLOT(loadPic()));
//}

//Client::~Client()
//{
//    delete  _sok;
//    delete _serv;
//    delete  m_Win;
//}

//void Client::onReadyRead()
//{
//    QPixmap myPixmap;
//    QByteArray block;
//    QBuffer buffer(&block);
//    QDataStream in(_sok);
//      if (_sok->bytesAvailable() )
//            return;
//        in >> block;

//     buffer.open(QIODevice::WriteOnly);
//     myPixmap.loadFromData(block);
//     emit sendPic(myPixmap);

//}
