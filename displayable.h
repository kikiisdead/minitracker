#ifndef displayable_h
#define displayable_h

//SUPERCLASS that allows for UI button things to trigger display update

class Displayable {
public:
  void (*displayUpdate)();
  void displayUpdateHandler(void (*func)()) {
    displayUpdate = *func;
  }
};

#endif