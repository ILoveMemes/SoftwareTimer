/*
    SoftwareTimer.cpp - library for simple use software timer.
    This library allows to call some function in selected time interval.
    Created by ILoveMemes, March 12, 2023
*/

#include "SoftwareTimer.h"

SoftwareTimer::SoftwareTimer(unsigned long i, void(*function)()) {
    if (function) {
        status = SOFTWARE_TIMER_STATUS_RUNNING;
    } else {
        status = SOFTWARE_TIMER_STATUS_STOPPED;
    }
    interval = i;
    callback = function;
    callTime = 0;
}

SoftwareTimer::~SoftwareTimer() {
    status = SOFTWARE_TIMER_STATUS_STOPPED;
    callback = nullptr;
}
    
unsigned char SoftwareTimer::attachFunction(void(*fun)()) {
    callback = fun;
    if (!fun) {
        status = SOFTWARE_TIMER_STATUS_ERROR;
    } else if (status == SOFTWARE_TIMER_STATUS_ERROR) {
        status = SOFTWARE_TIMER_STATUS_STOPPED;
    }
    return status;
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
            // callback is not null according to check in setter and constructor
            (*callback)();
            callTime = now;
        }
    }
}

unsigned char SoftwareTimer::stop() {
    status = SOFTWARE_TIMER_STATUS_STOPPED;
    return status;
}

unsigned char SoftwareTimer::pause() {
    status = SOFTWARE_TIMER_STATUS_PAUSED;
    // save elapsed time
    callTime = millis() - callTime;
    return status;
}

unsigned char SoftwareTimer::resume() {
    if (callback) {
        if (status == SOFTWARE_TIMER_STATUS_PAUSED) {
            // restore elapsed time
            callTime = millis() - callTime;
        } else {
            callTime = millis();
        }
        status = SOFTWARE_TIMER_STATUS_RUNNING;
    } else {
        status = SOFTWARE_TIMER_STATUS_ERROR;
    }
    return status;
}

unsigned char SoftwareTimer::getStatus() {
    return status;
}