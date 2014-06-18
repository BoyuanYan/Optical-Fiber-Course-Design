#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = 0);
    void timerEvent(QTimerEvent *);
    QRectF boundingRect() const;  
    int up;//up为入口1234对应的出口，有共24个取值，默认六个接点都平行传输的情况是1234。
    
signals:
    
public slots:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    QPixmap pix_up;            //用于表示两幅蝴蝶的图片
    //QPixmap pix_down;

    qreal angle;
};

#endif // BUTTERFLY_H
