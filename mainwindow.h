#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include"main_scene.h"



class MainWindow :  public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow();

private:
    main_Scene mScene;

};
#endif // MAINWINDOW_H
