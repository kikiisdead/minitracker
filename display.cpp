#include "display.h"

Display::Display(Lane* lane_) {
    display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    lane = lane_;
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println(F("SSD1306 allocation failed"));
      while (1);  // Don't proceed, loop forever
    }
    Serial.println("SSD1306 allocation success!");
  }

void Display::makeStep(int row, int column) {
  int xPos = (SCREEN_WIDTH * (column/2)) + 1;
  int yPos = (SCREEN_HEIGHT * (row/4)) + 1;
  int width = (SCREEN_WIDTH / 2) - 2;
  int height = (SCREEN_HEIGHT / 4) - 2;
  display.drawRoundRect(xPos, yPos, width, height, 4, WHITE);
  int stepPos = lane->stepPos;
  int x, y;
  int w, h;
  //need to display step number, sample chop, pitch, and if its on or off
  display.getTextBounds("1", 0, 0, &x, &y, &w, &h);
  display.setCursor(xPos + 1, yPos + ((height - h)/2));
  display.print(lane->stepPos);
}

void Display::update() {

}