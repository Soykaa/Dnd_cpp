#ifndef DND_CONNECTION_WITH_PLAYER_H
#define DND_CONNECTION_WITH_PLAYER_H

#include <QGraphicsPixmapItem>
#include <map>
#include <vector>
#include <string>

class Window : public QGraphicsPixmapItem {
public:
    explicit Window(QGraphicsItem *parent = 0);
    void setWindow(const QString str, int locationNum);
};

class Master : public QGraphicsPixmapItem {
public:
    explicit Master(QGraphicsItem *parent = 0);
    void setMaster(const QString str, int locationNum);
};

class WindowForText : public QGraphicsPixmapItem {
public:
    explicit WindowForText(QGraphicsItem *parent = 0);
    void setWindowForText(const QString str, int locationNum);
};

class WindowForText_D : public QGraphicsPixmapItem {
public:
    explicit WindowForText_D(QGraphicsItem *parent = 0);
    void setWindowForText_D(const QString str, int locationNum);
};

class MessForPlayer : public QGraphicsTextItem {
public:
    explicit MessForPlayer(int locationNum, QGraphicsItem *parent = 0);
    void setMessForPlayer(int num, int x, int y, int locationNum);
    void setMessForPlayer(const std::string, int x, int y, int locationNum);
private:
    std::vector<QString> init_messages;
    std::map<std::string, QString> action_messages;
};


#endif //DND_KEY_H
