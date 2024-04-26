
#include<QDebug>
#include "main_scene.h"
#include "qapplication.h"
#include "qgraphicssceneevent.h"
#include<QRectF>
#include<QDrag>
#include<QMimeData>
#include <QVector>
#include<QChar>


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

    Cl_Button = new QPushButton("Clear");
    Cl_Button->move(500,500);
    addWidget(Cl_Button);

    addWidget(mDropMonitor);

    connect(itogButton,&QAbstractButton::clicked, this, &main_Scene::itogSlot);

    connect(Cl_Button,&QPushButton::clicked, this,&main_Scene::clearMonitor);

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
         bool b =(*n) != QChar('+')&&(*n) != QChar ('-')&& (*n) !=QChar('/')&& (*n) !=QChar('*');

         qDebug()<<"bool b ="<< b;


         if((*n) != QChar('+')&&(*n) != QChar ('-')&& (*n) !=QChar('/')&& (*n) !=QChar('*'))
         {


             a.append(*n);
         }

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
        mDropMonitor->set_Itog();

    }

    if(d == '-')
    {
        float f = a.toFloat();
        float f1 = a1.toFloat();
        QVariant res = f-f1;
        (mDropMonitor->ss) = res.toString();
        mDropMonitor->set_Itog();


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
        mDropMonitor->set_Itog();


    }
    if(d == '*')
    {
        float f = a.toFloat();
        float f1 = a1.toFloat();
        QVariant res = f*f1;
        (mDropMonitor->ss) = res.toString();
        mDropMonitor->set_Itog();


    }
}

void main_Scene::clearMonitor()
{
    mDropMonitor->Cl_monitor();

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

void main_Scene::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<event->key();
     if (event->key()== Qt::Key_0 )
        {

        (mDropMonitor->ss).append('0');
         mDropMonitor->set_Key();
        mKeyboard.highlight_Key();

        }

     if (event->key()== Qt::Key_1 )
     {

            (mDropMonitor->ss).append('1');
         mDropMonitor->set_Key();

     }
     if (event->key()== Qt::Key_2 )
     {

         (mDropMonitor->ss).append('2');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_3 )
     {

         (mDropMonitor->ss).append('3');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_4 )
     {

         (mDropMonitor->ss).append('4');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_5 )
     {

         (mDropMonitor->ss).append('5');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_6 )
     {

         (mDropMonitor->ss).append('6');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_7 )
     {

         (mDropMonitor->ss).append('7');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_8 )
     {

         (mDropMonitor->ss).append('8');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_9)
     {

         (mDropMonitor->ss).append('9');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_Minus )
     {

         (mDropMonitor->ss).append('-');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_Plus )
     {

         (mDropMonitor->ss).append( '+');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_division )
     {

         (mDropMonitor->ss).append( '/');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_multiply )
     {

         (mDropMonitor->ss).append('*');
         mDropMonitor->set_Key();
     }
     if (event->key()== Qt::Key_Comma )
     {

         (mDropMonitor->ss).append('.');
         mDropMonitor->set_Key();
     }

}


/*void main_Scene::_init_Monitor()
{

   addWidget(&mMonitror);
}
*/
