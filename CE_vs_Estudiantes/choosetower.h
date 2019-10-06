#ifndef CHOOSETOWER_H
#define CHOOSETOWER_H

#include <QDialog>
#include "player.h"
#include "QLabel"
namespace Ui {
class ChooseTower;
}

class ChooseTower : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseTower(QWidget *parent = nullptr, QPushButton *button = NULL, Player* player = NULL, QLabel* creditos = NULL);
    ~ChooseTower();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ChooseTower *ui;
    QPushButton *button;
    Player* player;
    QLabel* creditos;
};

#endif // CHOOSETOWER_H
