#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/kmin-logo.png");
    ui->label_logo->setPixmap(pix.scaled(300,200,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//signal: click()
//slot: on_pushButton_login_clicked()

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "kmin" && password == "qtdemo")
    {
        QMessageBox::information(this, "Login", "Login successfully!");
        hide();
        borrow = new borrowDialog(this);
        borrow->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Failed to login!");
    }
}
