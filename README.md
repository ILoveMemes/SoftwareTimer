# SoftwareTimer
Simple software timer to use. It provides a possibility to call a function at set time interval.

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
where 500 ms is timeout for calling function defined as ```void function()```

Then put ```tick``` function call into ```loop```:
```cpp
void loop() {
    timer.tick();
}
```
So now ```function()``` will be executed every 500 ms.

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
unsigned char status = timer.getStatus();     // return current timer state
```
```stop```, ```pause```, ```resume```, ```attachFunction``` are return current timer status. If status is ```SOFTWARE_TIMER_STATUS_ERROR``` then timer is stopped. This appears when callback function is null.

### Timer status
The timer can have following status
* ```SOFTWARE_TIMER_STATUS_STOPPED``` - all is OK, timer stopped;
* ```SOFTWARE_TIMER_STATUS_PAUSED``` - timer paused, see feature description below;
* ```SOFTWARE_TIMER_STATUS_RUNNING``` - timer running normally;
* ```SOFTWARE_TIMER_STATUS_ERROR``` - timer stopped, callback function is null.

### Pause feature
This timer can be paused by calling ```timer.pause()``` and then can be resumed by ```timer.resume()```.
When timer is paused, the time left to the next call of the function is memorized, and when timer is resumed it continues to count time since the last memorized value.
Calling ```timer.stop()``` sets elapsed time to zero, so resuming it after stop will count timer interval from zero.