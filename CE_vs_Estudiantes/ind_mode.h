#ifndef IND_MODE_H
#define IND_MODE_H

#include <QDialog>

namespace Ui {
class ind_mode;
}

/**
 * @brief Aprobación individual
 */
class ind_mode : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor aprob individual
     * @param parent
     */
    explicit ind_mode(QWidget *parent = 0);
    ~ind_mode();

private slots:
    /**
     * @brief Aceptar
     */
    void on_pushButton_clicked();

private:
    Ui::ind_mode *ui;
};

#endif // IND_MODE_H
