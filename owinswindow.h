#ifndef OWINSWINDOW_H
#define OWINSWINDOW_H

#include <QDialog>

namespace Ui {
class OWinsWindow;
}

class OWinsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OWinsWindow(QWidget *parent = 0);
    ~OWinsWindow();

private:
    Ui::OWinsWindow *ui;
};

#endif // OWINSWINDOW_H
