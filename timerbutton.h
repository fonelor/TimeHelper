#ifndef TIMERBUTTON_H
#define TIMERBUTTON_H

#include <QPushButton>

class TimerButton : public QPushButton
{
    Q_OBJECT

    Q_PROPERTY(int m_interval READ getInterval WRITE setInterval)

public:

    explicit  TimerButton(QWidget *parent = 0);

    int getInterval();

    void setInterval(int interval);

signals:

    void alarm();

public slots:

    void tick();
    void startInterval();

private:

    QString name;
    int m_interval;
    int curInterval;
    bool isArmed;

    void updateBtnText(QString txt);
};

#endif // TIMERBUTTON_H
