#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <StevesAwesomeButton.h>
#include <typeinfo>

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
Lane lane2 = Lane();
Lane lane3 = Lane();
Lane lane4 = Lane();
Lane* lanes[4] = { &lane1, &lane2, &lane3, &lane4 };
AudioOutputI2S i2sOut;
AudioConnection patchcord1(lane1.samplePlayer, 0, i2sOut, 0);
AudioConnection patchcord2(lane1.samplePlayer, 0, i2sOut, 1);
AudioControlSGTL5000 audioShield;

Display display(&lane1); //figure out singleton so that I'm making sure that there is only one display object

Editable* edit = &lane1;

void setup() {
  Serial.begin(9600);

  AudioMemory(12);

  audioShield.enable();
  audioShield.volume(0.5);

  lane1.displayUpdateHandler(displayUpdate);
  lane1.generatePattern();

  upButton.pressHandler(upPress);
  downButton.pressHandler(downPress);
  leftButton.pressHandler(leftPress);
  rightButton.pressHandler(rightPress);
  editButton.pressHandler(editPress);
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
  editButton.update();
}

void displayUpdate() {
  display.update();
}

void upPress() {  //wrapping the abstract function into a static function. the pointer to this function will call different functions based on the type of Editable object.
  edit->up();
}

void downPress() {
  edit->down();
}

void leftPress() {
  edit->left();
}

void rightPress() {
  edit->right();
}

void editPress() {
  if (edit->type == (char)"l") {
    edit = lane1.getSelectedPattern()[lane1.stepPos];  //get pointer to the Step object at the position in the pattern
  } else if (edit->type == (char)"s") {
    edit = &lane1;
  }
}