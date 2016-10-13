#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    QPushButton *btnBite = new QPushButton("LA BITE", this);
    QObject::connect(btnBite,SIGNAL(clicked(bool)), this, SLOT(changeColor()));
    this->setFixedSize(1000, 800);
}
MainWindow::~MainWindow()
{
    delete ui;
}
