#ifndef END_H
#define END_H

#include <QDialog>

namespace Ui {
class End;
}
/**
 * @brief Clase que indica que se terminó la partida
 */
class End : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la clase End
     * @param parent
     */
    explicit End(QWidget *parent = 0);
    ~End();

private slots:
    /**
     * @brief Aceptar que terminó la partida
     */
    void on_pushButton_clicked();

private:
    Ui::End *ui;
};

#endif // END_H
