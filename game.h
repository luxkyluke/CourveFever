#ifndef GAME_H
#define GAME_H
#include <QObject>
#include "terrain.h"
#include "player.h"
#include "bonus.h"

#include "gamewindow.h"


class Game : public QObject{
private:
    Q_OBJECT
    QVector<Player*> players;
    QVector<Bonus*> bonus;
    QTimer* timer;
    Terrain terrain;
    int nbLivingPlayers;
    GameWindow* window;

    void updateScene();
    Player& getPlayer(QColor c);
    Bonus* getBonus(QColor c);
    void checkCollision();
    void killPlayer(Player* p);
    void initPlayers();
    void changePositionPlayer(Player *p);
    bool colorAlreadyExist(QColor c);
    bool isNextToSth(Player *p);
    void end();


public:
    Game();
    Game(QVector<Player*>& _players);
    void addPlayer(Player *p);
    bool keyEvent(QKeyEvent* event);
    void draw(QPainter *painter) const;
    int getWidth() const;
    int getHeight() const;
    void addBonus(Bonus* b);
    bool eventFilter(QObject *object, QEvent *event);
    void play();
    Terrain* getTerrain();
    static bool isSafePosition(QPointF pos);

public slots:
    void refresh();

};

#endif // GAME_H
