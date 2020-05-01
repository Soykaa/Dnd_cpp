#include <QDebug>
#include <QApplication>
#include <QGraphicsItem>
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


void GameBoard::makeGift(int giftNum, int x, int y, int location) {
    gifts_[giftNum].gift = new Gift();
    gifts_[giftNum].gift->setGift(x, y, location);
    gifts_[giftNum].x = x;
    gifts_[giftNum].y = y;
    boards[location].changeOneFieldType(x, y, Type::gift);
}

void GameBoard::makeGame() {
    player_->setPlayer("../images/dragonborn.png");
    player_->setPos(0, 0);
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    scenes[0]->addItem(player_);
    player2_->setPlayer("../images/character.png");
    player2_->setPos(0, 0);
    player2_->setFlag(QGraphicsItem::ItemIsFocusable);
    player2_->setFocus();
    scenes[0]->addItem(player2_);
    makeDoor(5, 5);
    makeGifts(3, 1);
    makeObstacles(30, 0);
    makeObstacles(45, 1);
    show();
}


void GameBoard::makeGifts(int amount, int location) {
    gifts_.resize(amount);
    for (int i = 0; i < amount; i++) {
        int x = rand() % boards[location].getAmountOfEncounters();
        int y = rand() % boards[location].getAmountOfEncounters();
        if (boards[location].getFieldType(x, y) == Type::emptyField)
            makeGift(i, x, y, location);
    }
}

void GameBoard::makeObstacle(int obstNum, int x, int y, int location) {
    obstacles_[obstNum].obst = new Obstacle();
    obstacles_[obstNum].obst->setObstacle(x, y, location);
    obstacles_[obstNum].x = x;
    obstacles_[obstNum].y = y;
    boards[location].changeOneFieldType(x, y, Type::obstacle);
}

void GameBoard::makeObstacles(int amount, int location) {
    obstacles_.resize(amount);
    for (int i = 0; i < amount; i++) {
        int x = rand() % boards[location].getAmountOfEncounters();
        int y = rand() % boards[location].getAmountOfEncounters();
        if (boards[location].getFieldType(x, y) == Type::emptyField)
            makeObstacle(i, x, y, location);
    }
}

void GameBoard::makeDoor(int x, int y) {
    door_ = new Door();
    door_->setDoor();
    door_->setPos(x * game->cell_width, y * game->cell_width);
    scenes[0]->addItem(door_);
    boards[0].changeOneFieldType(x, y, Type::door);
    boards[1].changeOneFieldType(x + 1, y + 1, Type::door);
}

void GameBoard::keyPressEvent(QKeyEvent *event) {
    int i = locationNum;
    qDebug() << "dext " << boards[i].h1->cs_.getDexterity() << "\n";
    qDebug() << i << "\n";
    if (event->key() == Qt::Key_Any) {
        QApplication::quit();
    }
    if (gameIsFinished)
        return;

    if (event->key() == Qt::Key_Left) {
            boards[i].makeTurn_1(Direction::left);
    }
    if (event->key() == Qt::Key_Right) {
            boards[i].makeTurn_1(Direction::right);
    }
    if (event->key() == Qt::Key_Up) {
            boards[i].makeTurn_1(Direction::up);
    }
    if (event->key() == Qt::Key_Down) {
            boards[i].makeTurn_1(Direction::down);
    }


    if (event->key() == Qt::Key_A) {
            boards[i].makeTurn_2(Direction::left);
    }
    if (event->key() == Qt::Key_D) {
            boards[i].makeTurn_2(Direction::right);
    }
    if (event->key() == Qt::Key_W) {
            boards[i].makeTurn_2(Direction::up);
    }
    if (event->key() == Qt::Key_S) {
            boards[i].makeTurn_2(Direction::down);
    }
    int x_1 = boards[i].getCharacterPosition_X_1();
    int y_1 = boards[i].getCharacterPosition_Y_1();
    player_->setPos(start_x + x_1 * cell_width, start_y + y_1 * cell_width);

    int x_2 = boards[i].getCharacterPosition_X_2();
    int y_2 = boards[i].getCharacterPosition_Y_2();
    player2_->setPos(start_x + x_2 * cell_width, start_y + y_2 * cell_width);


    if (boards[i].getFieldType(boards[i].getCharacterPosition_X_1(), boards[i].getCharacterPosition_Y_1()) == Type::finnish) {
        qDebug() << "finnish\n";
    }
    if (boards[i].getFieldType(boards[i].getCharacterPosition_X_1(), boards[i].getCharacterPosition_Y_1()) == Type::gift) {
        boards[i].takeGift_1(18);
        for (GiftCord g : gifts_) {
            if (g.x == boards[i].getCharacterPosition_X_1() && g.y == boards[i].getCharacterPosition_Y_1())
                g.gift->~Gift();
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X_2(), boards[i].getCharacterPosition_Y_2()) == Type::gift) {
        boards[i].takeGift_2(18);
        for (GiftCord g : gifts_) {
            if (g.x == boards[i].getCharacterPosition_X_2() && g.y == boards[i].getCharacterPosition_Y_2())
                g.gift->~Gift();
        }
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X_1(), boards[i].getCharacterPosition_Y_1()) == Type::finnish and boards[i].canWin_1()) {
        gameIsFinished = true;
        Message *text = new Message();
        text->setMessage(i);
        text->setPos(280, 400);
        player_->~Player();
        player2_->~Player();
    } else if (boards[i].getFieldType(boards[i].getCharacterPosition_X_2(), boards[i].getCharacterPosition_Y_2()) == Type::finnish and boards[i].canWin_2()) {
        gameIsFinished = true;
        Message *text = new Message();
        text->setMessage(i);
        text->setPos(280, 400);
        player_->~Player();
        player2_->~Player();
    }

    if (boards[i].getFieldType(boards[i].getCharacterPosition_X_1(), boards[i].getCharacterPosition_Y_1()) == Type::door &&
            boards[i].getFieldType(boards[i].getCharacterPosition_X_2(), boards[i].getCharacterPosition_Y_2()) == Type::door) {
        qDebug() << "door\n";
        changeLocation();
    }
}

void GameBoard::changeLocation() {
    if (currentLocation_ == Location::firstLocation) {
        locationNum = 1;
        boards[1].h1 = boards[0].h1;
        boards[1].h2 = boards[0].h2;
        setBackgroundBrush(QBrush(QImage("../images/forest.png")));
        scenes[1]->addItem(player_);
        scenes[1]->addItem(player2_);
        scenes[1]->addItem(door_);
        door_->setPos(6 * game->cell_width, 6 * game->cell_width);
        boards[1].characterPosition_X_1 = 6;
        boards[1].characterPosition_X_2 = 6;
        boards[1].characterPosition_Y_1 = 6;
        boards[1].characterPosition_Y_2 = 6;
        player_->setPos(start_x + boards[1].getCharacterPosition_X_1() * cell_width, start_y + boards[1].getCharacterPosition_Y_1() * cell_width);
        player2_->setPos(start_x + boards[1].getCharacterPosition_X_2() * cell_width, start_y + boards[1].getCharacterPosition_Y_2() * cell_width);
        boards[1].changeOneFieldType(6, 6, Type::door);
        setScene(scenes[1]);
        currentLocation_ = Location::secondLocation;
        return;
    }
    if (currentLocation_ == Location::secondLocation) {
        boards[0].h1 = boards[1].h1;
        boards[0].h2 = boards[1].h2;
        locationNum = 0;
        setBackgroundBrush(QBrush(QImage("../images/new_background.png")));
        door_->setPos(5 * game->cell_width, 5 * game ->cell_width);
        scenes[0]->addItem(player_);
        scenes[0]->addItem(player2_);
        boards[1].characterPosition_X_1 = 5;
        boards[1].characterPosition_X_2 = 5;
        boards[1].characterPosition_Y_1 = 5;
        boards[1].characterPosition_Y_2 = 5;
        player_->setPos(start_x + boards[1].getCharacterPosition_X_1() * cell_width, start_y + boards[1].getCharacterPosition_Y_1() * cell_width);
        player2_->setPos(start_x + boards[1].getCharacterPosition_X_2() * cell_width, start_y + boards[1].getCharacterPosition_Y_2() * cell_width);
        scenes[0]->addItem(door_);
        setScene(scenes[0]);
        currentLocation_ = Location::firstLocation;
        return;
    }
}
