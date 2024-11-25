#include "step.h"

Step::Step(unsigned int _sampleChop, int _pitch, bool _on) {
  sampleChop = _sampleChop;
  pitch = _pitch;
  on = _on;
  selected = ON;
  type = "s";
}

void Step::left() {
  selected = (selected > 0) ? selected - 1 : FX;
  displayUpdate();
}

void Step::right() {
  selected = (selected < 3) ? selected + 1 : ON;
  displayUpdate();
}

void Step::up() {
  if (selected == ON) {
    on = !on;
  } else if (selected == CHOP) {
    sampleChop += 1;
  } else if (selected == PITCH) {
    pitch += 1;
  } else if (selected == FX) { 
  }
  displayUpdate();
}

void Step::down() {
  if (selected == ON) {
    on = !on;
  } else if (selected == CHOP) {
    sampleChop -= 1;
  } else if (selected == PITCH) {
    pitch -= 1;
  } else if (selected == FX) {
  }
  displayUpdate();
}