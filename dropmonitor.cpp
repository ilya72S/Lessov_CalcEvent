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

void DropMonitor::set_Itog()
{
    clear();
    setText(ss);
    QLineEdit::update();

}

void DropMonitor::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();

}

void DropMonitor::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    ss.append(mimeData->text());
    setText(ss);

}
