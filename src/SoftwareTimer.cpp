/*
    SoftwareTimer.cpp - library for simple use software timer.
    This library allows to call some function in selected time interval.
    Created by ILoveMemes, March 12, 2023
*/

#include "SoftwareTimer.h"

SoftwareTimer::SoftwareTimer() {
    status = SOFTWARE_TIMER_STATUS_RUNNING;
    interval = 0;
    callback = nullptr;
    callTime = 0;
}

SoftwareTimer::SoftwareTimer(unsigned long i, void(*function)()) {
    status = SOFTWARE_TIMER_STATUS_RUNNING;
    interval = i;
    callback = function;
    callTime = 0;
}

SoftwareTimer::~SoftwareTimer() {
    status = SOFTWARE_TIMER_STATUS_STOPPED;
    callback = nullptr;
}
    
void SoftwareTimer::attachFunction(void(*fun)()) {
    callback = fun;
}

void SoftwareTimer::setInterval(unsigned long i) {
    interval = i;
}

unsigned long SoftwareTimer::getInterval() {
    return interval;
}

void SoftwareTimer::tick() {
    if (status == SOFTWARE_TIMER_STATUS_RUNNING) {
        unsigned long now = millis();
        if (now - callTime >= interval) {
            if (callback) {
                (*callback)();
            }
            callTime = now;
        }
    }
}

void SoftwareTimer::stop() {
    status = SOFTWARE_TIMER_STATUS_STOPPED;
}

void SoftwareTimer::pause() {
    status = SOFTWARE_TIMER_STATUS_PAUSED;
    // save elapsed time
    callTime = millis() - callTime;
}

void SoftwareTimer::resume() {
    if (status == SOFTWARE_TIMER_STATUS_PAUSED) {
        // restore elapsed time
        callTime = millis() - callTime;
    } else {
        callTime = millis();
    }
    status = SOFTWARE_TIMER_STATUS_RUNNING;
}