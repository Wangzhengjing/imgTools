#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QMovie>
#include <QEvent>
#include <iostream>
#include <QPixmap>
#include <QCursor>
#include <qvariant.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>
#include <QtOpenGL/qgl.h>
#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include "mainwindow.h"
#include <QApplication>
#include "mouseevent.h"
#include <QMovie>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent, int w, int h) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    width = w;
    height = h;

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOK(QString filename)
{
    //QString filename = "C:\\osg\\osgmake\\osgearth_bin\\data\\2.JPG";
    QImage image(filename);
    QPixmap pixmap = QPixmap::fromImage(image);

    EventLabel *label = new EventLabel(ui->label, pixmap.height(), pixmap.width());
    label->setWindowTitle("MouseEventDemo");

    label->setMouseTracking(true); //用于直接开启鼠标坐标的追踪  默认情况下是关闭的

    label->setGeometry( QRect( 100, 100, pixmap.width(), pixmap.height() ) );

    QMovie *movie =new QMovie(filename);

    label->setMovie(movie);
    label->setAlignment(Qt::AlignLeading);
    movie->start();

    label->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString filename;

    filename = ui->textEdit->toPlainText();
    QFileInfo fileInfo(filename);
    if(fileInfo.isFile())
    {
        slotOK(filename);
    }
    else
    {
        QString msg;
        msg.sprintf("Not a fileeeeeeeeeeeeeeeee.");

        if (ui->label)
            ui->label->setText(msg);
    }
}
