#include "conv_mass.h"
#include "ui_conv_mass.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <string>
conv_mass::conv_mass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conv_mass)
{
    ui->setupUi(this);
    ui->LV1->setCurrentRow(1);
    ui->LV2->setCurrentRow(1);
    QListWidgetItem *lv1item1 = new QListWidgetItem("Тонна");
    ui->LV1->addItem(lv1item1);
    QListWidgetItem *lv1item2 = new QListWidgetItem("Килограмм");
    ui->LV1->addItem(lv1item2);
    QListWidgetItem *lv1item3 = new QListWidgetItem("Грамм");
    ui->LV1->addItem(lv1item3);
    QListWidgetItem *lv1item4 = new QListWidgetItem("Фунт");
    ui->LV1->addItem(lv1item4);
    QListWidgetItem *lv2item1 = new QListWidgetItem("Тонна");
    ui->LV2->addItem(lv2item1);
    QListWidgetItem *lv2item2 = new QListWidgetItem("Килограмм");
    ui->LV2->addItem(lv2item2);
    QListWidgetItem *lv2item3 = new QListWidgetItem("Грамм");
    ui->LV2->addItem(lv2item3);
    QListWidgetItem *lv2item4 = new QListWidgetItem("Фунт");
    ui->LV2->addItem(lv2item4);
}

conv_mass::~conv_mass()
{
    delete ui;
}


void conv_mass::on_mass_exit_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",
                                                            QMessageBox::No| QMessageBox::Yes);
    if (exit == QMessageBox::Yes){
        QApplication::exit();
    }
}

void conv_mass::on_m_return_clicked()
{
    hide();
    emit secondWindow();
}

void conv_mass::on_m_convert_clicked()
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
    }else if(first == "Тонна" and second == "Килограмм"){
        ui->result->setNum(d_input_value * 1000);
    }else if(first == "Тонна" and second == "Грамм"){
        ui->result->setNum(d_input_value * 1000000);
    }else if(first == "Тона" and second == "Фунт"){
        ui->result->setNum(d_input_value * 2205);
    }else if(first == "Килограмм" and second == "Тонна"){
        ui->result->setNum(d_input_value / 1000);
    }else if(first == "Килограмм" and second == "Грамм"){
        ui->result->setNum(d_input_value * 1000);
    }else if(first == "Килограмм" and second == "Фунт"){
        ui->result->setNum(d_input_value * 2.205);
    }else if (first == "Грамм" and second == "Тонна"){
        ui->result->setNum(d_input_value / 1000000);
    }else if(first == "Грамм" and second == "Килограмм"){
        ui->result->setNum(d_input_value / 1000);
    }else if(first == "Грамм" and second == "Фунт"){
        ui->result->setNum(d_input_value / 454);
    }else if(first == "Фунт" and second == "Тонна"){
        ui->result->setNum(d_input_value / 2205);
    }else if(first == "Фунт" and second == "Килограмм"){
        ui->result->setNum(d_input_value / 2.205);
    }else if(first == "Фунт" and second == "Грамм"){
        ui->result->setNum(d_input_value * 454);
    }else if(ui->lineEdit->text() == NULL){
        QMessageBox::warning(this,"Внимание!", "Введите начальное значение!",QMessageBox::Ok,QMessageBox::Ok);
    }
}
