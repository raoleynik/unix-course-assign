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
signals:
    void thirdWindow();

private slots:

    void on_temp_exit_clicked();

    void on_t_return_clicked();

    void on_t_convert_clicked();

private:
    Ui::conv_temp *ui;
};

#endif // CONV_TEMP_H
