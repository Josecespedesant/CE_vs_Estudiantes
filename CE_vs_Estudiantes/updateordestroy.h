#ifndef UPDATEORDESTROY_H
#define UPDATEORDESTROY_H

#include <QDialog>
#include "player.h"
#include "QLabel"
#include "parcela.h"

namespace Ui {
class UpdateOrDestroy;
}

class UpdateOrDestroy : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateOrDestroy(QWidget *parent = 0,Parcela* button = 0, Player* player = 0, QLabel* creditos = 0);
    ~UpdateOrDestroy();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::UpdateOrDestroy *ui;
    Parcela *button;
    Player *player;
    QLabel *creditos;

};

#endif // UPDATEORDESTROY_H
