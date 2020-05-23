#include "conv_length.h"
#include "ui_conv_length.h"
#include <QMessageBox>
#include <QDebug>
Conv_Length::Conv_Length(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Conv_Length)
{
    ui->setupUi(this);
}

Conv_Length::~Conv_Length()
{
    delete ui;
}

