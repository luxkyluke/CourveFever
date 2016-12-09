#include "menu.h"
#include "ui_menuwindow.h"

#include <QString>
#include <iostream>

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow){
    ui->setupUi(this);
    ui->pseudoTextEdit->setText("Player1");
    QObject::connect(ui->pseudoTextEdit, SIGNAL(textChanged()),
                     this, SLOT(checkTextEditWidth()));
}

MenuWindow::~MenuWindow(){
    delete ui;
}

void MenuWindow::checkTextEditWidth(){
    QString text = ui->pseudoTextEdit->toPlainText();
    if(text.length() > 15){
        ui->pseudoTextEdit->setText(text.left(15));
    }

}
