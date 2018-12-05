#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, int w = 300, int h = 300);
    ~MainWindow();

    static QLabel *getLabel();
    void slotOK(QString filename);

public:
    Ui::MainWindow *ui;
    int width;//屏幕宽
    int height;//屏幕高

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
