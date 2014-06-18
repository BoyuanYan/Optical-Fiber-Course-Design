#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //显示启动画面
    QPixmap pixmap("C://keshe/startup.png");
    QSplashScreen splash(pixmap);
    splash.show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash.showMessage(QObject::tr("《光纤通信》课程设计第一组作品\n程序加载中...\n\\*^o^*// "),
                        topRight,
                        Qt::black);
    a.processEvents();//使程序在显示启动画面的同时仍然能够响应鼠标等其他事件。


    MainWindow w;
    w.show();

    splash.finish(&w);
    return a.exec();
}
