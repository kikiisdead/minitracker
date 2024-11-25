#include "display.h"

Display::Display(Lane* lane_) {
  display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  lane = lane_;
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);  // Don't proceed, loop forever
  }
  Serial.println("SSD1306 allocation success!");
  refreshRate = REFRESH_RATE; //Hz
}

void Display::makeStep(int row, int column, int position) {
  int xPos = (SCREEN_WIDTH * (column/2)) + 1;
  int yPos = (SCREEN_HEIGHT * (row/4)) + 1;
  int width = (SCREEN_WIDTH / 2) - 2;
  int height = (SCREEN_HEIGHT / 4) - 2;
  display.drawRoundRect(xPos, yPos, width, height, 4, WHITE);
  if (lane->getSelectedPattern()[position]->on) {
    stepText(0, width, height, xPos, yPos);
    display.print(position);
    stepText(1, width, height, xPos, yPos);
    display.print(lane->getSelectedPattern()[position]->sampleChop);
    stepText(2, width, height, xPos, yPos);
    display.print(lane->getSelectedPattern()[position]->pitch);
  }
}

void Display::stepText(int position, int width, int height, int xPos, int yPos) {
  int16_t x, y; //short int couold be - negative
  uint16_t w, h; //unsigned short int - cannot be negative
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.getTextBounds("1", 0, 0, &x, &y, &w, &h);
  display.setCursor(xPos + (width * position/5) + 1, yPos + ((height - h)/2));
}

void Display::makeLane() {
  for (int i = 0; i < 4; i ++) {
    int stepAdjust = i - 1;
    makeStep(i, 0, lane->stepPos + stepAdjust);
  }
}

void Display::update() {
  if (timeSinceRefresh >= 1000/refreshRate) {
    display.clearDisplay();
    makeLane();
    display.display();
    timeSinceRefresh = 0;
  }
}