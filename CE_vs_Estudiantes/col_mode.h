#ifndef COL_MODE_H
#define COL_MODE_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class col_mode;
}
/**
 * @brief Clase que permite el modo aprobacion colectiva
 */
class col_mode : public QDialog
{
    Q_OBJECT

public:
    explicit col_mode(QWidget *parent = 0, int*max = 0);
    ~col_mode();

private slots:
    /**
     * @brief Se ingreso la cantidad de oleadas
     */
    void on_pushButton_clicked();

private:
    Ui::col_mode *ui;

    int* max;

    /**
     * @brief Saber si el texto es un numero
     * @param text
     * @return true or false
     */
    bool checkInt(QLineEdit *text);
};

#endif // COL_MODE_H
