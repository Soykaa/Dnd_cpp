#include <QDebug>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>
#include <QGraphicsItem>
#include <cassert>
#include <fstream>
#include "include/sleep.h"
#include "include/game_board.h"
#include "include/player.h"
#include "include/obstacle.h"
#include "include/dice.h"
#include "include/character.h"
#include "include/character_skills.h"

extern GameBoard *game;

GameBoard::GameBoard() {
    charIm.chars.resize(10);
    charIm.chars[0] = "../images/char0.png";
    charIm.chars[1] = "../images/char1.png";
    charIm.chars[2] = "../images/char2.png";
    charIm.chars[3] = "../images/char3.png";
    charIm.chars[4] = "../images/char4.png";
    charIm.chars[5] = "../images/char5.png";
    charIm.chars[6] = "../images/char6.png";
    charIm.chars[7] = "../images/char7.png";
    charIm.chars[8] = "../images/char8.png";
    charIm.chars[9] = "../images/char9.png";
    boards.resize(2);
    scenes.resize(2);
    gifts_.resize(2);
    frame_.resize(2);
    conWind.resize(2);
    enemies.resize(2);
    bpi.resize(2);
    obstacles_.resize(2);
    for (auto& scene : scenes) {
        scene = new QGraphicsScene();
        scene -> setSceneRect(0, 0, window_width, window_height + extract_height);
    }
    setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
    setScene(scenes[0]);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(window_width, window_height + extract_height);
    player_ = new Player();
    player2_ = new Player();
}


void GameBoard::makeGift(int x, int y, int location) {
    GiftCord gf;
    gf.gift = new Gift();
    gf.gift->setGift(x, y, location);
    gf.x = x;
    gf.y = y;
    gifts_[location].push_back(gf);
    boards[location].changeOneFieldType(x, y, Type::item, ItemType::gift);
}

void GameBoard::makeKey(int x, int y, int location) {
        KeyCord k;
        k.key = new Key();
        k.key->setKey("../images/key.png", x, y, location);
        k.x = x;
        k.y = y;
        keys_.push_back(k);
        boards[location].changeOneFieldType(x, y, Type::item, ItemType::triangle_key);
}

void GameBoard::makeEnemy(int x, int y, int location, int num) {
        EnemyImCord e;
        e.ei = new EnemyIm();
        e.en.setHitPoints(rand() %  17 + 14);
        if (num == 1)
            e.ei->setEnemyIm("../images/enemy1.png", x, y, location);
        else if (num == 2)
            e.ei->setEnemyIm("../images/enemy2.png", x, y, location);
        else
            e.ei->setEnemyIm("../images/enemy3.png", x, y, location);
        e.x = x;
        e.y = y;
        enemies[location].push_back(e);
        boards[location].changeOneFieldType(x, y, Type::enemy);
}

void GameBoard::makeKeys(int location) {
    makeKey(9, 9, 0);
    makeKey(0, 9, 0);
}

void GameBoard::takeKey(int player) const {
    auto* it1 = new ItemBack();
    auto* it2 = new ItemBack();
    int y;
    if (player == 0)
        y = 80;
    else
        y = 80 + (window_height - 50)/ 2 + 30;
    it1->setItemBack("../images/key.png", start_x + board_size + cell_width + 30, y, 0, 0);
    it2->setItemBack("../images/key.png", start_x + board_size + cell_width + 30, y, 1, 0);
}

void GameBoard::takeRope(int player) const {
    auto* it1 = new ItemBack();
    auto* it2 = new ItemBack();
    int y;
    if (player == 0)
        y = 300;
    else
        y = 300 + (window_height - 50)/ 2 + 30;
    it1->setItemBack("../images/rope.png", start_x + board_size + cell_width + 30, y, 0, 0);
    it2->setItemBack("../images/rope.png", start_x + board_size + cell_width + 30, y, 1, 0);
}

void GameBoard::makeRope(int x, int y, int location) {
    RopeCord rp{};
    rp.rope = new WellItem();
    rp.rope->setWellItem(x, y, location, true);
    rp.x = x;
    rp.y = y;
    well.ropes.push_back(rp);
    boards[location].changeOneFieldType(x, y, Type::item, ItemType::rope);
}

void GameBoard::makeWell(int x, int y, int unusedLocationNum) {
    well.well = new WellItem();
    well.well->setWellItem(x, y, locationNum, false);
    boards[locationNum].changeOneFieldType(x, y, Type::obstacle);
    boards[locationNum].changeOneFieldType(x + 1, y, Type::obstacle);
    boards[locationNum].changeOneFieldType(x + 2, y, Type::obstacle);
    boards[locationNum].changeOneFieldType(x, y + 1, Type::obstacle);
    boards[locationNum].changeOneFieldType(x + 1, y + 1, Type::obstacle);
    boards[locationNum].changeOneFieldType(x + 2, y + 1, Type::obstacle);
    boards[locationNum].changeOneFieldType(x, y + 2, Type::well);
    boards[locationNum].changeOneFieldType(x + 1, y + 2, Type::well);
    boards[locationNum].changeOneFieldType(x + 2, y + 2, Type::well);
}

void GameBoard::takeGift(int player, int giftNum) const {
    auto* it1 = new ItemBack();
    auto* it2 = new ItemBack();
    int x, y;
    if (giftNum == 1) {
        x = start_x + board_size + cell_width + 30;
        y = 190;
    }
    if (giftNum == 2) {
        x = start_x + board_size + cell_width + 80;
        y = 240;
    }
    if (giftNum == 3) {
        x = start_x + board_size + cell_width + 130;
        y = 190;
    }
    if (player)
        y += (window_height - 50)/ 2 + 30;

    it1->setItemBack("../images/gift.png", x, y, 0, 1);
    it2->setItemBack("../images/gift.png", x, y, 1, 1);
}

void GameBoard::makeFrame(const QString& str) const {
    for (int i = 0; i < window_height; i += cell_width) {
        auto* o1 = new Obstacle();
        o1->setForFrame(str, start_x - cell_width, i, 0);
        auto* o2 = new Obstacle();
        o2->setForFrame(str, start_x + board_size, i, 0);
        auto* o3 = new Obstacle();
        o3->setForFrame(str, start_x - cell_width, i, 1);
        auto* o4 = new Obstacle();
        o4->setForFrame(str, start_x + board_size, i, 1);
    }
    for (int i = start_x; i < board_size + start_x; i += cell_width) {
        auto* o1 = new Obstacle();
        o1->setForFrame(str, i, window_height - cell_width, 0);
        auto* o2 = new Obstacle();
        o2->setForFrame(str, i, window_height - cell_width, 1);
    }
}

void GameBoard::makeGame() {
    makeLeftWindow();
    makeBackpack();
    makeFrame("../images/obstacle.png");
    player_->setPlayer("../images/dragonborn.png");
    scenes[0]->addItem(player_);
    player2_->setPlayer("../images/character.png");
    player_->setPlayer(charIm.chars[charIm.char1]);
    scenes[0]->addItem(player_);
    player2_->setPlayer(charIm.chars[charIm.char2]);
    scenes[0]->addItem(player2_);
    buildBoard(0, "../locations/first_location.txt");
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    player2_->setFlag(QGraphicsItem::ItemIsFocusable);
    player2_->setFocus();
    buildBoard(1, "../locations/second_location.txt");
    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()));
    show();
}

void GameBoard::makeLeftWindow() {
    for (size_t i = 0; i != conWind.size(); ++i) {
        conWind[i].window = new Window();
        conWind[i].master = new Master();
        conWind[i].wft_l = new WindowForText();
        conWind[i].window->setWindow("../images/a.svg", i);
        conWind[i].master->setMaster("../images/qst.png", i);
        conWind[i].wft_l->setWindowForText("../images/gst_bg", i);
        conWind[i].wft_b = new WindowForText_D();
        conWind[i].wft_b->setWindowForText_D("../images/gst_bg", i);
        conWind[i].hint = new MessForPlayer(i);
        conWind[i].hint->setMessForPlayer(0, 450, 870, 0);
        conWind[i].mess = new MessForPlayer(i);
        conWind[i].hint2 = new MessForPlayer(i);
        conWind[i].hint3 = new MessForPlayer(i);
        conWind[i].hint4 = new MessForPlayer(i);
        conWind[i].hint5 = new MessForPlayer(i);
        conWind[i].char1 = new ItemBack();
        conWind[i].char2 = new ItemBack();
    }
}

void GameBoard::makeBackpack() {
    for (size_t i = 0; i != bpi.size(); ++i) {
        bpi[i].bi1 = new BackgroundIm();
        bpi[i].bi2 = new BackgroundIm();
        bpi[i].bi1->setBackgroundIm("../images/bkg_backpack.jpg", start_x + board_size + cell_width + 10, 10, i);
        bpi[i].bi2->setBackgroundIm("../images/bkg_backpack.jpg", start_x + board_size + cell_width + 10, (window_height - 50)/ 2 + 40, i);
        auto* it = new ItemBack();
        it->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 30, 80, i, 0);
        auto* it2 = new ItemBack();
        it2->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 30, 80 + (window_height - 50)/ 2 + 30, i, 0);
        auto* it3 = new ItemBack();
        it3->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 30, 300, i, 0);
        auto* it4 = new ItemBack();
        it4->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 30, 300 + (window_height - 50)/ 2 + 30, i, 0);
        auto* it5 = new ItemBack();
        it5->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 30, 190, i, 1);
        auto* it6 = new ItemBack();
        it6->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 30, 190 + (window_height - 50)/ 2 + 30, i, 1);
        auto* it7 = new ItemBack();
        it7->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 130, 190, i, 1);
        auto* it8 = new ItemBack();
        it8->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 130, 190 + (window_height - 50)/ 2 + 30, i, 1);
        auto* it9 = new ItemBack();
        it9->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 80, 240, i, 1);
        auto* it10 = new ItemBack();
        it10->setItemBack("../images/bkg_it.jpg", start_x + board_size + cell_width + 80, 240 + (window_height - 50)/ 2 + 30, i, 1);
        bpi[i].name1 = new MessForPlayer(i);
        bpi[i].name1->setMessForPlayer(15, start_x + board_size + cell_width + 45, 25, 0);
        bpi[i].name2 = new MessForPlayer(i);
        bpi[i].name2->setMessForPlayer(16, start_x + board_size + cell_width + 45, 25 + (window_height - 50)/ 2 + 30, 0);
    }
}


void GameBoard::makeRandomGifts(int amount, int location) {
    for (int i = 0; i < amount; i++) {
        int x = rand() % boards[location].getAmountOfEncounters();
        int y = rand() % boards[location].getAmountOfEncounters();
        if (!(x == 0 && y == 0) && boards[location].getFieldType(x, y) == Type::emptyField)
            makeGift(x, y, location);
    }
}

void GameBoard::makeObstacle(const QString& str, int x, int y, int location, bool destroyable) {
    ObstacleCord oc{};
    oc.obst = new Obstacle();
    oc.obst->setObstacle(str, x, y, location);
    oc.x = x;
    oc.y = y;
    obstacles_[location].push_back(oc);
    boards[location].changeOneFieldType(x, y, destroyable ? Type::destroyableWall : Type::obstacle);
}

void GameBoard::makeExit(int x, int y, int localLocationNum) {
    Door*  d = new Door();
    d->setDoor(x, y, localLocationNum, true);
    boards[localLocationNum].changeOneFieldType(x, y, Type::finnish);
}


void GameBoard::makeRandomObstacles(int amount, int location) {
    for (size_t i = 0; i != amount; ++i) {
        int x = rand() % boards[location].getAmountOfEncounters();
        int y = rand() % boards[location].getAmountOfEncounters();
        if (boards[location].getFieldType(x, y) == Type::emptyField)
            makeObstacle("../images/obstacle.png", x, y, location, false);
    }
}

void GameBoard::makeObstacles() {
    size_t num = rand() % (boards[0].getAmountOfEncounters() / 2);
    for (size_t i = 0; i != boards[0].getAmountOfEncounters(); ++i) {
        if (i == num || i == boards[0].getAmountOfEncounters() / 2 + num + 1) {
            makeObstacle("../images/obstacle.png", i, 7, 0, true);
            continue;
        }
        makeObstacle("../images/obstacle.png", i, 7, 0, false);
    }
    num = boards[0].getAmountOfEncounters() / 2;
    for (size_t i = 8; i != boards[0].getAmountOfEncounters(); ++i)
        makeObstacle("../images/obstacle.png", num, i, 0, false);
}

void GameBoard::makeDoor(int x0, int y0, int x1, int y1) {
    doors.door0 = new Door();
    doors.door1 = new Door();
    doors.x0 = x0;
    doors.y0 = y0;
    doors.x1 = x1;
    doors.y1 = y1;
    doors.door0->setDoor(x0, y0, 0 , false);
    doors.door1->setDoor(x1, y1, 1, false);
    boards[0].changeOneFieldType(x0, y0, Type::door);
    boards[1].changeOneFieldType(x1, y1, Type::door);
}

void GameBoard::keyPressEvent(QKeyEvent *event) {
    if (!gameIsStarted && event->key() == Qt::Key_Any) {
        conWind[0].hint->setMessForPlayer("", 0, 0, 0);
        gameIsStarted = true;
        conWind[0].mess->setMessForPlayer(1, 40, 575, 0);
        sleep(900);
        conWind[0].mess->setMessForPlayer(2, 40, 575, 0);
        sleep(900);
        conWind[0].mess->setMessForPlayer(3, 25, 525, 0);
        sleep(900);
        conWind[0].mess->setMessForPlayer(4, 25, 575, 0);
        sleep(900);
        conWind[0].mess->setMessForPlayer(5, 35, 600, 0);
        sleep(900);
        conWind[0].mess->setMessForPlayer(6, 15, 550, 0);
        for (int i = 0; i < 2; i++) {
            conWind[i].hint->setMessForPlayer(7, 30, window_height + 15, 0);
            conWind[i].hint2->setMessForPlayer(8, 300, window_height + 15, 0);
            conWind[i].hint3->setMessForPlayer(9, 930, window_height + 15, 0);
            conWind[i].hint4->setMessForPlayer(10, 1200, window_height + 15, 0);
            conWind[i].hint5->setMessForPlayer(11, 615, window_height + 10, 0);
            conWind[i].char1->setItemBack(charIm.chars[charIm.char1], 850, window_height + 20, i, true);
            conWind[i].char2->setItemBack(charIm.chars[charIm.char2], 540, window_height + 20, i, true);
        }
        return;
    }
    if (!gameIsStarted)
        return;

    int i = locationNum;

    if (gameIsFinished)
        return;

    if (event->key() == Qt::Key_Left) {
            boards[i].makeTurn(Direction::left, 0);
    }
    if (event->key() == Qt::Key_Right) {
            boards[i].makeTurn(Direction::right, 0);
    }
    if (event->key() == Qt::Key_Up) {
            boards[i].makeTurn(Direction::up, 0);
    }
    if (event->key() == Qt::Key_Down) {
            boards[i].makeTurn(Direction::down, 0);
    }


    if (event->key() == Qt::Key_A) {
            boards[i].makeTurn(Direction::left, 1);
    }
    if (event->key() == Qt::Key_D) {
            boards[i].makeTurn(Direction::right, 1);
    }
    if (event->key() == Qt::Key_W) {
            boards[i].makeTurn(Direction::up, 1);
    }
    if (event->key() == Qt::Key_S) {
            boards[i].makeTurn(Direction::down, 1);
    }
    int x_1 = boards[i].getCharacterPosition_X(0);
    int y_1 = boards[i].getCharacterPosition_Y(0);
    player_->setPos(start_x + x_1 * cell_width, start_y + y_1 * cell_width);

    int x_2 = boards[i].getCharacterPosition_X(1);
    int y_2 = boards[i].getCharacterPosition_Y(1);
    player2_->setPos(start_x + x_2 * cell_width, start_y + y_2 * cell_width);

    if (boards[i].getFieldItemType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == ItemType::gift) {
        auto[taken, num] = boards[i].takeItems(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0), 0);
        if (taken) {
            takeGift(0, num);
            for (GiftCord g : gifts_[i]) {
                if (g.x == boards[i].getCharacterPosition_X(0) && g.y == boards[i].getCharacterPosition_Y(0))
                    g.gift->~Gift();
            }
        } else {
            conWind[i].mess->setMessForPlayer("already has", 10, 575, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 10, 575, locationNum);
        }
    }

    if (boards[i].getFieldItemType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == ItemType::gift) {
        auto[taken, num] = boards[i].takeItems(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1), 1);
        if (taken) {
            takeGift(1, num);
            for (GiftCord g : gifts_[i]) {
                if (g.x == boards[i].getCharacterPosition_X(1) && g.y == boards[i].getCharacterPosition_Y(1)) {
                    g.gift->~Gift();
                }
            }

        } else {
            conWind[i].mess->setMessForPlayer("already has", 10, 575, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 10, 575, locationNum);
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::well &&
        boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::well) {
        if (!well.canUse) {
            if (boards[i].canUseOneItem(0, ItemType::rope) && boards[i].canUseOneItem(1, ItemType::rope)) {
                conWind[i].mess->setMessForPlayer("use ropes", 15, 575, 0);
                if (event->key() == Qt::Key_Any) {
                    well.canUse = true;
                    conWind[i].mess->setMessForPlayer("can use well", 40, 575, 0);
                    sleep(1000);
                    conWind[i].mess->setMessForPlayer("one by one", 40, 550, 0);
                    sleep(900);
                    conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
                    return;
                }
            } else {
                conWind[i].mess->setMessForPlayer("not enough ropes", 40, 550, 0);
                sleep(900);
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
            }
        } else {
            conWind[i].mess->setMessForPlayer("one by one", 40, 550, 0);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
        }
    } else if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::well) {
        if (well.canUse) {
            conWind[i].mess->setMessForPlayer("want increase", 40, 550, 0);
            if (event->key() == Qt::Key_Shift) {
                boards[i].increase(0);
                conWind[i].mess->setMessForPlayer("increased", 60, 550, 0);
                sleep(900);
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
            }
        } else {
            conWind[i].mess->setMessForPlayer("no ropes", 40, 555, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
        }
    } else if (boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::well) {
        if (well.canUse) {
            conWind[i].mess->setMessForPlayer("want increase", 40, 550, locationNum);
            if (event->key() == Qt::Key_CapsLock) {
                boards[i].increase(1);
                conWind[i].mess->setMessForPlayer("increased", 60, 550, 0);
                sleep(900);
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
            }
        } else {
            conWind[i].mess->setMessForPlayer("no ropes", 40, 555, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
        }
    }

    if (boards[i].getFieldItemType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == ItemType::triangle_key) {
        if (boards[i].takeUniqItem(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0), 0)) {
            for (KeyCord k : keys_) {
                if (k.x == boards[i].getCharacterPosition_X(0) && k.y == boards[i].getCharacterPosition_Y(0)) {
                    k.key->~Key();
                    takeKey(0);
                }
            }
        } else {
            conWind[i].mess->setMessForPlayer("already has", 10, 575, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 10, 575, locationNum);
        }
    }

    if (boards[i].getFieldItemType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == ItemType::triangle_key) {
        if (boards[i].takeUniqItem(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1), 1)) {
            for (KeyCord k : keys_) {
                if (k.x == boards[i].getCharacterPosition_X(1) && k.y == boards[i].getCharacterPosition_Y(1)) {
                    k.key->~Key();
                    takeKey(1);
                }
            }
        } else {
            conWind[i].mess->setMessForPlayer("already has", 10, 575, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 10, 575, locationNum);
        }
    }

    if (boards[i].getFieldItemType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == ItemType::rope) {
        if (boards[i].takeUniqItem(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0), 0)) {
            for (RopeCord r : well.ropes) {
                if (r.x == boards[i].getCharacterPosition_X(0) && r.y == boards[i].getCharacterPosition_Y(0)) {
                    r.rope->~WellItem();
                    takeRope(0);
                }
            }
        } else {
            conWind[i].mess->setMessForPlayer("already has", 10, 575, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("none", 10, 575, locationNum);
        }
    }

    if (boards[i].getFieldItemType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == ItemType::rope) {
        if (boards[i].takeUniqItem(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1), 1)) {
            for (RopeCord r : well.ropes) {
                if (r.x == boards[i].getCharacterPosition_X(1) && r.y == boards[i].getCharacterPosition_Y(1)) {
                    r.rope->~WellItem();
                    takeRope(1);
                }
            }
        } else {
            conWind[i].mess->setMessForPlayer("already has", 10, 575, locationNum);
            sleep(500);
            conWind[i].mess->setMessForPlayer("none", 10, 575, locationNum);
        }
    }

    auto[dir1, a, b] = boards[i].check(0);
    if (!dir1.empty()) {
        if (boards[i].canDestroyWall(0)) {
                std::string action = "1 break wall " + dir1;
                conWind[i].mess->setMessForPlayer(action, 20, 575, locationNum);
            if (event->key() == Qt::Key_Shift) {
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
                for (ObstacleCord o : obstacles_[i])
                    if (o.x == a && o.y == b) {
                        o.obst->setObstacle("../images/broakenwall.png", a, b, i);
                        sleep(450);
                        o.obst->~Obstacle();
                    }
                boards[i].destroy(a, b);
            }
        } else {
            conWind[i].mess->setMessForPlayer("weak", 15, 550, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("need gift", 25, 550, locationNum);
        }
        sleep(900);
        conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
    }

    auto[dir2, c, d] = boards[i].check(1);
    if (!dir2.empty()) {
        if (boards[i].canDestroyWall(1)) {
            std::string action = "2 break wall " + dir2;
            conWind[i].mess->setMessForPlayer(action, 20, 575, locationNum);
            if (event->key() == Qt::Key_CapsLock) {
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
                for (ObstacleCord o : obstacles_[i])
                    if (o.x == c && o.y == d) {
                        o.obst->setObstacle("../images/broakenwall.png", c, d, i);
                        sleep(450);
                        o.obst->~Obstacle();
                    }
                boards[i].destroy(c, d);
            }
        } else {
            conWind[i].mess->setMessForPlayer("weak", 15, 550, locationNum);
            sleep(900);
            conWind[i].mess->setMessForPlayer("need gift", 25, 550, locationNum);
        }
        sleep(900);
        conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
    }

    auto[dir3, aa, bb] = boards[i].check(0, Type::enemy);
    if (!dir3.empty()) {
        Enemy* en;
        for (EnemyImCord e : enemies[i]) {
            if (e.x == aa && e.y == bb) {
                en = &e.en;
            }
        }
        int res1 = boards[i].beatEnemy(0, en);
        if (res1 != -1) {
            std::string action = "1 beat enemy " + dir3;
            conWind[i].mess->setMessForPlayer(action, 20, 575, locationNum);
            if (event->key() == Qt::Key_Shift) {
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
                for (EnemyImCord e : enemies[i]) {
                    if (e.x == aa && e.y == bb) {
                        if (res1 == 1) {
                            e.ei->setEnemyIm("../images/h.png", aa, bb, i);
                            conWind[i].mess->setMessForPlayer("beat charisma", 40, 590, 0);
                        } else {
                            e.ei->setEnemyIm("../images/s.png", aa, bb, i);
                            conWind[i].mess->setMessForPlayer("beat strength", 40, 590, 0);
                        }
                        sleep(450);
                        boards[i].reduce(0);
                        e.ei->~EnemyIm();
                    }
                }
                boards[i].destroy(aa, bb);
            }
        } else {
            conWind[i].mess->setMessForPlayer("weak2", 40, 550, 0);
        }
        sleep(900);
        conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
    }

    auto[dir4, cc, dd] = boards[i].check(1,  Type::enemy);
    if (!dir4.empty()) {
        Enemy* en;
        for (EnemyImCord e : enemies[i])
            if (e.x == cc && e.y == dd) {
                en = &e.en;
            }
        int res2 = boards[i].beatEnemy(1, en);
        if (res2 != -1) {
            std::string action = "2 beat enemy " + dir4;
            conWind[i].mess->setMessForPlayer(action, 5, 575, locationNum);
            if (event->key() == Qt::Key_CapsLock) {
                conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
                for (EnemyImCord e : enemies[i]) {
                    if (e.x == cc && e.y == dd) {
                        if (res2 == 1) {
                            e.ei->setEnemyIm("../images/h.png", cc, dd, i);
                            conWind[i].mess->setMessForPlayer("beat charisma", 40, 590, 0);
                        } else {
                            e.ei->setEnemyIm("../images/s.png", cc, dd, i);
                            conWind[i].mess->setMessForPlayer("beat strength", 40, 590, 0);
                        }
                        boards[i].reduce(1);
                        sleep(450);
                        e.ei->~EnemyIm();
                    }
                }
                boards[i].destroy(cc, dd);
            }
        } else {
            conWind[i].mess->setMessForPlayer("weak2", 40, 550, 0);
        }
        sleep(900);
        conWind[i].mess->setMessForPlayer("none", 20, 575, locationNum);
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::finnish &&
        boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::finnish) {
        gameIsFinished = true;
        auto *text = new Message();
        text->setMessage(i);
        text->setPos(500, 400);

        player_->~Player();
        player2_->~Player();
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::door &&
            boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::door) {
        if (boards[i].canUseOneItem(0, ItemType::triangle_key) && boards[i].canUseOneItem(1, ItemType::triangle_key)) {
            conWind[i].mess->setMessForPlayer("open door", 40, 575, locationNum);
            if (event->key() == Qt::Key_Any) {
                changeLocation();
            }
        }
    }
}

void GameBoard::changeLocation() {
    if (locationNum == 0) {
        locationNum = 1;
        setBackgroundBrush(QBrush(QImage("../images/second_location.jpg")));
        scenes[1]->addItem(player_);
        scenes[1]->addItem(player2_);
        boards[1].heroes[0].x = doors.x1;
        boards[1].heroes[0].y = doors.y1;
        boards[1].heroes[1].x = doors.x1;
        boards[1].heroes[1].y = doors.y1;
        player_->setPos(start_x + boards[1].getCharacterPosition_X(0) * cell_width, start_y + boards[1].getCharacterPosition_Y(0) * cell_width);
        player2_->setPos(start_x + boards[1].getCharacterPosition_X(1) * cell_width, start_y + boards[1].getCharacterPosition_Y(1) * cell_width);
        setScene(scenes[1]);
        if (firstChange) {
            conWind[1].mess->setMessForPlayer(12, 40, 575, 0);
            sleep(800);
            conWind[1].mess->setMessForPlayer(13, 60, 575, 0);
            sleep(800);
            conWind[1].mess->setMessForPlayer(14, 15, 560, 0);
            sleep(800);
            firstChange = false;
        }
        return;
    }
    if (locationNum == 1) {
        locationNum = 0;
        setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
        scenes[0]->addItem(player_);
        scenes[0]->addItem(player2_);
        boards[1].heroes[0].x = doors.x0;
        boards[1].heroes[0].y = doors.y0;
        boards[1].heroes[1].x = doors.x0;
        boards[1].heroes[1].y = doors.y0;
        player_->setPos(start_x + boards[1].getCharacterPosition_X(0) * cell_width, start_y + boards[1].getCharacterPosition_Y(0) * cell_width);
        player2_->setPos(start_x + boards[1].getCharacterPosition_X(1) * cell_width, start_y + boards[1].getCharacterPosition_Y(1) * cell_width);
        setScene(scenes[0]);
        return;
    }
}

void GameBoard::buildBoard(int location, const std::string& filename) {
    std::ifstream file;
    file.open(filename, std::ios_base::in);
    assert(file.is_open());
    while (!file.eof()) {
        std::string object;
        int x, y;
        file >> object >> x >> y;
        if (object == "player1") {
            player_->setPos(start_x + x * game->cell_width, start_y + y * game->cell_width);
        } else if (object == "player2") {
            player2_->setPos(start_x + x * game->cell_width, start_y + y * game->cell_width);
        } else if (object == "door") {
            int x1, y1;
            file >> x1 >> y1;
            makeDoor(x, y, x1, y1);
        } else if (object == "gift") {
            makeGift(x, y, location);
        } else if (object == "rope") {
            makeRope(x, y, location);
        } else if (object == "key") {
            makeKey(x, y, location);
        } else if (object == "exit") {
            makeExit(x, y, location);
        } else if (object == "well") {
            makeWell(x, y, location);
        } else if (object == "enemy") {
            int num;
            file >> num;
            makeEnemy(x, y, location, num);
        } else if (object == "obstacle") {
            makeObstacle("../images/obstacle.png", x, y, location, false);
        } else if (object == "destroyableObstacle") {
            makeObstacle("../images/obstacle.png", x, y, location, true);
        }
    }
}
