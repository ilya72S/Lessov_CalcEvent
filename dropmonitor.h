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

    // QWidget interface
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // DROPMONITOR_H
