#include "mouseevent.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

//注意添加这个头文件
#include <QMouseEvent>
#include <iostream>



void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("%d, %d", event->x(), event->y());
    msg.sprintf("    x:%.3f,     y:%.3f;\n" \
                "(1-x):%.3f, (1-y):%.3f", event->x()/_PicW, event->y()/_PicH, 1-event->x()/_PicW, 1-event->y()/_PicH);

    if (_label)
        _label->setText(msg);
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
     QString msg=QString("press:%1,%2").arg(event->pos().x()).arg(event->pos().y());

     if (_label)
         _label->setText(msg);
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("Release: (%d, %d)",event->x(), event->y());
    if (_label)
        _label->setText(msg);
}


/*==========================================================查看按键事件的两种方法============================================*/

bool EventLabel::event(QEvent *e) //重写event函数
{
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if (keyEvent->key() == Qt::Key_Tab)
        {
            qDebug() << "You press tab.";
            return true;
        }
    }
    return QWidget::event(e);
}



void EventLabel::keyPressEvent(QKeyEvent *event) //重写keyPressEvent函数
{
        int key=event->key();
        if( key==Qt::Key_F)
        {
             qDebug() << "You press F.";
        }
}

EventLabel::EventLabel(QLabel *label, double height, double width)
{
    _label = label;
    _PicH = height;
    _PicW = width;
}
