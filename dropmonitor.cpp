#include <QPainter>
#include "dropmonitor.h"
#include "qlineedit.h"
#include<QGraphicsRectItem>

DropMonitor::DropMonitor(QWidget *parent): QLineEdit(parent)
{
    setMinimumSize(100,30);
    setAcceptDrops(true);
    //QLineEdit *line = new QLineEdit;
    //setBuddy(line);
    show();

}

void DropMonitor::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();

}

void DropMonitor::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    setText(mimeData->text());

}
