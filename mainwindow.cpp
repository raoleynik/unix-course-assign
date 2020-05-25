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
    lwindow = new Conv_Length();
    connect(lwindow, &Conv_Length::firstWindow, this, &MainWindow::show);
    mwindow = new conv_mass();
    connect(mwindow, &conv_mass::secondWindow,this,&MainWindow::show);
    twindow =new conv_temp();
    connect(twindow,&conv_temp::thirdWindow,this,&MainWindow::show);
    t2window = new conv_time();
    connect(t2window,&conv_time::fourthWindow,this,&MainWindow::show);
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
    lwindow->show();

}
// Переход в конвертер температуры
void MainWindow::on_PushButton_Conv_Temp_Open_clicked()
{
    hide();
    twindow->show();
}
// Переход в конвертер массы
void MainWindow::on_PushButton_Conv_Mass_Open_clicked()
{
    hide();
    mwindow->show();
}
//Переход в конвертер времени

void MainWindow::on_PushButton_Conv_Time_Open_clicked()
{
    hide();
    t2window->show();
}
