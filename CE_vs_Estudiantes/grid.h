#ifndef GRID_H
#define GRID_H

#include <QDialog>
#include <iostream>

namespace Ui {
class Grid;
}

class Grid : public QDialog
{
    Q_OBJECT

public:
    explicit Grid(QWidget *parent = nullptr);
    ~Grid();


private slots:
    void handleButton();

private:
    Ui::Grid *ui;
};

#endif // GRID_H
