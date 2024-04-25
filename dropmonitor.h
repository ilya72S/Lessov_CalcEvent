#ifndef DROPMONITOR_H
#define DROPMONITOR_H
#include "qtmetamacros.h"
#include <QtGui>
#include <QLabel>
#include <QLineEdit>

class DropMonitor: public QLineEdit
{
    Q_OBJECT
public:
    explicit DropMonitor(QWidget *parent = nullptr);
    QString ss;
    void set_Itog();
    void Cl_monitor();
    void set_Key();

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event)override;
    void dropEvent(QDropEvent *event)override;

    // QWidget interface
protected:
   // virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // DROPMONITOR_H
