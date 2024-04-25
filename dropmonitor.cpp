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

void DropMonitor::Cl_monitor()
{
    clear();
    ss.clear();
    QLineEdit::update();

}

void DropMonitor::set_Key()
{
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

/*void DropMonitor::keyPressEvent(QKeyEvent *event)
{

    setText(ss);
    QLineEdit::update();



}*/
