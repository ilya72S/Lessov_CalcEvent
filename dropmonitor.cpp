#include <QPainter>
#include "dropmonitor.h"
#include<QGraphicsRectItem>

DropMonitor::DropMonitor(QWidget *parent): QLabel(parent)
{
    setMinimumSize(100,30);
    setAcceptDrops(true);
    SetRect();
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
