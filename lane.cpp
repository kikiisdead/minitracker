#include "lane.h"

Lane::Lane() {
  samplePlayer.looping = false;
  samplePlayer.backwards = false;
  timePerStep = 175;
  sequenceLength = 16;
  startTimes = { 0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875 };
  stepPos = 0;
  selectedPattern = 0;
  samplePlayer.setSampleArray(AudioSampleCollins1w);
  type = "l";
}

void Lane::generatePattern() {
  Step* sequencer[128];
  for (int i = 0; i < 128; i ++) {
    sequencer[i] = new Step(i % 8, 6, !((bool) (i % 2)));
    sequencer[i]->displayUpdateHandler(displayUpdate);
  }
  patterns.push_back(sequencer);
}

Step** Lane::getSelectedPattern() {
  return patterns[selectedPattern];
}

void Lane::play() {
  if (timeSinceStep >= timePerStep) {
    if (patterns[selectedPattern][stepPos]->on) {
      samplePlayer.startPercent = startTimes.at(patterns[selectedPattern][stepPos]->sampleChop);
      samplePlayer.pitchShift(patterns[selectedPattern][stepPos]->pitch);
      if (patterns[selectedPattern][stepPos]->sampleChop + 1 >= startTimes.size()) {
        samplePlayer.endPercent = 1;
      } else {
        samplePlayer.endPercent = startTimes.at(patterns[selectedPattern][stepPos]->sampleChop + 1);
      }
      displayUpdate();
      samplePlayer.play();
    }

    timeSinceStep = 0;
    stepPos++;
    if (stepPos >= sequenceLength) {
      stepPos = 0;
    }
  }
}

void Lane::up() {
  stepPos++;
  if (stepPos >= sequenceLength) {
    stepPos = 0;
  } 
  displayUpdate();
}

void Lane::down() {
  stepPos--;
  if (stepPos < 0) {
    stepPos = sequenceLength;
  }
  displayUpdate();
}