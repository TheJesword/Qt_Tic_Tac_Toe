#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include "xwinswindow.h"
#include "owinswindow.h"
#include "drawwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startGame();
    bool nextPlayer();
    void displayWins();
    void checkWin();
    void clearBoard();
    void displayPlayer();
    unsigned int addxWin();
    unsigned int addoWin();
    unsigned int addDraw();

private slots:
    void topLeftButtonClick();
    void topMiddleButtonClick();
    void topRightButtonClick();
    void leftButtonClick();
    void middleButtonClick();
    void rightButtonClick();
    void bottomLeftButtonClick();
    void bottomMiddleButtonClick();
    void bottomRightButtonClick();

private:
    Ui::MainWindow *ui;
    XWinsWindow xWindow;
    OWinsWindow oWindow;
    DrawWindow drawWindow;

    bool nextPlayerTurn;
    unsigned int xWins;
    unsigned int oWins;
    unsigned int draws;

};

#endif // MAINWINDOW_H
