#ifndef CANTADDTOWER_H
#define CANTADDTOWER_H

#include <QDialog>

namespace Ui {
class CantAddTower;
}

class CantAddTower : public QDialog
{
    Q_OBJECT

public:
    explicit CantAddTower(QWidget *parent = 0);
    ~CantAddTower();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CantAddTower *ui;
};

#endif // CANTADDTOWER_H
