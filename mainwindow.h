#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void tick();

    void onAlarm();

    void on_btnExit_clicked();
    void on_btnCustom_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;

    int customInterval;
    bool customArmed;
};

#endif // MAINWINDOW_H
