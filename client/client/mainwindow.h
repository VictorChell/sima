#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void connectTcp();

private:
    Ui::MainWindow *ui;
    QPixmap myPixmap;
    QString filename;
    QTcpSocket* tcpSocket;
public   slots:
    void loadPng_click();
    void resisePng();
    void sendTcpPng();
   void onReadyRead();
};

#endif // MAINWINDOW_H
