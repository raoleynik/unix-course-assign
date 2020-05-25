#ifndef CONV_MASS_H
#define CONV_MASS_H

#include <QWidget>

namespace Ui {
class conv_mass;
}

class conv_mass : public QWidget
{
    Q_OBJECT

public:
    explicit conv_mass(QWidget *parent = nullptr);
    ~conv_mass();
signals:
    void secondWindow();
private slots:

    void on_mass_exit_clicked();

    void on_m_return_clicked();

    void on_m_convert_clicked();

private:
    Ui::conv_mass *ui;
};

#endif // CONV_MASS_H
