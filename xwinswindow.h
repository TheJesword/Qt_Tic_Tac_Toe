#ifndef XWINSWINDOW_H
#define XWINSWINDOW_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class XWinsWindow;
}

class XWinsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit XWinsWindow(QWidget *parent = 0);
    ~XWinsWindow();

private:
    Ui::XWinsWindow *ui;
    QPushButton closeButton;

};

#endif // XWINSWINDOW_H
