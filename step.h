#ifndef step_h
#define step_h

#define ON 0
#define CHOP 1
#define PITCH 2
#define FX 3

#include "editable.h"
#include "displayable.h"

//Data from a step + editability through  abstract methods from editable interface

class Step : public Editable, public Displayable {
private:
  int selected;
public:
  Step(unsigned int _sampleChop, int _pitch, bool _on);
  unsigned int sampleChop;
  int pitch;
  bool on;
  void up();
  void down();
  void left();
  void right();
};

#endif