#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alarmdialog.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->customInterval = 0;
    this->customArmed = false;

    ui->btn10m->setProperty("m_interval", 600);
    ui->btn20m->setProperty("m_interval", 1200);


    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            ui->btn10m, SLOT(tick()));
    connect(timer, SIGNAL(timeout()),
            ui->btn20m, SLOT(tick()));
    connect(timer, SIGNAL(timeout()),
            this, SLOT(tick()));

    connect(ui->btn10m, SIGNAL(alarm()),
            this, SLOT(onAlarm()));
    connect(ui->btn20m, SIGNAL(alarm()),
            this, SLOT(onAlarm()));


    timer->start(1000);

    this->setWindowFlags(Qt::WindowStaysOnTopHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tick()
{
    if (customArmed && (customInterval > 0))
    {
        customInterval--;
        QTime curTime(0,0,0,0);
        curTime = curTime.addSecs(customInterval);
        curTime.addMSecs(customInterval);
        ui->btnCustom->setText(curTime.toString("hh:mm:ss"));
    }
    else
    {
        customInterval = 0;
        ui->btnCustom->setText(tr("Свое"));
//        QTime curTime(0,0,0,0);
//        curTime = curTime.addSecs(customInterval);
//        ui->btnCustom->setText(curTime.toString("hh:mm:ss"));
        if (customArmed)
        {
            customArmed = false;
            onAlarm();
        }
    }
}

void MainWindow::on_btnExit_clicked()
{
    this->close();
}

void MainWindow::onAlarm()
{
    //QMessageBox::StandardButton alrmDialog;
    //alrmDialog = QMessageBox::information(this, tr("Alarm"), tr("Alarm"));

    AlarmDialog* alrmDlg = new AlarmDialog(this);
    alrmDlg->showFullScreen();

}

void MainWindow::on_btnCustom_clicked()
{
    if (customArmed)
    {
        customArmed = false;

    }
    else
    {
        this->customInterval = 60 * QInputDialog::getInt(this, tr("Введите количество минут"),
                                                         tr("Количество минут"),
                                                         0, 0, 120);

        if (customInterval > 0 )
        {
            this->customArmed = true;
        }
    }
}
