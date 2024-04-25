#include<QPainter>
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<QRectF>


#include "fild.h"

fild::fild(int aLines,int aColumns,int aCellSize):
    Lines(aLines),
    Columns(aColumns),
    Cell_size(aCellSize),
    Field_width(aColumns*aCellSize),
    Field_height(aLines*aCellSize)
{
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::MouseButton::LeftButton);

    setFlags( QGraphicsItem::ItemIsFocusable);


}



QRectF fild::boundingRect() const
{
    return QRectF(0,0,Field_width,Field_height);

}

void fild::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int l = 0; l <= Lines;++l)
    {
       painter->drawLine(QLineF(0, l*Cell_size, Field_width, l*Cell_size));
    }

    for(int c = 0 ; c <= Columns;++c)
    {
        painter->drawLine(QLineF(c*Cell_size, 0, c*Cell_size, Field_height));
    }

    _draw_Cells_( painter);

    if(mHover)
    {
        int x = mMousePos.x()/Cell_size;
        int y = mMousePos.y()/Cell_size;

        painter->setPen(QColor(255,0,0));
        painter->drawRoundedRect(x*Cell_size,
                               y*Cell_size,
                               Cell_size,
                               Cell_size,2,2);


    }

}

void fild::enableHoverPos(QPointF aPos)
{
    mHover = true;
    mMousePos = mapFromScene(aPos);
    QGraphicsItem::update();

}

void fild::disableHover()
{
    mHover = false;
    QGraphicsItem::update();
}

QVariant fild::take_keyboard(const QPointF & aPos)
{
    QPointF pos = mapFromScene(aPos);
     int c = pos.x()/Cell_size;
     int l = pos.y()/Cell_size;
     QVariant res = Vec_Fields[l*Columns+c];
     return res;

}

/*bool fild::fildIsEmpty(const QPointF &)
{

}
*/



void fild::BoundingRectOnSceneCalc()
{
    QPointF pos = scenePos();
    QRectF rect = boundingRect();

    QPointF TopLeft{pos.x()+rect.x(),pos.y()+rect.y()};
    QPointF bottonRiegt{TopLeft.x()+rect.width(),TopLeft.y()+rect.height()};

    mBoundingSceneRect.setBottomLeft(TopLeft);
    mBoundingSceneRect.setBottomRight(bottonRiegt);

}

qreal fild::xtl()
{
    return mBoundingSceneRect.topLeft().x();
}

qreal fild::ytl()
{
    return mBoundingSceneRect.topLeft().y();
}

qreal fild::xbr()
{
  return mBoundingSceneRect.bottomRight().x();
}

qreal fild::ybr()
{
  return mBoundingSceneRect.bottomRight().y();
}

void fild::_draw_Cells_(QPainter * painter)
{
    if(Vec_Fields.size() == 0)
        return;
    for(int l = 0;l < Lines; ++l)
    {
       for(int c = 0; c < Columns; ++c)
       {
           painter->drawText(c*Cell_size+15,l*Cell_size+20,Vec_Fields[l*Columns+c].toString());
       }
    }


}





void fild::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mHover = false;
    QGraphicsItem::update();

}

void fild::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    mMousePos = event->pos();
    mHover = true;
    QGraphicsItem::update();

}

/*void fild::keyPressEvent(QKeyEvent *event)// что бы при нажатии клавиш подсвечивались квадатики а сцене
{
    if (event->key()== Qt::Key_0 || Qt::Key_9 && Qt::Key_Plus && Qt::Key_Minus
                                         && Qt::Key_division && Qt::Key_multiply)
    {
        mHover = true;
        QGraphicsItem::update();
    }


}*/

