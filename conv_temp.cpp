#include "conv_temp.h"
#include "ui_conv_temp.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <string>
conv_temp::conv_temp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conv_temp)
{
    ui->setupUi(this);
    ui->LV1->setCurrentRow(1);
    ui->LV2->setCurrentRow(1);
    QListWidgetItem *lv1item1 = new QListWidgetItem("Цельсий");
    ui->LV1->addItem(lv1item1);
    QListWidgetItem *lv1item2 = new QListWidgetItem("Кельвин");
    ui->LV1->addItem(lv1item2);
    QListWidgetItem *lv1item3 = new QListWidgetItem("Фаренгейт");
    ui->LV1->addItem(lv1item3);
    QListWidgetItem *lv2item1 = new QListWidgetItem("Цельсий");
    ui->LV2->addItem(lv2item1);
    QListWidgetItem *lv2item2 = new QListWidgetItem("Кeльвин");
    ui->LV2->addItem(lv2item2);
    QListWidgetItem *lv2item3 = new QListWidgetItem("Фаренгeйт");
    ui->LV2->addItem(lv2item3);

}

conv_temp::~conv_temp()
{
    delete ui;
}

void conv_temp::on_temp_exit_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",
                                                            QMessageBox::No| QMessageBox::Yes);
    if (exit == QMessageBox::Yes){
        QApplication::exit();
    }
}

void conv_temp::on_t_return_clicked()
{
    hide();
    emit thirdWindow();
}
void conv_temp::on_t_convert_clicked()
{
    QString first = ui->LV1->currentItem()->text();
    QString second = ui->LV2->currentItem()->text();
    QString s_input_value = ui->lineEdit->text();
    if (s_input_value.contains(".")){
        s_input_value.replace(",",".");
    }
    double d_input_value = s_input_value.toDouble();
    if (first==second){
        ui->result->setNum(d_input_value);
    }else if(first == "Цельсий" and second == "Фаренгейт"){
        ui->result->setNum(d_input_value*9/5+32);
    }else if(first == "Цельсий" and second == "Кельвин"){
        ui->result->setNum(d_input_value+273.15);
    }else if (first == "Кельвин" and second == "Цельсий"){
        ui->result->setNum(d_input_value-273.15);
    }else if(first == "Кельвин" and second =="Фаренгейт"){
        ui->result->setNum((d_input_value-273.15)*9/5+32);
    }else if(first == "Фаренгейт" and second == "Цельсий"){
        ui->result->setNum((d_input_value-32)*5/9);
    }else if(first == "Фаренгейт" and second == "Кельвин"){
        ui->result->setNum((d_input_value-32)*5/9+273.15);
    }else if(ui->lineEdit->text() == NULL){
        QMessageBox::warning(this,"Внимание!", "Введите начальное значение!",QMessageBox::Ok,QMessageBox::Ok);
    }
}


