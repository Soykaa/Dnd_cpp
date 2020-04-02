#ifndef GAMEWINDOW_H_INCLUDE
#define GAMEWINDOW_H_INCLUDE

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include "board.h"
#include "game_board.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget {
	Q_OBJECT

public:
	GameWindow(QWidget *parent = nullptr);
	~GameWindow();

private slots:
	//void showGame();
	void on_pushButton_clicked();
	void on_pushButton_3_clicked();

private:
	Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H