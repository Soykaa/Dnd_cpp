#ifndef DND_GAME_BOARD_H
#define DND_GAME_BOARD_H

#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include <string>
#include "utility.h"
#include "enums.h"
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
    void changeLocation();
    Well well;
    Player* player_;
    Player* player2_;
    bool gameIsStarted = false;
    bool firstChange = true;
    CharIm charIm;
    std::vector<ConnectionWindow> conWind;
    std::vector<BackpackIm> bpi;
    std::vector<std::vector<EnemyImCord>> enemies;
    //ConnectionWindow conWind;
    BackpackIm bp;
    Doors doors;
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
    void makeEnemy(int x, int y, int location, int num);
    void makeExit(int x, int  y, int localLocationNum);
    void makeKeys(int location);
    void makeObstacle(const QString& str, int x, int y, int location, bool destroyable);
    void makeDoor(int x0, int y0, int x1, int y1);
    void makeFrame(const QString& str) const;
    void makeGame();
    void makeLeftWindow();
    void makeWell(int x, int y, int locationNum);
    void makeRope(int x, int y, int locationNum);
    void makeBackpack();
    void takeKey(int player) const;

    void buildBoard(int location, const std::string& filename);

    void takeRope(int player) const;
    void takeGift(int player, int giftNum) const;
    std::vector<Board>boards;
    std::vector<QGraphicsScene*>scenes;
    void keyPressEvent(QKeyEvent *event);
    bool gameIsFinished = false;
    int start_x = 400;
    int start_y = 0;
    const int board_size = 795;
    const int cell_width = board_size / boards[0].getAmountOfEncounters();
    const int window_width = start_x + board_size + 4 * cell_width + 50;
    const int window_height = board_size + cell_width;
    const int extract_height = 90;
};

#endif //DND_GAME_BOARD_H
