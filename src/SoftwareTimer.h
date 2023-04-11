/*
    SoftwareTimer.h - library for simple use software timer.
    This library allows to call some function in selected time interval.
    Created by ILoveMemes, March 12, 2023
*/

#ifndef SOFTWARE_TIMER_H
#define SOFTWARE_TIMER_H

#include <Arduino.h>

#define SOFTWARE_TIMER_STATUS_STOPPED 0
#define SOFTWARE_TIMER_STATUS_PAUSED 1
#define SOFTWARE_TIMER_STATUS_RUNNING 2
#define SOFTWARE_TIMER_STATUS_ERROR 3

class SoftwareTimer {
private:
    unsigned long interval;
    unsigned long callTime;
    void(*callback)() = nullptr;
    unsigned char status = SOFTWARE_TIMER_STATUS_STOPPED;

public:
    SoftwareTimer(unsigned long interval = 0, void(*function)() = nullptr);
    ~SoftwareTimer();
    unsigned char attachFunction(void(*fun)());
    void setInterval(unsigned long i);
    unsigned long getInterval();
    void tick();
    unsigned char stop();
    unsigned char pause();
    unsigned char resume();
    unsigned char getStatus();
};

#endif