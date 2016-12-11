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
    ui->WidgetPlayer_2->setVisible(false);
    ui->WidgetPlayer_3->setVisible(false);
    ui->WidgetPlayer_4->setVisible(false);
    ui->WidgetPlayer_5->setVisible(false);

    ui->checkBoxPlayer2->setVisible(false);
    ui->checkBoxPlayer3->setVisible(false);
    ui->checkBoxPlayer4->setVisible(false);
    ui->checkBoxPlayer5->setVisible(false);

    ui->pseudoTextEdit_5->installEventFilter(this);
    ui->pseudoTextEdit_2->installEventFilter(this);
    ui->pseudoTextEdit_3->installEventFilter(this);
    ui->pseudoTextEdit_4->installEventFilter(this);
    ui->pseudoTextEdit_7->installEventFilter(this);
    ui->pseudoTextEdit_8->installEventFilter(this);

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
    //qDebug("ge");
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        QTextEdit *champs = qobject_cast<QTextEdit*> (object);
        if(champs != NULL)
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


void MenuWindow::on_checkBoxPlayer1_clicked(bool checked){
    ui->WidgetPlayer_1->setVisible(checked);
    ui->checkBoxPlayer2->setVisible(checked);
    if(ui->checkBoxPlayer2->isChecked())
        ui->checkBoxPlayer2->click();
}

void MenuWindow::on_checkBoxPlayer2_clicked(bool checked){
    ui->WidgetPlayer_2->setVisible(checked);
    ui->checkBoxPlayer3->setVisible(checked);
    if(ui->checkBoxPlayer3->isChecked())
        ui->checkBoxPlayer3->click();
}

void MenuWindow::on_checkBoxPlayer3_clicked(bool checked){
    ui->WidgetPlayer_3->setVisible(checked);
    ui->checkBoxPlayer4->setVisible(checked);
    if(ui->checkBoxPlayer4->isChecked())
        ui->checkBoxPlayer4->click();
}

void MenuWindow::on_checkBoxPlayer4_clicked(bool checked){
    ui->WidgetPlayer_4->setVisible(checked);
    ui->checkBoxPlayer5->setVisible(checked);
    if(ui->checkBoxPlayer5->isChecked())
        ui->checkBoxPlayer5->click();
}

void MenuWindow::on_checkBoxPlayer5_clicked(bool checked){
    ui->WidgetPlayer_5->setVisible(checked);
}
