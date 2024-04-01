
#include<QDebug>
#include "main_scene.h"
#include "qapplication.h"
#include "qgraphicssceneevent.h"
#include<QRectF>
#include<QDrag>
#include<QMimeData>


main_Scene::main_Scene()
{
    _init_Keyboard();
    // _init_Monitor();

   // Line_Monitor->move(200,100);

    //addWidget(&Line_Monitor);

    mDropMonitor = new DropMonitor();

    addWidget(mDropMonitor);

}



void main_Scene::_init_Keyboard()
{
    mKeyboard.setPos(200,200);
    mKeyboard.BoundingRectOnSceneCalc();
    addItem(&mKeyboard);
    qDebug()<<"keyboard";


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
      const QPointF Drag_pos = event->scenePos();
     }

}

void main_Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    const QPointF Drag_pos = event->scenePos();

    bool keybordHover =  _is_moving_keyboard_(event->scenePos());

     if(keybordHover)
     {
      if( event->buttons() & Qt::LeftButton)
       {
        int distance = (event->scenePos()- Drag_pos).manhattanLength();
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
