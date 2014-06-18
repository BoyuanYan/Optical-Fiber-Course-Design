#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include "butterfly.h"
#include <QGraphicsScene>

#include <QMessageBox>//ch2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->closeMyComBtn->setEnabled(false);
    ui->sendMsgBtn->setEnabled(false);
    /**********以下是交换逻辑显示部分**********/
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-330,-120,700,250));

    butterfly = new Butterfly;
    butterfly->setPos(0,0);

    scene->addItem(butterfly);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(700,250);
    ui->graphicsView->show();
    /**********以上是交换逻辑显示部分**********/


    ui->Reset_Btn->setEnabled(false);//默认设置下不能复位，即“重置”不可用
    //ui->Output1->currentIndex();//获取Output1当前的index值，从0到3对应选项的1-4。

    Sleep(2000);//休眠2s，用于显示程序启动画面
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Confirm_Btn_clicked()//ch1
{
    int a,b,c,d,out;

    a = ui->Output1->currentIndex();
    b = ui->Output2->currentIndex();
    c = ui->Output3->currentIndex();
    d = ui->Output4->currentIndex();
    out = (a+1)*1000 + (b+1)*100 + (c+1)*10 +(d+1);
    butterfly->up = out;

    if(out == 1234)
    {
        ui->Reset_Btn->setEnabled(false);
    }
    else
    {
        ui->Reset_Btn->setEnabled(true);
    }

    switch(out)
    {
    case 1234:
        //myCom->write("abcdef");
        myCom->write("a");
        break;
    case 1243:
        //myCom->write("aBcdef");
        myCom->write("b");
        break;
    case 1324:
        //myCom->write("aBcDeF");
        myCom->write("c");
        break;
    case 1342:
        //myCom->write("aBcDef");
        myCom->write("d");
        break;
    case 1423:
        //myCom->write("abcDeF");
        myCom->write("e");
        break;
    case 1432:
        //myCom->write("abcDef");
        myCom->write("f");
        break;
    case 2134:
        //myCom->write("abcdEf");
        myCom->write("g");
        break;
    case 2143:
        //myCom->write("abcdEF");
        myCom->write("h");
        break;
    case 2314:
        //myCom->write("abCdEf");
        myCom->write("i");
        break;
    case 2341:
        //myCom->write("abCdEF");
        myCom->write("j");
        break;
    case 2413:
        //myCom->write("aBCdEf");
        myCom->write("k");
        break;
    case 2431:
        //myCom->write("aBCdEF");
        myCom->write("l");
        break;
    case 3124:
        //myCom->write("aBcDEF");
        myCom->write("m");
        break;
    case 3142:
        //myCom->write("aBcDEf");
        myCom->write("n");
        break;
    case 3214:
        //myCom->write("ABcDEF");
        myCom->write("o");
        break;
    case 3241:
        //myCom->write("ABcDEf");
        myCom->write("p");
        break;
    case 3412:
        //myCom->write("ABCDEF");
        myCom->write("q");
        break;
    case 3421:
        //myCom->write("ABCDEf");
        myCom->write("r");
        break;
    case 4123:
        //myCom->write("ABCdef");
        myCom->write("s");
        break;
    case 4132:
        //myCom->write("ABCdeF");
        myCom->write("t");
        break;
    case 4213:
        //myCom->write("aBCdef");
        myCom->write("u");
        break;
    case 4231:
        //myCom->write("aBCdeF");
        myCom->write("v");
        break;
    case 4312:
        //myCom->write("aBCDef");
        myCom->write("w");
        break;
    case 4321:
        //myCom->write("aBCDeF");
        myCom->write("x");
        break;
    default:
        //此处应弹出错误框
        break;

    }

}

void MainWindow::on_Reset_Btn_clicked()
{
    ui->Output1->setCurrentIndex(0);
    ui->Output2->setCurrentIndex(1);
    ui->Output3->setCurrentIndex(2);
    ui->Output4->setCurrentIndex(3);
    ui->Reset_Btn->setEnabled(false);

    butterfly->up = 1234;

    //发送控制消息
    myCom->write("a");
}

void MainWindow::on_actionReference_triggered()
{
    QMessageBox *ref = new QMessageBox;
    ref->information(NULL,tr("隔离度参考"),tr("          高电平交叉（dB)                  低电平平行（dB）\n\
A1-A3           -7.3                A1-A2           -7.35\n\n\
A4-A2           -7.46               A4-A3           -7.35\n\n\
B1-B3           -7.85               B1-B2           -8.37\n\n\
B4-B2           -8.78               B4-B3           -7.67\n\n\
C1-C3           -7.65               C1-C2           -7.95\n\n\
C4-C2           -7.48               C4-C3           -8.32\n\n\
D1-D3           -7.89               D1-D2           -8.93\n\n\
D4-D2           -7.78               D4-D3           -9.03\n\n\
E1-E3           -7.99               E1-E2           -7.27\n\n\
E4-E2           -7.89               E4-E3           -7.37\n\n\
F1-F3           -8.02               F1-F2           -8.00\n\n\
F4-F2           -8.00               F4-F3           -7.92\n\n                                 "));
}

void MainWindow::on_actionAbout_Version_triggered()
{
    QMessageBox *ver = new QMessageBox;
    ver->information(NULL,tr("Version"),tr("Version 1.0\n\n请注意：作者不再维护该应用！\n"));
}

void MainWindow::on_actionContact_triggered()
{
    QMessageBox *con = new QMessageBox;
    con->information(NULL,tr("联系我们"),tr("作者：闫伯元\n\ngithub：https://github.com/BoyuanYan/Optical-Fiber-Course-Design\n\n联系方式：yanliuzhangyan@163.com\n"));
}


































void MainWindow::readMyCom()
{
    QByteArray temp = myCom->readAll();

    ui->textBrowser->insertPlainText(temp);
}

void MainWindow::on_openMyComBtn_clicked()
{
    struct PortSettings myComSetting = {BAUD19200, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 500};

    myCom = new Win_QextSerialPort("com3", myComSetting, QextSerialBase::EventDriven);//com3
//    struct PortSettings myComSetting = {BAUD9600, DATA_7, PAR_NONE, STOP_1, FLOW_OFF, 500};

//    myCom = new Win_QextSerialPort("com6", myComSetting, QextSerialBase::EventDriven);

    myCom->open(QIODevice::ReadWrite);

    connect(myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));

    ui->openMyComBtn->setEnabled(false);
    ui->closeMyComBtn->setEnabled(true);
    ui->sendMsgBtn->setEnabled(true);
}

void MainWindow::on_closeMyComBtn_clicked()
{
    myCom->close();
    ui->openMyComBtn->setEnabled(true);
    ui->closeMyComBtn->setEnabled(false);
    ui->sendMsgBtn->setEnabled(false);
}

void MainWindow::on_sendMsgBtn_clicked()
{
    myCom->write(ui->sendMsgLineEdit->text().toLatin1());
}



