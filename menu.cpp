#include <QString>
#include <iostream>
#include <QKeyEvent>
#include <QDebug>
#include <ctime>

#include "menu.h"
#include "ui_menuwindow.h"



static int ID_INCREMENTATOR=0;

static const QString PSEUDO_TEXT = "pseudoTextEdit";
static const QString LKEY_TEXT = "LKeyTextEdit";
static const QString RKEY_TEXT = "RKeyTextEdit";

static const int PSEUDO_NB_MAX_CHAR = 25;
static const int KEY_NB_MAX_CHAR = 1;

MenuWindow::MenuWindow( QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow){
    ui->setupUi(this);

    //game =g;
    //addPlayer();

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

    ui->pseudoTextEdit_1->installEventFilter(this);
    ui->pseudoTextEdit_2->installEventFilter(this);
    ui->pseudoTextEdit_3->installEventFilter(this);
    ui->pseudoTextEdit_4->installEventFilter(this);
    ui->pseudoTextEdit_5->installEventFilter(this);
    ui->pseudoTextEdit_6->installEventFilter(this);

    ui->LKeyTextEdit_1->installEventFilter(this);
    ui->LKeyTextEdit_2->installEventFilter(this);
    ui->LKeyTextEdit_3->installEventFilter(this);
    ui->LKeyTextEdit_4->installEventFilter(this);
    ui->LKeyTextEdit_5->installEventFilter(this);
    ui->LKeyTextEdit_6->installEventFilter(this);

    ui->RKeyTextEdit_1->installEventFilter(this);
    ui->RKeyTextEdit_2->installEventFilter(this);
    ui->RKeyTextEdit_3->installEventFilter(this);
    ui->RKeyTextEdit_4->installEventFilter(this);
    ui->RKeyTextEdit_5->installEventFilter(this);
    ui->RKeyTextEdit_6->installEventFilter(this);

}



bool MenuWindow::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        QTextEdit *textEdit = qobject_cast<QTextEdit*> (object);
        if(textEdit != NULL){
            QString name = textEdit->objectName();
            QString type = name.split('_')[0];
            if(type == PSEUDO_TEXT){
                if(textEdit->toPlainText().size() > PSEUDO_NB_MAX_CHAR){
                    if(keyEvent->key() != Qt::Key_Backspace
                            && keyEvent->key() != Qt::Key_Delete)
                        return true;
                }
                if((keyEvent->key()>=Qt::Key_A
                        && keyEvent->key() <= Qt::Key_Z)
                        || (keyEvent->key()>=Qt::Key_0
                                && keyEvent->key() <= Qt::Key_9)
                        || keyEvent->key() == Qt::Key_Backspace
                        || keyEvent->key() == Qt::Key_Delete
                        || keyEvent->key() == Qt::Key_Right
                        || keyEvent->key() == Qt::Key_Left){
                    return QWidget::eventFilter(object,event);
                }
                else{
                    return true;
                }
            }
            else if (type == LKEY_TEXT || type == RKEY_TEXT){
//                QKeySequence key("M");
//                qDebug()<<key[0];
//                qDebug()<< keyEvent->key();
                if(keyEvent->key() == Qt::Key_Right){
                    textEdit->setPlainText("->");
                }else if(keyEvent->key() == Qt::Key_Left){
                    textEdit->setPlainText("<-");
                }
                if(textEdit->toPlainText().size() > KEY_NB_MAX_CHAR){
                    if(keyEvent->key() != Qt::Key_Backspace
                            && keyEvent->key() != Qt::Key_Delete)
                        return true;
                }
            }
        }
    }
    return QWidget::eventFilter(object,event);
}


MenuWindow::~MenuWindow(){
    delete ui;
}

void MenuWindow::closeEvent(QCloseEvent *event){
    delete game;
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

uint getKey(QString s){
    if(s == "->")
        return Qt::Key_Right;
    if(s == "<-")
        return Qt::Key_Left;
    QKeySequence key(s);
    return key[0];
}

/*I know it's very dirty but i don't know qt designer as well
to create generatively QWidget in the window
so i choose an easy but dirty solution
sorry about that*/
void MenuWindow::on_StartButton_clicked(){
    uint RKey, LKey;
    QString pseudo, Rchar, Lchar;
    QVector<Player*> players;

    srand(time(NULL));

    pseudo = ui->pseudoTextEdit_1->toPlainText();
    Rchar = ui->RKeyTextEdit_1->toPlainText();
    Lchar = ui->LKeyTextEdit_1->toPlainText();
    if(pseudo.size()<1 || Rchar.size()<1 || Lchar.size() < 1) return ;
    RKey = getKey(Rchar);
    LKey = getKey(Lchar);

    players.append(new Player(pseudo, RKey, LKey));
    if(!ui->checkBoxPlayer1->isChecked()){
        //this->hide();
        game = new Game(players);
        //this->show();
        return;
    }

    pseudo = ui->pseudoTextEdit_2->toPlainText();
    Rchar = ui->RKeyTextEdit_2->toPlainText();
    Lchar = ui->LKeyTextEdit_2->toPlainText();
    if(pseudo.size()<1 || Rchar.size()<1 || Lchar.size() < 1) return ;
    RKey = getKey(Rchar);
    LKey = getKey(Lchar);
    players.append(new Player(pseudo, RKey, LKey));
    if(!ui->checkBoxPlayer2->isChecked()){
        game = new Game(players);
        return;
    }

    pseudo = ui->pseudoTextEdit_3->toPlainText();
    Rchar = ui->RKeyTextEdit_3->toPlainText();
    Lchar = ui->LKeyTextEdit_3->toPlainText();
    if(pseudo.size()<1 || Rchar.size()<1 || Lchar.size() < 1) return ;
    RKey = getKey(Rchar);
    LKey = getKey(Lchar);
    players.append(new Player(pseudo, RKey, LKey));
    if(!ui->checkBoxPlayer3->isChecked()){
        game = new Game(players);
        return;
    }

    pseudo = ui->pseudoTextEdit_4->toPlainText();
    Rchar = ui->RKeyTextEdit_4->toPlainText();
    Lchar = ui->LKeyTextEdit_4->toPlainText();
    if(pseudo.size()<1 || Rchar.size()<1 || Lchar.size() < 1) return ;
    RKey = getKey(Rchar);
    LKey = getKey(Lchar);
    players.append(new Player(pseudo, RKey, LKey));
    if(!ui->checkBoxPlayer4->isChecked()){
        game = new Game(players);
        return;
    }

    pseudo = ui->pseudoTextEdit_5->toPlainText();
    Rchar = ui->RKeyTextEdit_5->toPlainText();
    Lchar = ui->LKeyTextEdit_5->toPlainText();
    if(pseudo.size()<1 || Rchar.size()<1 || Lchar.size() < 1) return ;
    RKey = getKey(Rchar);
    LKey = getKey(Lchar);
    players.append(new Player(pseudo, RKey, LKey));
    if(!ui->checkBoxPlayer5->isChecked()){
        game = new Game(players);
        return;
    }

    pseudo = ui->pseudoTextEdit_6->toPlainText();
    Rchar = ui->RKeyTextEdit_6->toPlainText();
    Lchar = ui->LKeyTextEdit_6->toPlainText();
    if(pseudo.size()<1 || Rchar.size()<1 || Lchar.size() < 1) return ;
    RKey = getKey(Rchar);
    LKey = getKey(Lchar);
    players.append(new Player(pseudo, RKey, LKey));

    game = new Game(players);
}
