#ifndef MAINFORM_H
#define MAINFORM_H
#include <qevent.h>
#include <qvariant.h>
#include <qwidget.h>
#include <qmessagebox.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;

class mainForm : public QWidget
{
    Q_OBJECT

public:
    mainForm(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0 );
    ~mainForm();

    QLabel* myPixmapLabel;

signals:
    void clicked();

public slots:
    virtual void mousePressEventSlot();

protected:
    void mousePressEvent(QMouseEvent *);

protected slots:
    virtual void languageChange();
};

#endif // MAINFORM_H

