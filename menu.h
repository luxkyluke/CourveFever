#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class MenuWindow;
}
class MenuWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent=0);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;

public slots:
    void checkTextEditWidth();

};


#endif // MENU_H
