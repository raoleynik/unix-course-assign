#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conv_length.h"
#include "conv_mass.h"
#include "conv_temp.h"
#include "conv_time.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_PushButton_exit_clicked();

    void on_PushButton_Conv_Length_Open_clicked();

    void on_PushButton_Conv_Temp_Open_clicked();

    void on_PushButton_Conv_Mass_Open_clicked();

    void on_PushButton_Conv_Time_Open_clicked();

private:
    Ui::MainWindow *ui;
    Conv_Length *lwindow;
    conv_mass *mwindow;
    conv_temp *twindow;
    conv_time *t2window;
};
#endif // MAINWINDOW_H
