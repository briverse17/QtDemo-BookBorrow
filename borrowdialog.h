#ifndef BORROWDIALOG_H
#define BORROWDIALOG_H

#include <QDialog>

namespace Ui {
class borrowDialog;
}

class borrowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit borrowDialog(QWidget *parent = nullptr);
    ~borrowDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::borrowDialog *ui;
};

#endif // BORROWDIALOG_H
