#ifndef CONV_TEMP_H
#define CONV_TEMP_H

#include <QWidget>

namespace Ui {
class conv_temp;
}

class conv_temp : public QWidget
{
    Q_OBJECT

public:
    explicit conv_temp(QWidget *parent = nullptr);
    ~conv_temp();

private slots:


private:
    Ui::conv_temp *ui;
};

#endif // CONV_TEMP_H
