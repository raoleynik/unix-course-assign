#include "conv_time.h"
#include "ui_conv_time.h"
#include <QMessageBox>
#include <QDebug>
#include <algorithm>
#include <iostream>
#include <string>
conv_time::conv_time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conv_time)
{
    ui->setupUi(this);
    ui->LV1->setCurrentRow(1);
    ui->LV2->setCurrentRow(1);
    QListWidgetItem *lv1item1 = new QListWidgetItem("Год");
    ui->LV1->addItem(lv1item1);
    QListWidgetItem *lv1item2 = new QListWidgetItem("Месяц");
    ui->LV1->addItem(lv1item2);
    QListWidgetItem *lv1item3 = new QListWidgetItem("Неделя");
    ui->LV1->addItem(lv1item3);
    QListWidgetItem *lv1item4 = new QListWidgetItem("Сутки");
    ui->LV1->addItem(lv1item4);
    QListWidgetItem *lv1item5 = new QListWidgetItem("Час");
    ui->LV1->addItem(lv1item5);
    QListWidgetItem *lv1item6 = new QListWidgetItem("Минута");
    ui->LV1->addItem(lv1item6);
    QListWidgetItem *lv1item7 = new QListWidgetItem("Секунда");
    ui->LV1->addItem(lv1item7);
    QListWidgetItem *lv2item1 = new QListWidgetItem("Год");
    ui->LV2->addItem(lv2item1);
    QListWidgetItem *lv2item2 = new QListWidgetItem("Месяц");
    ui->LV2->addItem(lv2item2);
    QListWidgetItem *lv2item3 = new QListWidgetItem("Неделя");
    ui->LV2->addItem(lv2item3);
    QListWidgetItem *lv2item4 = new QListWidgetItem("Сутки");
    ui->LV2->addItem(lv2item4);
    QListWidgetItem *lv2item5 = new QListWidgetItem("Час");
    ui->LV2->addItem(lv2item5);
    QListWidgetItem *lv2item6 = new QListWidgetItem("Минута");
    ui->LV2->addItem(lv2item6);
    QListWidgetItem *lv2item7 = new QListWidgetItem("Секунда");
    ui->LV2->addItem(lv2item7);
}

conv_time::~conv_time()
{
    delete ui;
}

void conv_time::on_time_exit_clicked()
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Выход","Вы действительно хотите выйти?",
                                                            QMessageBox::No| QMessageBox::Yes);
    if (exit == QMessageBox::Yes){
        QApplication::exit();
    }
}

void conv_time::on_t2_return_clicked()
{
    hide();
    emit fourthWindow();
}

void conv_time::on_t2_convert_clicked()
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
    }else if(first == "Год" and second == "Месяц"){
        ui->result->setNum(d_input_value * 12);
    }else if(first == "Год" and second == "Неделя"){
        ui->result->setNum(d_input_value * 84);
    }else if(first == "Год" and second == "Сутки"){
        ui->result->setNum(d_input_value * 365);
    }else if(first == "Год" and second == "Час"){
        ui->result->setNum(d_input_value * 8760);
    }else if(first == "Год" and second == "Минута"){
        ui->result->setNum(d_input_value * 525600);
    }else if(first == "Год" and second == "Секунда"){
        ui->result->setNum(d_input_value * 525600 * 60);
    }else if(first == "Месяц" and second == "Год"){
        ui->result->setNum(d_input_value / 12);
    }else if(first == "Месяц" and second == "Неделя"){
        ui->result->setNum(d_input_value * 4.345);
    }else if(first == "Месяц" and second == "Сутки"){
        ui->result->setNum(d_input_value * 30.417);
    }else if(first == "Месяц" and second == "Час"){
        ui->result->setNum(d_input_value * 730);
    }else if(first == "Месяц" and second == "Минута"){
        ui->result->setNum(d_input_value * 43800);
    }else if(first == "Месяц" and second == "Секунда"){
        ui->result->setNum(d_input_value * 4380 * 60);
    }else if(first == "Неделя" and second == "Год"){
        ui->result->setNum(d_input_value / 84);
    }else if(first == "Неделя" and second == "Месяц"){
        ui->result->setNum(d_input_value / 4.345);
    }else if(first == "Неделя" and second == "Сутки"){
        ui->result->setNum(d_input_value * 7);
    }else if(first == "Неделя" and second == "Час"){
        ui->result->setNum(d_input_value * 168); // fsafsafsa
    }else if(first == "Неделя" and second == "Минута"){
        ui->result->setNum(d_input_value * 168 * 60);
    }else if(first == "Неделя" and second == "Секунда"){
        ui->result->setNum(d_input_value * 168 * 3600);
    }else if(first == "Сутки" and second == "Год"){
        ui->result->setNum(d_input_value / 365);
    }else if(first == "Сутки" and second == "Месяц"){
        ui->result->setNum(d_input_value / 30.417);
    }else if(first == "Сутки" and second == "Неделя"){
        ui->result->setNum(d_input_value / 7);
    }else if(first == "Сутки" and second == "Час"){
        ui->result->setNum(d_input_value * 24);
    }else if(first == "Сутки" and second == "Минута"){
        ui->result->setNum(d_input_value * 24 * 60);
    }else if(first == "Сутки" and second == "Секунда"){
        ui->result->setNum(d_input_value * 24 * 3600);
    }else if(first == "Час" and second == "Год"){
        ui->result->setNum(d_input_value / 8760);
    }else if(first == "Час" and second == "Месяц"){
        ui->result->setNum(d_input_value / 730);
    }else if(first == "Час" and second == "Неделя"){
        ui->result->setNum(d_input_value / 168);
    }else if(first == "Час" and second == "Сутки"){
        ui->result->setNum(d_input_value / 24);
    }else if(first == "Час" and second == "Минута"){
        ui->result->setNum(d_input_value * 60);
    }else if(first == "Час" and second == "Секунда"){
        ui->result->setNum(d_input_value * 3600);
    }else if(first == "Минута" and second == "Год"){
        ui->result->setNum(d_input_value / 525600);
    }else if(first == "Минута" and second == "Месяц"){
        ui->result->setNum(d_input_value / 43800);
    }else if(first == "Минута" and second == "Неделя"){
        ui->result->setNum(d_input_value / 168 / 60);
    }else if(first == "Минута" and second == "Сутки"){
        ui->result->setNum(d_input_value / 24 / 60);
    }else if(first == "Минута" and second == "Час"){
        ui->result->setNum(d_input_value / 60);
    }else if(first == "Минута" and second == "Секунда"){
        ui->result->setNum(d_input_value * 60);
    }else if(first == "Секунда" and second == "Год"){
        ui->result->setNum(d_input_value / 525600 / 60);
    }else if(first == "Секунда" and second == "Месяц"){
        ui->result->setNum(d_input_value / 4380 / 60);
    }else if(first == "Секунда" and second == "Неделя"){
        ui->result->setNum(d_input_value / 168 / 3600);
    }else if(first == "Секунда" and second == "Сутки"){
        ui->result->setNum(d_input_value / 24 / 3600);
    }else if(first == "Секунда" and second == "Час"){
        ui->result->setNum(d_input_value / 3600);
    }else if(first == "Секунда" and second == "Минута"){
        ui->result->setNum(d_input_value / 60);
    }else if(ui->lineEdit->text() == NULL){
        QMessageBox::warning(this,"Внимание!", "Введите начальное значение!",QMessageBox::Ok,QMessageBox::Ok);
    }
}

