#include "include/connectionWithPlayer.h"
#include <QTextEdit>
#include "include/game_board.h"

extern GameBoard *game;

Window::Window(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Window::setWindow(const QString str, int locationNum) {
    setPixmap(QPixmap(str).scaled(game->start_x - game->cell_width, game->window_height));
    setPos(0, 0);
    game->scenes[locationNum]->addItem(this);
}

Master::Master(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void Master::setMaster(const QString str, int locationNum) {
    setPixmap(QPixmap(str));
    setPos(35, 0);
    game->scenes[locationNum]->addItem(this);
}

WindowForText::WindowForText(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void WindowForText::setWindowForText(const QString str, int locationNum) {
    setPixmap(QPixmap(str).scaled(game->start_x - game->cell_width, 350));
    setPos(0, 450);
    game->scenes[locationNum]->addItem(this);
}

WindowForText_D::WindowForText_D(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {}

void WindowForText_D::setWindowForText_D(const QString str, int locationNum) {
    setPixmap(QPixmap(str).scaled(game->window_width, game->extract_height));
    setPos(0, game->window_height);
    game->scenes[locationNum]->addItem(this);
}


MessForPlayer::MessForPlayer(int locationNum, QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    game->scenes[locationNum]->addItem(this);
    init_messages.resize(20);
    init_messages[0] = "<h1> Нажмите пробел, чтобы начать игру </h1>";
    init_messages[1] = "<h1>Приветствую Вас, <br> &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; путники</h1>";
    init_messages[2] = "<h1>&nbsp;&nbsp;Вы забрели в <br>мое подземелье</h1>";
    init_messages[3] = "<h1>&nbsp;&nbsp;Найти выход <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;будет сложно, <br> &nbsp;&nbsp;но вы справитесь <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;если будете <br>действовать сообща</h1>";
    init_messages[4] = "<h1>Я буду помогать вам <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;и <br> &nbsp;&nbsp;давать подсказки</h1>";
    init_messages[5] = "<h1>Вот первая из них: </h1>";
    init_messages[6] = "<h1> &nbsp;&nbsp;&nbsp;&nbsp;Дверь откроется <br> только <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;двумя <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ключами <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;одновременно</h1>";
    init_messages[7] = "<h2>&nbsp;&nbsp;W - вверх, S - вниз <br> A - влево, D - вправо</h2>";
    init_messages[8] = "<h2> Кнопка действий: <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Caps Lock </h2>";
    init_messages[9] = "<h2> &nbsp;&nbsp;&#8593;- вверх, &#8595; - вниз <br> &#8592; - влево, &#8594; - вправо</h2>";
    init_messages[10] = "<h2> Кнопка действий: <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Shift </h2>";
    init_messages[11] = "<h1> УПРАВЛЕНИЕ <br> &nbsp;&nbsp;ИГРОКАМИ </h1>";
    init_messages[12] = "<h1>Молодцы путники.<br> &nbsp;&nbsp;Вы стали ближе<br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;к победе</h1>";
    init_messages[13] = "<h1> &nbsp;&nbsp;Но впереди <br> все еще ждут <br> &nbsp;&nbsp;&nbsp;испытания </h1>";
    init_messages[14] = "<h1> Вы не сможете выйти <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;пока не сразите <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;врага </h1>";
    action_messages["none"] = "";
    action_messages["can open door"] = "<h1>Молодцы, путники. <br>Теперь вы можете <br> открыть дверь</h1>";
    action_messages["open door"] = "<h1>Нажмите пробел, <br> &nbsp;&nbsp;&nbsp;чтобы пройти <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;через дверь</h1>"; // 40, 575
    action_messages["1 break wall left"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 1, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену слева</h1>"; // 20, 575
    action_messages["1 break wall right"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 1, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену справа</h1>";
    action_messages["1 break wall up"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 1, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену ниже</h1>";
    action_messages["1 break wall down"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 1, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену выше</h1>";
    action_messages["2 break wall left"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 2, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену слева</h1>"; // 20, 575
    action_messages["2 break wall right"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 2, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену справа</h1>";
    action_messages["2 break wall up"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 2, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену ниже</h1>";
    action_messages["2 break wall down"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Игрок 2, <br>&nbsp;&nbsp;вы можете сломать <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;стену выше</h1>";
    action_messages["already has"] = "<h1> &nbsp;Не будьте жадными. <br> &nbsp;Больше этих <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;предметов<br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;вам не нужно</h1>";
    action_messages["weak"] = "<h1> &nbsp;&nbsp;&nbsp;&nbsp;Эту стену можно <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;сломать,<br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;но вы еще <br> недостаточно сильны";
    action_messages["need gift"] = "<h1> 3 подарка <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;помогут вам <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;обрести <br> &nbsp;&nbsp;&nbsp;необходимые силы</h1>";
    action_messages["no ropes"] = "<h1> Колодец желаний <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;сломан. <br> У него не хватает <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;веревки </h1>";
    action_messages["can use well"] = "<h1> Теперь вы можете <br> &nbsp;&nbsp;&nbsp;&nbsp;использовать <br> колодец желаний!</h1>";
    action_messages["want increase"] = "<h1> Чтобы увеличить <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;силы <br> &nbsp;&nbsp;нажмите кнопку <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;действий";
    action_messages["increased"] = "<h1> &nbsp;&nbsp;&nbsp;&nbsp;Ваши силы <br> &nbsp;&nbsp;&nbsp;&nbsp;улучшены! <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Вы можете <br> победить врага";
    action_messages["weak2"] = "<h1> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;У вас <br> недостаточно сил <br> &nbsp;&nbsp;чтобы победить <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;врага </h1>";
    action_messages["not enough ropes"] = "<h1> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Вам нужно <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;две веревки <br> чтобы использовать <br> &nbsp;&nbsp;колодец желаний <h1>";
    action_messages["use ropes"] = "<h1>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Нажмите пробел, <br> чтобы использовать <br> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;веревки</h1>";


}

void MessForPlayer::setMessForPlayer(int num, int x, int y, int locationNum) {
    setHtml(init_messages[num]);
    setPos(x, y);
}

void MessForPlayer::setMessForPlayer(const std::string str, int x, int y, int locationNum) {
    setHtml(action_messages[str]);
    setPos(x, y);
}
