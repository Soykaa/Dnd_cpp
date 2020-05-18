#include <QDebug>
#include <QApplication>
#include <QGraphicsItem>
#include "include/sleep.h"
#include "include/game_board.h"
#include "include/player.h"
#include "include/obstacle.h"
#include "include/dice.h"
#include "include/character.h"
#include "include/character_skills.h"

extern GameBoard *game;

GameBoard::GameBoard() {
    setMouseTracking(true);
    boards.resize(2);
    scenes.resize(2);
    gifts_.resize(2);
    // keys_.resize(2);
    obstacles_.resize(2);
    boards[1].changeOneFieldType(boards[1].getAmountOfEncounters() - 1, boards[1].getAmountOfEncounters() - 1, Type::finnish);
    currentLocation_ = Location::firstLocation;
    for (auto& scene : scenes) {
        scene = new QGraphicsScene();
        scene -> setSceneRect(0, 0, window_width, window_height);
    }
    setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
    setScene(scenes[0]);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(window_width, window_height);
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
    boards[location].changeOneFieldType(x, y, Type::gift);
}

void GameBoard::makeKey(int x, int y, int location) {
        KeyCord k;
        k.key = new Key();
        k.key->setKey("../images/key.png", x, y, location);
        k.x = x;
        k.y = y;
        keys_.push_back(k);
        boards[location].changeOneFieldType(x, y, Type::key);
}

void GameBoard::makeKeys(int location) {
    makeKey(9, 9, 0);
    makeKey(0, 9, 0);
}

void GameBoard::makeGame() {
    player_->setPlayer("../images/dragonborn.png");
    player_->setPos(start_x, start_y);
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    scenes[0]->addItem(player_);
    player2_->setPlayer("../images/character.png");
    player2_->setPos(start_x, start_y);
    player2_->setFlag(QGraphicsItem::ItemIsFocusable);
    player2_->setFocus();
    scenes[0]->addItem(player2_);
    makeDoor(5, 5);
    makeRandomGifts(3, 1);
    makeKeys(0);
    makeObstacles();
    //makeRandomObstacles(45, 0);
    makeRandomObstacles(30, 1);
    show();
}


void GameBoard::makeRandomGifts(int amount, int location) {
    for (int i = 0; i < amount; i++) {
        int x = rand() % boards[location].getAmountOfEncounters();
        int y = rand() % boards[location].getAmountOfEncounters();
        if (boards[location].getFieldType(x, y) == Type::emptyField)
            makeGift(x, y, location);
    }
}

void GameBoard::makeObstacle(const QString str, int x, int y, int location, bool destroyable) {
    ObstacleCord oc;
    oc.obst = new Obstacle();
    oc.obst->setObstacle(str, x, y, location);
    oc.x = x;
    oc.y = y;
    obstacles_[location].push_back(oc);
    boards[location].changeOneFieldType(x, y, destroyable ? Type::destroyableWall : Type::obstacle);
}


void GameBoard::makeRandomObstacles(int amount, int location) {
    for (int i = 0; i < amount; i++) {
        int x = rand() % boards[location].getAmountOfEncounters();
        int y = rand() % boards[location].getAmountOfEncounters();
        if (boards[location].getFieldType(x, y) == Type::emptyField)
            makeObstacle("../images/obstacle.png", x, y, location, false);
    }
}

void GameBoard::makeObstacles() {
    int num = rand() % (boards[0].getAmountOfEncounters() / 2);
    for (int i = 0; i < boards[0].getAmountOfEncounters(); i++) {
        if (i == num || i == boards[0].getAmountOfEncounters() / 2 + num) {
            makeObstacle("../images/obstacle.png", i, 7, 0, true);
            continue;
        }
        makeObstacle("../images/obstacle.png", i, 7, 0, false);
    }
    num = boards[0].getAmountOfEncounters() / 2;
    makeObstacle("../images/obstacle.png", num, 8, 0, false);
    makeObstacle("../images/obstacle.png", num, 9, 0, false);
}

void GameBoard::makeDoor(int x, int y) {
    door_ = new Door();
    door_->setDoor();
    door_->setPos(x * game->cell_width + start_x, y * game->cell_width + start_y);
    scenes[0]->addItem(door_);
    boards[0].changeOneFieldType(x, y, Type::door);
    boards[1].changeOneFieldType(x + 1, y + 1, Type::door);
}

void GameBoard::keyPressEvent(QKeyEvent *event) {
    int i = locationNum;
    //qDebug() << "dext " << boards[i].h1->cs_.getDexterity() << "\n";
    //qDebug() << i << "\n";
    if (event->key() == Qt::Key_Any) {
        QApplication::quit();
    }
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


    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::finnish) {
        qDebug() << "finnish\n";
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::gift) {
        boards[i].takeGift(18, 0);
        qDebug() << "gift\n";
        for (GiftCord g : gifts_[i]) {
            if (g.x == boards[i].getCharacterPosition_X(0) && g.y == boards[i].getCharacterPosition_Y(0))
                g.gift->~Gift();
                //qDebug() << g.x << " " << g.y << "\n";
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::gift) {
        boards[i].takeGift(18, 1);
        for (GiftCord g : gifts_[i]) {
            if (g.x == boards[i].getCharacterPosition_X(1) && g.y == boards[i].getCharacterPosition_Y(1))
                g.gift->~Gift();
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::key) {
        boards[i].takeItem(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0), 0);
        for (KeyCord k : keys_) {
            if (k.x == boards[i].getCharacterPosition_X(0) && k.y == boards[i].getCharacterPosition_Y(0))
                k.key->~Key();
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::key) {
        boards[i].takeItem(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1), 1);
        for (KeyCord k : keys_) {
            if (k.x == boards[i].getCharacterPosition_X(1) && k.y == boards[i].getCharacterPosition_Y(1))
                k.key->~Key();
        }
    }

    auto[a, b] = boards[i].check(0);
    qDebug() << a << " " << b << "\n";
    if (a != -1 && b != -1 && boards[i].canDestroyWall(0)) {
        qDebug() << "press F to destroy wall " << a << " " << b << "\n";
        if (event->key() == Qt::Key_F) {
            qDebug() << "f pressed\n";
            for (ObstacleCord o : obstacles_[i])
                if (o.x == a && o.y == b) {
                    o.obst->setObstacle("../images/broakenwall.png", a, b, i);
                    sleep(450);
                    o.obst->~Obstacle();
                }
            boards[i].destroyWall(a, b);
        }
    }

    auto[c, d] = boards[i].check(1);
    if (c != -1 && d != -1 && boards[i].canDestroyWall(1)) {
        qDebug() << "press F to destroy wall " << c << " " << d << "\n";
        if (event->key() == Qt::Key_F) {
            qDebug() << "f pressed\n";
            for (ObstacleCord o : obstacles_[i])
                if (o.x == c && o.y == d) {
                    o.obst->setObstacle("../images/broakenwall.png", c, d, i);
                    sleep(450);
                    o.obst->~Obstacle();
                }
            boards[i].destroyWall(c, d);
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::finnish &&
        boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::finnish &&
        boards[i].canWin(1) && boards[i].canWin(1)) {
        gameIsFinished = true;
        Message *text = new Message();
        text->setMessage(i);
        text->setPos(500, 400);

        player_->~Player();
        player2_->~Player();
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X(0), boards[i].getCharacterPosition_Y(0)) == Type::door &&
            boards[i].getFieldType(boards[i].getCharacterPosition_X(1), boards[i].getCharacterPosition_Y(1)) == Type::door) {
        qDebug() << "door\n";
        if (boards[i].canOpenDoor(0) && boards[i].canOpenDoor(1))
            changeLocation();
    }
}

void GameBoard::changeLocation() {
    if (currentLocation_ == Location::firstLocation) {
        locationNum = 1;
        setBackgroundBrush(QBrush(QImage("../images/second_location.jpg")));
        scenes[1]->addItem(player_);
        scenes[1]->addItem(player2_);
        scenes[1]->addItem(door_);
        door_->setPos(6 * game->cell_width + start_x, 6 * game->cell_width + start_y);
        boards[1].heroes[0].x = 6;
        boards[1].heroes[0].y = 6;
        boards[1].heroes[1].x = 6;
        boards[1].heroes[1].y = 6;
        player_->setPos(start_x + boards[1].getCharacterPosition_X(0) * cell_width, start_y + boards[1].getCharacterPosition_Y(0) * cell_width);
        player2_->setPos(start_x + boards[1].getCharacterPosition_X(1) * cell_width, start_y + boards[1].getCharacterPosition_Y(1) * cell_width);
        boards[1].changeOneFieldType(6, 6, Type::door);
        setScene(scenes[1]);
        currentLocation_ = Location::secondLocation;
        return;
    }
    if (currentLocation_ == Location::secondLocation) {
        locationNum = 0;
        setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
        door_->setPos(5 * game->cell_width + start_x, 5 * game ->cell_width + start_y);
        scenes[0]->addItem(player_);
        scenes[0]->addItem(player2_);
        boards[1].heroes[0].x = 5;
        boards[1].heroes[0].y = 5;
        boards[1].heroes[1].x = 5;
        boards[1].heroes[1].y = 5;
        player_->setPos(start_x + boards[1].getCharacterPosition_X(0) * cell_width, start_y + boards[1].getCharacterPosition_Y(0) * cell_width);
        player2_->setPos(start_x + boards[1].getCharacterPosition_X(1) * cell_width, start_y + boards[1].getCharacterPosition_Y(1) * cell_width);
        scenes[0]->addItem(door_);
        setScene(scenes[0]);
        currentLocation_ = Location::firstLocation;
        return;
    }
}
