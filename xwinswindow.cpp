#include "xwinswindow.h"
#include "ui_xwinswindow.h"

XWinsWindow::XWinsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XWinsWindow)
{
    ui->setupUi(this);
    connect(ui->closeButton, SIGNAL (clicked()), this, SLOT(close()));
}

XWinsWindow::~XWinsWindow()
{
    delete ui;
}
