#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public Q_SLOTS:
    void changeColor(){
        QWidget m_pMyWidget = new QWidget(this);
        m_pMyWidget->setGeometry(0,0,300,100);
        QPalette pal(palette());
        this->setPalette(pal.setColor(QPalette::Background, QColor("#456897")));
    }
};

#endif // MAINWINDOW_H
