/*
  Blink (with software timer)

  Turns an LED on for half second, then off for half second, repeatedly without blocking loop function.

  created 06 Nov 2023
  by ILoveMemes

  https://github.com/ILoveMemes/SoftwareTimer
*/

#include <SoftwareTimer.h>

// LED pin defined as default led on the board
#define LED_PIN LED_BUILTIN

// timeout value set to 500 ms
#define TIMEOUT 500

// timer function
void toggle() {
  // check if led is powered on
  if (digitalRead(LED_PIN)) {
    // powered off the led
    digitalWrite(LED_PIN, LOW);
  } else {
    // powered on the led
    digitalWrite(LED_PIN, HIGH);
  }
}

// the timer variable
SoftwareTimer timer(TIMEOUT, &toggle);

void setup() {
  // set led pin as output
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // call the timer tick function
  timer.tick();
  // code here can work with the timer without been blocked
}
