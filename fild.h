#ifndef FILD_H
#define FILD_H
//#include "Com_Calc.h"
#include<QGraphicsItem>

class fild : public QGraphicsItem
{
public:
    fild(int,int,int);


    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void enableHoverPos(QPointF);
    void disableHover();

    //функции для перетаскивания

    //bool fildIsEmpty(const QPointF&);
    QVariant take_keyboard(const QPointF&aPos);

    void BoundingRectOnSceneCalc();

    qreal xtl();
    qreal ytl();
    qreal xbr();
    qreal ybr();

    virtual void _draw_Cells_(QPainter *);

    QVector<QVariant> Vec_Fields;
    //QVector<QVariant> keybVec_Fields;

protected:
    int Lines{0};//количество строк
    int Columns{0};//количество колонок
    int Cell_size{0}; // размер ячейки (квадратной)
    int Field_width{0};
    int Field_height{0};

    bool mHover{false};
    QPointF mMousePos;

   QRectF mBoundingSceneRect;


   // QGraphicsItem interface
protected:

   virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

   virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

   virtual void _init_Cels_()=0;


   // QGraphicsItem interface
   protected:
   //virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // FILD_H
