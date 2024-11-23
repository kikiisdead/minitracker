#ifndef button_h
#define button_h

#include <Arduino.h>
#include "editable.h"

class Button {
private:
  int buttonPin;
  int buttonState;
  int lastButtonState;
  elapsedMillis timeSinceEvent;
public:
  Button(int buttonPin_);
  void update();
  void (*press)();
  void pressHandler(void (*func)());
  void (*hold)();
  void holdHandler(void (*func)());
  void (*release)();
  void releaseHandler(void (*func)());
};

#endif