#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H
#include<QWidget>
#include<QGraphicsScene>
#include"monitor.h"
#include"keyboard.h"
#include"dropmonitor.h"
#include<QPushButton>


class main_Scene:public QGraphicsScene
{
public:
    main_Scene();

    //QLineEdit *Line_Monitor;

 public slots:

    void itogSlot();
    void clearMonitor();



private:

    //Monitor mMonitror;
    Keyboard mKeyboard;
    DropMonitor *mDropMonitor;
    QPointF mDrag_pos;
    QPushButton *itogButton;
    QPushButton *Cl_Button;


    void _init_Keyboard();
    //void _init_Monitor();

 bool _is_moving_keyboard_(const QPointF);



    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAIN_SCENE_H
