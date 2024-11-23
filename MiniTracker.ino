#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <StevesAwesomeButton.h>

#include "lane.h"
#include "editable.h"
#include "button.h"
#include "display.h"

#define UPBUTTON 33
#define DOWNBUTTON 34
#define LEFTBUTTON 35
#define RIGHTBUTTON 36
#define EDITBUTTON 37

Button upButton(UPBUTTON);
Button downButton(DOWNBUTTON);
Button leftButton(LEFTBUTTON);
Button rightButton(RIGHTBUTTON);
Button editButton(EDITBUTTON);

Lane lane1 = Lane();
AudioOutputI2S i2sOut;
AudioConnection patchcord1(lane1.samplePlayer, 0, i2sOut, 0);
AudioConnection patchcord2(lane1.samplePlayer, 0, i2sOut, 1);
AudioControlSGTL5000 audioShield;

Display display(&lane1);

Editable* edit = &lane1;

void setup() {
  Serial.begin(9600);

  AudioMemory(12);

  audioShield.enable();
  audioShield.volume(0.5);

  lane1.displayUpdateHandler(displayUpdate);

  upButton.pressHandler(up);
  downButton.pressHandler(down);
  leftButton.pressHandler(left);
  rightButton.pressHandler(right);
}

void loop() {
  lane1.play();
  editUpdate();
}

void editUpdate() {
  upButton.update();
  downButton.update();
  leftButton.update();
  rightButton.update();
}

void displayUpdate() {
  display.update();
}

void up() { //wrpping the abstract function into a static function
  edit->up();
}

void down() {
  edit->down();
}

void left() {
  edit->left();
}

void right() {
  edit->right();
}