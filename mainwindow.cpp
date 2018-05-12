#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initializing the values in the constructor
    xWins = 0;
    oWins = 0;
    draws = 0;
    nextPlayerTurn = false;

    // This takes you to the function where
    // all of the buttons can be pressed
    startGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    // Clearing everything on the board to start the game
    clearBoard();

    // Signal and slots for when the user presses the button
    // to play there mark on their turn;

    // ------------------- Top Row Buttons ------------------------------------------
    connect(ui->topLeftButton, SIGNAL (clicked()), this, SLOT(topLeftButtonClick()));
    connect(ui->topMiddleButton, SIGNAL (clicked()), this, SLOT(topMiddleButtonClick()));
    connect(ui->topRightButton, SIGNAL (clicked()), this, SLOT(topRightButtonClick()));

    // ------------------- Middle Row Buttons ---------------------------------------
    connect(ui->leftButton, SIGNAL (clicked()), this, SLOT(leftButtonClick()));
    connect(ui->middleButton, SIGNAL (clicked()), this, SLOT(middleButtonClick()));
    connect(ui->rightButton, SIGNAL (clicked()), this, SLOT(rightButtonClick()));

    // ------------------- Bottom Row Buttons ---------------------------------------
    connect(ui->bottomLeftButton, SIGNAL (clicked()), this, SLOT(bottomLeftButtonClick()));
    connect(ui->bottomMiddleButton, SIGNAL (clicked()), this, SLOT(bottomMiddleButtonClick()));
    connect(ui->bottomRightButton, SIGNAL (clicked()), this, SLOT(bottomRightButtonClick()));

    displayPlayer();
    displayWins();
}

// ------- Top Row -----------------
void MainWindow::topLeftButtonClick()
{
    ui->topLeftButton->hide();
    if(!nextPlayer())
    {
        ui->topLeftLabel->setText("X");
    }
    else
    {
        ui->topLeftLabel->setText("O");
    }
     checkWin();
     displayPlayer();
}

void MainWindow::topMiddleButtonClick()
{
    ui->topMiddleButton->hide();
    if(!nextPlayer())
    {
        ui->topMiddleLabel->setText("X");
    }
    else
    {
        ui->topMiddleLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}

void MainWindow::topRightButtonClick()
{
    ui->topRightButton->hide();
    if(!nextPlayer())
    {
        ui->topRightLabel->setText("X");
    }
    else
    {
        ui->topRightLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}
//-----------------------------------

// ------- Middle Row -----------------
void MainWindow::leftButtonClick()
{
    ui->leftButton->hide();
    if(!nextPlayer())
    {
        ui->leftLabel->setText("X");
    }
    else
    {
        ui->leftLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}

void MainWindow::middleButtonClick()
{
    ui->middleButton->hide();
    if(!nextPlayer())
    {
        ui->middleLabel->setText("X");
    }
    else
    {
        ui->middleLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}

void MainWindow::rightButtonClick()
{
    ui->rightButton->hide();
    if(!nextPlayer())
    {
        ui->rightLabel->setText("X");
    }
    else
    {
        ui->rightLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}
//-----------------------------------

// ------- Bottom Row -----------------
void MainWindow::bottomLeftButtonClick()
{
    ui->bottomLeftButton->hide();
    if(!nextPlayer())
    {
        ui->bottomLeftLabel->setText("X");
    }
    else
    {
        ui->bottomLeftLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}

void MainWindow::bottomMiddleButtonClick()
{
    ui->bottomMiddleButton->hide();
    if(!nextPlayer())
    {
        ui->bottomMiddleLabel->setText("X");
    }
    else
    {
        ui->bottomMiddleLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}

void MainWindow::bottomRightButtonClick()
{
    ui->bottomRightButton->hide();
    if(!nextPlayer())
    {
        ui->bottomRightLabel->setText("X");
    }
    else
    {
        ui->bottomRightLabel->setText("O");
    }
    checkWin();
    displayPlayer();
}
//-----------------------------------

void MainWindow::displayWins()
{
    ui->xWinsLabel->setText(QString::number(xWins));
    ui->oWinsLabel->setText(QString::number(oWins));
    ui->drawLabel->setText(QString::number(draws));
}

void MainWindow::displayPlayer()
{
    if(!nextPlayerTurn)
    {
        ui->playerLabel->setText("X");
    }
    else
    {
        ui->playerLabel->setText("O");
    }
}

unsigned int MainWindow::addxWin()
{
    xWins+=1;

    return xWins;
}

unsigned int MainWindow::addoWin()
{
    oWins+=1;

    return oWins;
}

unsigned int MainWindow::addDraw()
{
    draws+=1;

    return draws;
}

bool MainWindow::nextPlayer()
{
    if(!nextPlayerTurn)
    {
        nextPlayerTurn = true;
        return false;
    }
    else
    {
        nextPlayerTurn = false;
        return true;
    }
}

void MainWindow::checkWin()
{
    if((ui->bottomLeftLabel->text() == "X" && ui->bottomMiddleLabel->text() == "X" && ui->bottomRightLabel->text() == "X")
            || (ui->topLeftLabel->text() == "X" && ui->topMiddleLabel->text() == "X" && ui->topRightLabel->text() == "X")
            || (ui->leftLabel->text() == "X" && ui->middleLabel->text() == "X" && ui->rightLabel->text() == "X")
            || (ui->topLeftLabel->text() == "X" && ui->leftLabel->text() == "X" && ui->bottomLeftLabel->text() == "X")
            || (ui->topMiddleLabel->text() == "X" && ui->middleLabel->text() == "X" && ui->bottomMiddleLabel->text() == "X")
            || (ui->topRightLabel->text() == "X" && ui->rightLabel->text() == "X" && ui->bottomRightLabel->text() == "X")
            || (ui->topLeftLabel->text() == "X" && ui->middleLabel->text() == "X" && ui->bottomRightLabel->text() == "X")
            || (ui->topRightLabel->text() == "X" && ui->middleLabel->text() == "X" && ui->bottomLeftLabel->text() == "X"))
    {
        addxWin();
        displayWins();
        xWindow.show();
        clearBoard();
    }
    else if((ui->bottomLeftLabel->text() == "O" && ui->bottomMiddleLabel->text() == "O" && ui->bottomRightLabel->text() == "O")
            || (ui->topLeftLabel->text() == "O" && ui->topMiddleLabel->text() == "O" && ui->topRightLabel->text() == "O")
            || (ui->leftLabel->text() == "O" && ui->middleLabel->text() == "O" && ui->rightLabel->text() == "O")
            || (ui->topLeftLabel->text() == "O" && ui->leftLabel->text() == "O" && ui->bottomLeftLabel->text() == "O")
            || (ui->topMiddleLabel->text() == "O" && ui->middleLabel->text() == "O" && ui->bottomMiddleLabel->text() == "O")
            || (ui->topRightLabel->text() == "O" && ui->rightLabel->text() == "O" && ui->bottomRightLabel->text() == "O")
            || (ui->topLeftLabel->text() == "O" && ui->middleLabel->text() == "O" && ui->bottomRightLabel->text() == "O")
            || (ui->topRightLabel->text() == "O" && ui->middleLabel->text() == "O" && ui->bottomLeftLabel->text() == "O"))
    {
        addoWin();
        displayWins();
        oWindow.show();
        clearBoard();
    }
    else if(ui->topLeftLabel->text() != "" && ui->topMiddleLabel->text() != "" && ui->topRightLabel->text() != "" &&
            ui->leftLabel->text() != "" && ui->middleLabel->text() != "" && ui->rightLabel->text() != "" &&
            ui->bottomLeftLabel->text() != "" && ui->bottomMiddleLabel->text() != "" && ui->bottomRightLabel->text() != "")
    {
        addDraw();
        displayWins();
        drawWindow.show();
        clearBoard();
    }
}

void MainWindow::clearBoard()
{
    // Clearing the board of X and O's
    ui->topLeftLabel->setText("");
    ui->topMiddleLabel->setText("");
    ui->topRightLabel->setText("");

    ui->leftLabel->setText("");
    ui->middleLabel->setText("");
    ui->rightLabel->setText("");

    ui->bottomLeftLabel->setText("");
    ui->bottomMiddleLabel->setText("");
    ui->bottomRightLabel->setText("");

    // Showing all of the buttons again to play
    ui->topLeftButton->show();
    ui->topMiddleButton->show();
    ui->topRightButton->show();

    ui->rightButton->show();
    ui->middleButton->show();
    ui->leftButton->show();

    ui->bottomLeftButton->show();
    ui->bottomMiddleButton->show();
    ui->bottomRightButton->show();
}

