#ifndef displayable_h
#define displayable_h

//interface has no constructor, purely a set of methods to be implemented virtual or not
//interface that allows for UI button things to trigger display update 

class Displayable {
public:
  void (*displayUpdate)();
  void displayUpdateHandler(void (*func)()) {
    displayUpdate = *func;
  }
};

#endif