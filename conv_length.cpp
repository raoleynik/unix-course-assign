#include "conv_length.h"
#include "ui_conv_length.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <string>

Conv_Length::Conv_Length(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Conv_Length)
{
    ui->setupUi(this);
    QListWidgetItem *lv1item1 = new QListWidgetItem("Километр");
    ui->LV1->addItem(lv1item1);
    QListWidgetItem *lv1item2 = new QListWidgetItem("Метр");
    ui->LV1->addItem(lv1item2);
    QListWidgetItem *lv1item3 = new QListWidgetItem("Сантиметр");
    ui->LV1->addItem(lv1item3);
    QListWidgetItem *lv1item4 = new QListWidgetItem("Миллиметр");
    ui->LV1->addItem(lv1item4);
    QListWidgetItem *lv1item5 = new QListWidgetItem("Фут");
    ui->LV1->addItem(lv1item5);

    QListWidgetItem *lv2item1 = new QListWidgetItem("Километр");
    ui->LV2->addItem(lv2item1);
    QListWidgetItem *lv2item2 = new QListWidgetItem("Метр");
    ui->LV2->addItem(lv2item2);
    QListWidgetItem *lv2item3 = new QListWidgetItem("Сантиметр");
    ui->LV2->addItem(lv2item3);
    QListWidgetItem *lv2item4 = new QListWidgetItem("Миллиметр");
    ui->LV2->addItem(lv2item4);
    QListWidgetItem *lv2item5 = new QListWidgetItem("Фут");
    ui->LV2->addItem(lv2item5);
}
Conv_Length::~Conv_Length()
{
    delete ui;
}


void Conv_Length::on_length_exit_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",
                                                            QMessageBox::No| QMessageBox::Yes);
    if (exit == QMessageBox::Yes){
        QApplication::exit();
    }
}

void Conv_Length::on_l_return_clicked()
{
    hide();
    emit firstWindow();
}

void Conv_Length::on_l_convert_clicked()
{
    QString first = ui->LV1->currentItem()->text();
    QString second = ui->LV2->currentItem()->text();
    QString s_input_value = ui->lineEdit->text();
    ui->LV1->setCurrentRow(1);
    ui->LV2->setCurrentRow(1);
    if (s_input_value.contains(".")){
        s_input_value.replace(",",".");
    }
    double d_input_value = s_input_value.toDouble();
    if (first==second){
        ui->result->setNum(d_input_value);
    }else if(first == "Километр" and second == "Метр"){
        ui->result->setNum(d_input_value * 1000);
    }else if(first == "Километр" and second == "Сантиметр"){
        ui->result->setNum(d_input_value * 100000);
    }else if(first == "Километр" and second == "Миллиметр"){
        ui->result->setNum(d_input_value * 1000000);
    }else if(first == "Километр" and second == "Фут"){
        ui->result->setNum(d_input_value * 3281);
    }else if(first == "Метр" and second == "Километр"){
        ui->result->setNum(d_input_value / 1000);
    }else if(first == "Метр" and second == "Сантиметр"){
        ui->result->setNum(d_input_value * 100);
    }else if(first == "Метр" and second == "Миллиметр"){
        ui->result->setNum(d_input_value * 1000);
    }else if(first == "Метр" and second == "Фут"){
        ui->result->setNum(d_input_value * 3.281);
    }else if(first == "Сантиметр" and second == "Километр"){
        ui->result->setNum(d_input_value / 100000);
    }else if(first == "Сантиметр" and second == "Метр"){
        ui->result->setNum(d_input_value / 100);
    }else if(first == "Сантиметр" and second == "Миллиметр"){
        ui->result->setNum(d_input_value * 10);
    }else if(first == "Сантиметр" and second == "Фут"){
        ui->result->setNum(d_input_value / 30.48);
    }else if(first == "Миллиметр" and second == "Километр"){
        ui->result->setNum(d_input_value / 1000000);
    }else if(first == "Миллиметр" and second == "Метр"){
        ui->result->setNum(d_input_value / 1000);
    }else if(first == "Миллиметр" and second == "Сантиметр"){
        ui->result->setNum(d_input_value / 10);
    }else if(first == "Миллиметр" and second == "Фут"){
        ui->result->setNum(d_input_value / 305);
    }else if(first == "Фут" and second == "Километр"){
        ui->result->setNum(d_input_value / 3281);
    }else if(first == "Фут" and second == "Метр"){
        ui->result->setNum(d_input_value / 3.281);
    }else if(first == "Фут" and second == "Сантиметр"){
        ui->result->setNum(d_input_value * 30.48);
    }else if(first == "Фут" and second == "Миллиметр"){
        ui->result->setNum(d_input_value * 305);
    }else if(ui->lineEdit->text() == NULL){
        QMessageBox::warning(this,"Внимание!", "Введите начальное значение!",QMessageBox::Ok,QMessageBox::Ok);
    }
}
