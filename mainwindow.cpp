#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "conv_length.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PushButton_exit_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",
                                                            QMessageBox::No| QMessageBox::Yes);
    if (exit == QMessageBox::Yes){
        QApplication::quit();
    }
}

void MainWindow::on_PushButton_Conv_Length_Open_clicked()
{
    Conv_Length c_l;
    c_l.show();
}
