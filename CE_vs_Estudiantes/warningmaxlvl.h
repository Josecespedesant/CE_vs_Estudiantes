#ifndef WARNINGMAXLVL_H
#define WARNINGMAXLVL_H

#include <QDialog>

namespace Ui {
class WarningMaxLvl;
}

/**
 * @brief The WarningMaxLvl class
 */
class WarningMaxLvl : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief WarningMaxLvl
     * @param parent
     */
    explicit WarningMaxLvl(QWidget *parent = 0);
    ~WarningMaxLvl();

private slots:
    /**
     * @brief Accept
     */
    void on_pushButton_clicked();

private:
    Ui::WarningMaxLvl *ui;
};

#endif // WARNINGMAXLVL_H
