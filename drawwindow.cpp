#include "drawwindow.h"
#include "ui_drawwindow.h"

DrawWindow::DrawWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow)
{
    ui->setupUi(this);
    connect(ui->closeButton, SIGNAL (clicked()), this, SLOT(close()));
}

DrawWindow::~DrawWindow()
{
    delete ui;
}
