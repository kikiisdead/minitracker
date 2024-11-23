#ifndef lane_h
#define lane_h

#include <StevesAwesomeSamplePlayer.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Adafruit_SSD1306.h>
#include "AudioSampleCollins1w.h"
#include "step.h"
#include "editable.h"
#include "displayable.h"

//lane of the sequencer

class Lane : public Editable, public Displayable {
private:
  std::vector<double> startTimes;
  elapsedMillis timeSinceStep;
  int timePerStep;
public:
  Lane();
  Step* sequencer[128]; //max of 128 steps gets initialized in the constructor
  int stepPos;
  int sequenceLength;
  StevesAwesomeSamplePlayer samplePlayer;
  void update();
  void play();
  void up();
  void down();
  void left() {}; //not really doing anything
  void right() {}; //not really doing anything
};

#endif