#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QEvent>
#include <QVector>
#include <stdlib.h>

namespace Ui {
class MenuWindow;
}

struct player{
    int id;
    int rightKey;
    int leftKey;
    std::string pseudo;
};

class MenuWindow : public QMainWindow{
    Q_OBJECT
    QVector<player*>  players;

    void addPlayer();
    void initWindow();

public:
    explicit MenuWindow(QWidget *parent=0);

    bool eventFilter(QObject *object, QEvent *event);

    ~MenuWindow();

private:
    Ui::MenuWindow *ui;

public slots:
    void checkTextEditWidth();

private slots:
    void on_checkBox_clicked(bool checked);
    void on_WidgetPlayer_0_objectNameChanged(const QString &objectName);
};


#endif // MENU_H
