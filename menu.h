#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QEvent>
#include <QVector>
#include <stdlib.h>
#include "game.h"

namespace Ui {
class MenuWindow;
}


class MenuWindow : public QMainWindow{
    Q_OBJECT

    Game* game;
    void initWindow();


public:
    explicit MenuWindow( QWidget *parent=0);

    bool eventFilter(QObject *object, QEvent *event);

    ~MenuWindow();

private:
    Ui::MenuWindow *ui;
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

public slots:

private slots:
    void on_checkBoxPlayer1_clicked(bool checked);
    void on_checkBoxPlayer2_clicked(bool checked);
    void on_checkBoxPlayer3_clicked(bool checked);
    void on_checkBoxPlayer4_clicked(bool checked);
    void on_checkBoxPlayer5_clicked(bool checked);
    void on_StartButton_clicked();
};


#endif // MENU_H
