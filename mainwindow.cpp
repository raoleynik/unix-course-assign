#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QMainWindow>
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
// Выход из приложения
void MainWindow::on_PushButton_exit_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",
                                                            QMessageBox::No| QMessageBox::Yes);
    if (exit == QMessageBox::Yes){
        QApplication::quit();
    }
}
// Переход в конвертер длины
void MainWindow::on_PushButton_Conv_Length_Open_clicked()
{
    hide();
    lwindow = new Conv_Length();
    lwindow->show();

}
// Переход в конвертер температуры
void MainWindow::on_PushButton_Conv_Temp_Open_clicked()
{
    hide();
    twindow = new conv_temp();
    twindow->show();
}
// Переход в конвертер массы
void MainWindow::on_PushButton_Conv_Mass_Open_clicked()
{
    hide();
    mwindow = new conv_mass();
    mwindow->show();
}
//Переход в конвертер объёма
void MainWindow::on_PushButton_Conv_Volume_Open_clicked()
{
    hide();
    vwindow = new conv_volume();
    vwindow->show();
}

