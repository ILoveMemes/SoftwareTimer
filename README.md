# SoftwareTimer
Simple library for use software timer. It provides a possibility to call a function at set time interval.

## Compatibility
This library is compatible with all architectures.

## How to use
Include the library
```cpp
#include <SoftwareTimer.h>
```
Define a timer like this
```cpp
SoftwareTimer timer;
```
..or like this
```cpp
SoftwareTimer timer(500, &function);
```
where 500 ms is timeout for calling funciton defined as ```void function()```

Then put ```tick``` function call into ```loop```:
```cpp
void loop() {
    timer.tick();
}
```
So now ```function()``` will be execute every 500 ms.

## Interface description
Constructor:
```cpp
SoftwareTimer timer1;                         // without params
SoftwareTimer timer2(1000);                   // setup the time interval
SoftwareTimer timer3(1000, &function);        // setup the time interval and the executable function
```
Tick function (put this call into ```loop```):
```cpp
timer.tick();                                 // call for handling timer logic
```
Setup params at runtime:
```cpp
timer.attachFunction(&function);              // set executable function
timer.setInterval(500);                       // set timeout interval in milliseconds
unsigned long interval = timer.getInterval(); // get the interval
timer.stop();                                 // stop the timer
timer.pause();                                // pause the timer
timer.resume();                               // resume timer after pausing or stopping
```

### Pause feature
This timer can be paused by calling ```timer.pause()``` and then can be resumed by ```timer.resume()```.
When timer is paused, left time to call function is memorising, and when timer resume it continue to count time from memorised value.
Calling ```timer.stop()``` set elapsed time to zero, so resuming after stop will be count timer interval from zero.