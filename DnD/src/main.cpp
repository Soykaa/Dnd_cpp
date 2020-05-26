#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "include/chargen.h"
#include "include/board.h"
#include "include/game_menu.h"
#include "include/game_board.h"


GameBoard *game;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GameWindow window;
    window.resize(750, 750);
    window.setWindowTitle("Dungeon and dragons");
    window.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, window.size(), qApp->desktop()->availableGeometry()));
    window.show();
    return app.exec();
}
