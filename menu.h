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

/**
 * @brief The MenuWindow class : Menu window to know how many players
 * wants to play and which pseudo and keys they want to have
 */
class MenuWindow : public QMainWindow{
private:
    Q_OBJECT
    Game* game;
    void initWindow();

public:
    explicit MenuWindow( QWidget *parent=0);

    /**
     * @brief eventFilter : to check what is pressed by user
     * @param object
     * @param event
     * @return
     */
    bool eventFilter(QObject *object, QEvent *event);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_checkBoxPlayer1_clicked(bool checked);
    void on_checkBoxPlayer2_clicked(bool checked);
    void on_checkBoxPlayer3_clicked(bool checked);
    void on_checkBoxPlayer4_clicked(bool checked);
    void on_checkBoxPlayer5_clicked(bool checked);
    void on_StartButton_clicked();
};


#endif // MENU_H
