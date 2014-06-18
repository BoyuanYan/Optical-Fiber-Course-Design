#include "butterfly.h"
#include <math.h>

const static double PI=3.1416;
//static bool pre = 0;

Butterfly::Butterfly(QObject *parent) :
    QObject(parent)
{
    up = 1234;
    pix_up.load("C://keshe/交换图片/1234 111111.png");
    //pix_down.load("C://keshe/交换图片/1234 111111.png");

    startTimer(50);//刷新频率20Hz
}

QRectF Butterfly::boundingRect() const
{
    qreal adjust =2;
    return QRectF(-pix_up.width()/2-adjust,-pix_up.height()/2-adjust,pix_up.width()+adjust*2,pix_up.height()+adjust*2);
}

void Butterfly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(up)
    {
    case 1234:
        pix_up.load("C://keshe/交换图片/1234 111111.png");
        break;
    case 1243:
        pix_up.load("C://keshe/交换图片/1243 101111.png");
        break;
    case 1324:
        pix_up.load("C://keshe/交换图片/1324 101010.png");
        break;
    case 1342:
        pix_up.load("C://keshe/交换图片/1342 101011.png");
        break;
    case 1423:
        pix_up.load("C://keshe/交换图片/1423 111010.png");
        break;
    case 1432:
        pix_up.load("C://keshe/交换图片/1432 111011.png");
        break;
    case 2134:
        pix_up.load("C://keshe/交换图片/2134 111101.png");
        break;
    case 2143:
        pix_up.load("C://keshe/交换图片/2143 111100.png");
        break;
    case 2314:
        pix_up.load("C://keshe/交换图片/2314 110101.png");
        break;
    case 2341:
        pix_up.load("C://keshe/交换图片/2341 110100.png");
        break;
    case 2413:
        pix_up.load("C://keshe/交换图片/2413 100101.png");
        break;
    case 2431:
        pix_up.load("C://keshe/交换图片/2431 100100.png");
        break;
    case 3124:
        pix_up.load("C://keshe/交换图片/3124 101000.png");
        break;
    case 3142:
        pix_up.load("C://keshe/交换图片/3142 101001.png");
        break;
    case 3214:
        pix_up.load("C://keshe/交换图片/3214 001000.png");
        break;
    case 3241:
        pix_up.load("C://keshe/交换图片/3241 001001.png");
        break;
    case 3412:
        pix_up.load("C://keshe/交换图片/3412 000000.png");
        break;
    case 3421:
        pix_up.load("C://keshe/交换图片/3421 000001.png");
        break;
    case 4123:
        pix_up.load("C://keshe/交换图片/4123 000111.png");
        break;
    case 4132:
        pix_up.load("C://keshe/交换图片/4132 000110.png");
        break;
    case 4213:
        pix_up.load("C://keshe/交换图片/4213 100111.png");
        break;
    case 4231:
        pix_up.load("C://keshe/交换图片/4231 100110.png");
        break;
    case 4312:
        pix_up.load("C://keshe/交换图片/4312 100011.png");
        break;
    case 4321:
        pix_up.load("C://keshe/交换图片/4321 100010.png");
        break;
    default:
        //此处应弹出错误信息框
        break;
    }

    painter->drawPixmap(boundingRect().topLeft(),pix_up);
}

void Butterfly::timerEvent(QTimerEvent *)
{

    update();

}

