#ifndef GRID_H
#define GRID_H

#include <QDialog>

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
    void handleButton(QPushButton*);

private:
    Ui::Grid *ui;
};

#endif // GRID_H
