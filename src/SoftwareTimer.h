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

class SoftwareTimer {
private:
    unsigned long interval;
    unsigned long callTime;
    void(*callback)() = nullptr;
    unsigned char status = SOFTWARE_TIMER_STATUS_STOPPED;

public:   
    SoftwareTimer();
    SoftwareTimer(unsigned long interval, void(*function)() = nullptr);
    ~SoftwareTimer();
    void attachFunction(void(*fun)());
    void setInterval(unsigned long i);
    unsigned long getInterval();
    void tick();
    void stop();
    void pause();
    void resume();
};

#endif