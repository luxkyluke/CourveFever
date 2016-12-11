#include "menu.h"
#include "ui_menuwindow.h"

#include <QString>
#include <iostream>
#include <QKeyEvent>
#include <QDebug>

static int ID_INCREMENTATOR=0;

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow){
    ui->setupUi(this);

    addPlayer();

    initWindow();




}

void MenuWindow::initWindow(){
    ui->WidgetPlayer_1->setVisible(false);

//    ui->pseudoTextEdit->setText("Player1");
//    QObject::connect(ui->pseudoTextEdit, SIGNAL(textChanged()),
//                     this, SLOT(checkTextEditWidth()));
//    ui->pseudoTextEdit->installEventFilter(this);
//    foreach(player* p, players){

//    }
}

void MenuWindow::addPlayer(){
    player p ;
    p.id = ID_INCREMENTATOR++;
    p.leftKey = Qt::Key_Left;
    p.rightKey = Qt::Key_Right;
    p.pseudo = std::string("Player_") + std::to_string(ID_INCREMENTATOR);
    players.append(&p);
}

bool MenuWindow::eventFilter(QObject *object, QEvent *event) {
    if (object == ui->pseudoTextEdit_8 && event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        if (keyEvent->key() == Qt::Key_A)	{
            qDebug("Enter Key Pressed...");
            qDebug()<<keyEvent->key();
            return true;
        }
    }
    return QWidget::eventFilter(object,event);
}


MenuWindow::~MenuWindow(){
    delete ui;
}

void MenuWindow::checkTextEditWidth(){
    QString text = ui->pseudoTextEdit_2->toPlainText();
    if(text.length() > 15){
        ui->pseudoTextEdit_2->setText(text.left(15));
    }
}

void MenuWindow::on_checkBox_clicked(bool checked){
    ui->WidgetPlayer_1->setVisible(true);
}


void MenuWindow::on_WidgetPlayer_0_objectNameChanged(const QString &objectName)
{

}
