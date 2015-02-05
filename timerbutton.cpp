#include "timerbutton.h"
#include <QTime>

TimerButton::TimerButton(QWidget *parent) : QPushButton(parent)
{
    this->isArmed = false;
    curInterval = 0;
    m_interval = 0;

    connect(this, SIGNAL(clicked()),
            this, SLOT(startInterval()));
}

void TimerButton::tick()
{
    if (isArmed && (curInterval > 0))
    {
        curInterval--;
        QTime curTime(0,0,0,0);
        curTime = curTime.addSecs(curInterval);
        curTime.addMSecs(curInterval);
        updateBtnText(curTime.toString("hh:mm:ss"));
    }
    else
    {
        curInterval = m_interval;
        QTime curTime(0,0,0,0);
        curTime = curTime.addSecs(curInterval);
        updateBtnText(curTime.toString("hh:mm:ss"));
        if (isArmed)
        {
            isArmed = false;
            emit alarm();
        }
    }
}

void TimerButton::startInterval()
{
    isArmed = !isArmed;
}

void TimerButton::updateBtnText(QString txt)
{
    this->setText(txt);
}

int TimerButton::getInterval()
{
    return this->m_interval;
}

void TimerButton::setInterval(int interval)
{
    this->m_interval = interval;
}
