#ifndef CONV_VOLUME_H
#define CONV_VOLUME_H

#include <QWidget>

namespace Ui {
class conv_volume;
}

class conv_volume : public QWidget
{
    Q_OBJECT

public:
    explicit conv_volume(QWidget *parent = nullptr);
    ~conv_volume();

private slots:

private:
    Ui::conv_volume *ui;
};

#endif // CONV_VOLUME_H
