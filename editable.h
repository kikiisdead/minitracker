#ifndef editable_h
#define editable_h

//interface that allows for the UI things to work

class Editable {
public:
  char type;
  virtual void left() = 0;
  virtual void right() = 0;
  virtual void up() = 0;
  virtual void down() = 0;
};

#endif