#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QGLWidget* w;

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    ~MainWindow();

};

#endif // MAINWINDOW_H
