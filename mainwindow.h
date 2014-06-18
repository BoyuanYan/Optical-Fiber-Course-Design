#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "butterfly.h"
#include "win_qextserialport.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Win_QextSerialPort *myCom;
    Butterfly *butterfly;//ch1
    ~MainWindow();

private slots:
    void on_Confirm_Btn_clicked();

    void on_Reset_Btn_clicked();

    void on_actionReference_triggered();

    void readMyCom();
    void on_openMyComBtn_clicked();
    void on_closeMyComBtn_clicked();
    void on_sendMsgBtn_clicked();

    void on_actionAbout_Version_triggered();

    void on_actionContact_triggered();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
