#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>

namespace Ui {
class DrawWindow;
}

class DrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DrawWindow(QWidget *parent = 0);
    ~DrawWindow();

private:
    Ui::DrawWindow *ui;
};

#endif // DRAWWINDOW_H
