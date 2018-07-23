#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mserver.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QPixmap m_myPixmap;
    mServer* ms;

public slots:
    void startServ();
     void loadPic( QPixmap myPixmap);
     void saveJPEG();
};

#endif // MAINWINDOW_H
