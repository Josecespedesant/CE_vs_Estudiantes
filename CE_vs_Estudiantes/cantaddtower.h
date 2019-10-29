#ifndef CANTADDTOWER_H
#define CANTADDTOWER_H

#include <QDialog>


namespace Ui {
class CantAddTower;
}

/**
 * @brief Clase que indica que no se puede añadir esa torre
 */
class CantAddTower : public QDialog
{
    Q_OBJECT

public:
    explicit CantAddTower(QWidget *parent = 0);
    ~CantAddTower();

private slots:
    /**
     * @brief Boton de ok
     */
    void on_pushButton_clicked();

private:
    Ui::CantAddTower *ui;
};

#endif // CANTADDTOWER_H
