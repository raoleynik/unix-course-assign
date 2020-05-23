#include "conv_volume.h"
#include "ui_conv_volume.h"
#include <QMessageBox>
#include <QDebug>
conv_volume::conv_volume(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conv_volume)
{
    ui->setupUi(this);
}

conv_volume::~conv_volume()
{
    delete ui;
}

