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
     * necessary changes on element's game
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
     * @brief checkCollision : Check all the collisions during the game
     * So as you may notice the player can be kill himself when he's alone
     * but not with other player
     */
    void checkCollision();

    /**
     * @brief killPlayer : to kill the player ou died and increase the score
     * of the others
     * @param p
     */
    void killPlayer(Player* p);
    /**
     * @brief initPlayers : To re-attribute player's positions and colors
     * to avoid to have players in the initial place with too similare colors
     */
    void initPlayers();

    /**
     * @brief colorAlreadyExist : to know if a color is already taken by someone
     * @param c
     * @return
     */
    bool colorAlreadyExist(QColor c);

    /**
     * @brief isInTouch : To know if the player p is touching the bonus b
     * @param b
     * @param p
     * @return
     */
    bool isInTouch(Bonus* b, Player *p);

    /**
     * @brief isNextToSth : To know, if a player position is next to someone else
     * @param p
     * @return
     */
    bool isNextToSb(Player *p);

    /**
     * @brief end : stop timers when the game is over
     */
    void end();

    /**
     * @brief getIdwinner : return the position of the best player
     * of the game, in a player's vector;
     * @return
     */
    int getIdwinner();

    /**
     * @brief isPreparationTime: mesure is the preparation time is over or not
     * @return
     */
    bool isPreparationTime();

    /**
     * @brief getRemainingPrepTime : return what time it left before beginning
     * @return
     */
    int getRemainingPrepTime();

public:
    Game(QVector<Player*>& _players);
    void addBonus(Bonus* b);
    ~Game();

    /**
     * @brief keyEvent : inform all player that a key event append
     * @param event
     */
    void keyEvent(QKeyEvent* event);

    /**
     * @brief draw : To let the game draw him and all his component
     * @param painter
     */
    void draw(QPainter *painter) const;

    /**
     * @brief eventFilter : To recive all events happenning
     * in the game window
     * @param object
     * @param event
     * @return
     */
    bool eventFilter(QObject *object, QEvent *event);

private slots:
    void on_clickQuitButton();
    void on_clickRestartButton();

    /**
     * @brief createRandomBonus : Called every 7sec to create a bonus
     */
    void createRandomBonus();

    /**
     * @brief refresh : call every frame to check collisions and apply changes
     */
    void refresh();


};

#endif // GAME_H
