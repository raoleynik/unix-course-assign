#ifndef CONV_TIME_H
#define CONV_TIME_H

#include <QWidget>

namespace Ui {
class conv_time;
}

class conv_time : public QWidget
{
    Q_OBJECT

public:
    explicit conv_time(QWidget *parent = nullptr);
    ~conv_time();

signals:
    void fourthWindow();

private slots:
    void on_time_exit_clicked();

    void on_t2_return_clicked();

    void on_t2_convert_clicked();

private:
    Ui::conv_time *ui;
};

#endif // CONV_TIME_H
