#ifndef CONV_LENGTH_H
#define CONV_LENGTH_H

#include <QWidget>

namespace Ui {
class Conv_Length;
}

class Conv_Length : public QWidget
{
    Q_OBJECT

public:
    explicit Conv_Length(QWidget *parent = nullptr);
    ~Conv_Length();
signals:
    void firstWindow();
private slots:


    void on_length_exit_clicked();

    void on_l_return_clicked();

    void on_l_convert_clicked();

private:
    Ui::Conv_Length *ui;
};

#endif // CONV_LENGTH_H
