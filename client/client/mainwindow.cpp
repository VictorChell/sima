#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QFileInfo>
#include<QTcpSocket>
#include<QBuffer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bLoadPng,SIGNAL(clicked()),this,SLOT(loadPng_click()));
    connect(ui->bResizePng,SIGNAL(clicked()),this,SLOT(resisePng()));
    connect(ui->bPostPng,SIGNAL(clicked()),this,SLOT(sendTcpPng()));
   // connect(this->myPixmap,SIGNAL(readyRead()),this,SLOT(onReadyRead)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPng_click()
{
    this->filename=QFileDialog::getOpenFileName(this,tr("Open Foto"), "",
                                             tr("Foto Files (*.png )"));
    QFileInfo f(this->filename);

    if (!this->filename.isEmpty()) {
      this->myPixmap.load(this->filename);
      ui->spH->setValue(this->myPixmap.size().height()) ;
      ui->spW->setValue(this->myPixmap.size().width());
      ui->lpng->setPixmap(this->myPixmap);
    }

}

void MainWindow::resisePng()
{
     this->myPixmap.load(this->filename);
     QSize PicSize( ui->spW->value(),ui->spH->value());
     this->myPixmap= this->myPixmap.scaled(PicSize,Qt::IgnoreAspectRatio);
     ui->lpng->setPixmap(this->myPixmap);

}

void MainWindow::connectTcp()
{
    tcpSocket=new QTcpSocket(this);
     QString strHost=ui->eIPServer->text();
     QString nPort=ui->ePort->text();
    tcpSocket->connectToHost(strHost,nPort.toInt());
}

void MainWindow::sendTcpPng()
{
    connectTcp();
    QByteArray block;
    QByteArray bArray;
    QBuffer buffer(&bArray);
    buffer.open(QIODevice::WriteOnly);
    myPixmap.save(&buffer, "PNG");
    tcpSocket->write(bArray);


}

void MainWindow::onReadyRead()
{
    QDataStream in(this->tcpSocket);



}
