#include "borrowdialog.h"
#include "ui_borrowdialog.h"
#include <QMessageBox>
#include <QDateTime>

borrowDialog::borrowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::borrowDialog)
{
    ui->setupUi(this);
    int w = ui->label_htlt->width()*7;
    int h = ui->label_htlt->height()*7;
    QPixmap pix(":/resources/hanh-trang-lap-trinh-tac-gia-vu-cong-tan-tai.jpg");
    ui->label_htlt->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix2(":/resources/the-art-of-programming-donald-knuth.jpg");
    ui->label_programmingart->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix3(":/resources/python-machine-learning.jpg");
    ui->label_python->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix4(":/resources/a-brief-history-of-time.jpg");
    ui->label_historyoftime->setPixmap(pix4.scaled(w,h,Qt::KeepAspectRatio));
}

borrowDialog::~borrowDialog()
{
    delete ui;
}

void borrowDialog::on_pushButton_clicked()
{
    QString result = "";
    if (!ui->checkBox_htlt->isChecked() && !ui->checkBox_programmingart->isChecked() && !ui->checkBox_python->isChecked() && !ui->checkBox_historyoftime->isChecked())
        result = "You have borrowed no book.";
    else
    {
        result = "You have borrowed: ";
        if (ui->checkBox_htlt->isChecked())
        {
            result += ui->checkBox_htlt->text() + "; ";
        }
        if (ui->checkBox_programmingart->isChecked())
        {
            result += ui->checkBox_programmingart->text() + "; ";
        }
        if (ui->checkBox_python->isChecked())
        {
            result += ui->checkBox_python->text() + "; ";
        }
        if (ui->checkBox_historyoftime->isChecked())
        {
            result += ui->checkBox_historyoftime->text() + "; ";
        }
    }

    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    result += "\n\nAt " + time.toString("hh:mm") + ", " + date.toString("MM/dd/yyyy");

    QMessageBox::information(this, "Borrow", result);
}
