#include "dicethread.h"
#include "QTime"
#include "QDebug"

DiceThread::DiceThread()
{

}

void DiceThread::run()
{
    stop=false;
    m_seq=0;
    qsrand(QTime::currentTime().msec());
    while (!stop) {
        if(!pause){
            m_diceValue=qrand();
            m_diceValue=(m_diceValue%6)+1;
            m_seq++;
            emit newValue(m_seq,m_diceValue);
        }
        msleep(500);
    }
    quit();
}

void DiceThread::diceBegin()
{
    pause=false;
}

void DiceThread::dicePause()
{
    pause=true;
}

void DiceThread::stopThread()
{
    stop=true;
}

