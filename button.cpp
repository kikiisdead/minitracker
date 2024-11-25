#include "button.h"
#include <Arduino.h>

Button::Button(int buttonPin_) {
  this->buttonPin = buttonPin_;
  buttonState = HIGH;
  lastButtonState = HIGH;
  pinMode(buttonPin, INPUT_PULLUP);
  timeSinceEvent = 0;
}

void Button::update() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH && timeSinceEvent > 5) {  // button press inverted HIGH adn LOW because input pullup
    press();
    timeSinceEvent = 0;
  } else if (buttonState == LOW && lastButtonState == LOW) {  // button sustain
    hold();
  } else if (buttonState == HIGH && lastButtonState == LOW && timeSinceEvent > 5) {  // button release
    release();
    timeSinceEvent = 0; //elapsed millis to set debounce time
  } 
  lastButtonState = buttonState;
}

void Button::pressHandler(void (*func)()) {
  press = *func;
}

void Button::holdHandler(void (*func)()) {
  hold = *func;
}

void Button::releaseHandler(void (*func)()) {
  release = *func;
}