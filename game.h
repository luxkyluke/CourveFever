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
    QTimer* gameTimer, *bonusTimer;
    clock_t preparationTimer;       //Timer for the time before the game start
    Terrain *terrain;
    int nbLivingPlayers;
    GameWindow* window;             //the game window

    /**
     * @brief updateScene : call every frame to make the
     * necessary checks and changes
     */
    void updateScene();

    /**
     * @brief getPlayer : return the player associed with the color c
     * @param c
     * @return
     */
    Player& getPlayer(QColor c);

    /**
     * @brief getBonus : return the bonus touch by the player p
     * @param c : bonus color
     * @param p
     * @return
     */
    Bonus* getBonus(QColor c, Player *p);

    /**
     * @brief checkCollision : Check all the colisions during the game
     * So as you may notice the player can be kill himself when he's alone
     * but not with other player
     * And the
     */
    void checkCollision();
    void killPlayer(Player* p);
    void initPlayers();
    void changePositionPlayer(Player *p);
    bool colorAlreadyExist(QColor c);
    bool isInTouch(Bonus* b, Player *p);
    bool isNextToSth(Player *p);
    bool isPreparationTime();
    int getRemainingPrepTime();
    void end();
    int getIdwinner();

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
    ~Game();

private slots:
    void on_clickQuitButton();
    void on_clickRestartButton();
    void createRandomBonus();
    void refresh();


};

#endif // GAME_H
