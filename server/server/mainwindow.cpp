#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"mserver.h"
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pBStart,SIGNAL(clicked()),this,SLOT(startServ()));
    connect(ui->pBSave,SIGNAL(clicked()),this,SLOT(saveJPEG()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ms;

}

void MainWindow::loadPic(QPixmap myPixmap)
{
    m_myPixmap=myPixmap;
    ui->lPixmap->setPixmap(myPixmap);
}

void MainWindow::saveJPEG()
{
    QString filename=QFileDialog::getSaveFileName(0,tr("Сохранить Foto"), "",
                                             tr("Foto Files (*.jpeg )"));
    if(!filename.isEmpty() && !m_myPixmap.isNull()){
        m_myPixmap.save(filename,"JPEG");
    }
}

void MainWindow::startServ()
{
    QString str=ui->lipServer->text();
    qint16 i=ui->lPort->text().toShort();
   ms = new mServer(str,i,this);
 connect(ms,&mServer::sendPix,this,&MainWindow::loadPic);
}
