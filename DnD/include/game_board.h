#ifndef DND_GAME_BOARD_H
#define DND_GAME_BOARD_H

#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include "utility.h"
#include "player.h"
#include "dice.h"
#include "obstacle.h"
#include "gift.h"
#include "door.h"
#include "board.h"
#include "message.h"
#include "character.h"
#include "character_skills.h"
#include "connectionWithPlayer.h"

class GameBoard : public QGraphicsView {
    Q_OBJECT

public:
    int locationNum = 0;
    GameBoard();
    enum class Location {
        firstLocation, //можно назвать как-то осмысленно
        secondLocation,
    };
    Location currentLocation_;
    void changeLocation();
    Player* player_;
    Player* player2_;
    //Window* bkg;
    //Master* master;
    //WindowForText* wft;
    std::vector<KeyCord>keys_;
    std::vector<Dice*> dices_;
    std::vector<std::vector<GiftCord>> gifts_;
    std::vector<std::vector<ObstacleCord>> obstacles_;
    std::vector<std::vector<Obstacle*>> frame_;
    Door *door_;
    void makeRandomGifts(int amount, int location);
    void makeRandomObstacles(int amount, int location);
    void makeObstacles();
    void makeGift(int x, int y, int location);
    void makeKey(int x, int y, int location);
    void makeKeys(int location);
    void makeObstacle(const QString str, int x, int y, int location, bool destroyable);
    void makeDoor(int x, int y);
    void makeFrame(const QString str);
    void makeGame();
    void makeLeftWindow();
    std::vector<Board>boards;
    std::vector<QGraphicsScene*>scenes;
    void keyPressEvent(QKeyEvent *event);
    bool gameIsFinished = false;
    int start_x = 400;
    int start_y = 0;
    const int board_size = 795;
    const double cell_width = board_size / boards[0].getAmountOfEncounters();
    const int window_width = 1400;
    const int window_height = board_size + cell_width;
};

#endif //DND_GAME_BOARD_H
