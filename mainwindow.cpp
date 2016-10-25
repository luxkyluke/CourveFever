#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderer.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    this->resize(800, 800);

    QWidget* w = new Renderer(this);

    this->setCentralWidget(w);
}

MainWindow::~MainWindow(){

}
