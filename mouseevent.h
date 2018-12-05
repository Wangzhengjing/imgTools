#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}



class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public:
    EventLabel(QLabel *label, double height, double width);
    bool event(QEvent *e);
    void keyPressEvent(QKeyEvent *event);

private:
    QLabel *_label;
    double _PicH;//图片高
    double _PicW;//图片宽
};


#endif // MOUSEEVENT_H
