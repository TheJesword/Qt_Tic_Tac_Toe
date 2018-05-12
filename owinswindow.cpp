#include "owinswindow.h"
#include "ui_owinswindow.h"

OWinsWindow::OWinsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OWinsWindow)
{
    ui->setupUi(this);
    connect(ui->closeButton, SIGNAL (clicked()), this, SLOT(close()));
}

OWinsWindow::~OWinsWindow()
{
    delete ui;
}
