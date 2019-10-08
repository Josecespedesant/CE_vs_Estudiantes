#ifndef WARNINGMAXLVL_H
#define WARNINGMAXLVL_H

#include <QDialog>

namespace Ui {
class WarningMaxLvl;
}

class WarningMaxLvl : public QDialog
{
    Q_OBJECT

public:
    explicit WarningMaxLvl(QWidget *parent = 0);
    ~WarningMaxLvl();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WarningMaxLvl *ui;
};

#endif // WARNINGMAXLVL_H
