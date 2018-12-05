#include "mainwindow.h"
#include <QApplication>
#include "mouseevent.h"
#include <QMovie>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w(0, a.desktop()->width(), a.desktop()->height());
    w.show();

    return a.exec();
}
