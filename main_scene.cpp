
#include<QDebug>
#include "main_scene.h"
#include "qapplication.h"
#include "qgraphicssceneevent.h"
#include<QRectF>
#include<QDrag>
#include<QMimeData>
#include <QVector>


main_Scene::main_Scene()
{
    _init_Keyboard();
    // _init_Monitor();

   // Line_Monitor->move(200,100);

    //addWidget(&Line_Monitor);

    mDropMonitor = new DropMonitor();

    itogButton = new QPushButton("=");
    itogButton->move(200,500);
    addWidget(itogButton);

    addWidget(mDropMonitor);

    connect(itogButton,&QAbstractButton::clicked, this, &main_Scene::itogSlot);

}

void main_Scene::itogSlot()
{
    QString a,a1,d;

    QString str = mDropMonitor->ss;
    qDebug()<<"str= "<<str;
     QChar *n = str.data();
     qDebug()<<" n= "<< *n;
     while(!n->isNull())
    {


         if((*n) != QChar('+')||(*n) != QChar ('-')|| (*n) !=QChar('/')|| (*n) !=QChar('*'))

        a.append(*n);

        else
        {
            d.append(*n);
            a1 = a;
             a.clear();
        }

        ++n;
    }

    qDebug()<<"a= "<< a;
    qDebug()<<"a1= "<< a1;
    qDebug()<<"d= "<< d;


    if(d == '+')
    {
        float f = a.toFloat();
        float f1 = a1.toFloat();
        QVariant res = f+f1;
        (mDropMonitor->ss) = res.toString();

    }

    if(d == '-')
    {
        float f = a.toFloat();
        float f1 = a1.toFloat();
        QVariant res = f-f1;
        (mDropMonitor->ss) = res.toString();

    }

    if(d == '/')
    {
        float f = a.toFloat();
        float f1 = a1.toFloat();
        if (f1==0)
        {
            qDebug()<<"На оль делить нельзя";
            return;
        }
        QVariant res = f/f1;
        (mDropMonitor->ss) = res.toString();

    }
    if(d == '*')
    {
        float f = a.toFloat();
        float f1 = a1.toFloat();
        QVariant res = f*f1;
        (mDropMonitor->ss) = res.toString();

    }
}



void main_Scene::_init_Keyboard()
{
    mKeyboard.setPos(200,200);
    mKeyboard.BoundingRectOnSceneCalc();
    addItem(&mKeyboard);
    //qDebug()<<"keyboard";


}

/*void main_Scene::_init_Monitor()
{

}*/

bool main_Scene::_is_moving_keyboard_(const QPointF aPos)
{

    return (aPos.x()>= mKeyboard.xtl())
             && (aPos.x()<= mKeyboard.xbr())
             && (aPos.y()>=mKeyboard.ytl())
             && (aPos.y()<=mKeyboard.ybr());
}

void main_Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
     {
      mDrag_pos = event->scenePos();
     }

}

void main_Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{


    bool keybordHover =  _is_moving_keyboard_(event->scenePos());
    //qDebug()<<"keybordHover= "<<keybordHover;
     if(keybordHover)
     {
      if( event->buttons() & Qt::LeftButton)
       {
        int distance = (event->scenePos()- mDrag_pos).manhattanLength();
        if(distance > QApplication::startDragDistance())
         {
          QMimeData* pMimeData = new QMimeData;
          QString aStr = (mKeyboard.take_keyboard(event->scenePos())).toString();
          pMimeData->setText(aStr);

          QDrag *pDrag = new QDrag(this);
          pDrag->setMimeData(pMimeData);
          pDrag->exec();
         }
       }
     }
    QGraphicsScene::mouseMoveEvent(event);

}


/*void main_Scene::_init_Monitor()
{

   addWidget(&mMonitror);
}
*/
