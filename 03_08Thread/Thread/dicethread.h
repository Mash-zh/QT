#ifndef DICETHREAD_H
#define DICETHREAD_H
#include "QThread"

class DiceThread :public QThread
{
    Q_OBJECT
public:
    DiceThread();

private:
    int m_seq=0;//掷骰子次数序号
    int m_diceValue=0;//骰子点数
    bool pause=true;
    bool stop=false;

protected:
    void run() override;

public:
    void diceBegin();
    void dicePause();
    void stopThread();

signals:
    void newValue(int seq,int diceValue);
};

#endif // DICETHREAD_H
