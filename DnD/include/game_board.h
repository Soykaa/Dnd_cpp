#ifndef DND_GAME_BOARD_H
#define DND_GAME_BOARD_H

#include <QGraphicsView>
#include <QKeyEvent>
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

class GameBoard : public QGraphicsView {
    //Q_OBJECT
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
    std::vector<Dice*> dices_;
    std::vector<GiftCord> gifts_;
    std::vector<ObstacleCord> obstacles_;
    Door *door_;
    void makeGifts(int amount, int location);
    void makeObstacles(int amount, int location);
    void makeGift(int giftNum, int x, int y, int location);
    void makeObstacle(int obstNum, int x, int y, int location);
    void makeDoor(int x, int y);
    void makeGame();
    std::vector<Board>boards;
    std::vector<QGraphicsScene*>scenes;
    void keyPressEvent(QKeyEvent *event);
    bool gameIsFinished = false;
    int start_x = 0;
    int start_y = 0;
    const int board_size = 1000;
    const int window_width = 1000;
    const int window_height = 1000;
    const int cell_width = board_size / boards[0].getAmountOfEncounters();
};

#endif //DND_GAME_BOARD_H
