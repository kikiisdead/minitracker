#ifndef screen_h
#define screen_h

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "lane.h"

#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

class Display {
private:
  Adafruit_SSD1306 display;
  Lane* lane;
  void makeStep(int row, int column, int position);
  void makeLane();
  void stepText(int position, int width, int height);
public:
  Display(Lane* lane_);
  void update();
};

#endif