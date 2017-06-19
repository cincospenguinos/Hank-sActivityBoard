/**
 * buzzer.h
 * Created by Andre LaFleur, 19 June 2017
 *
 * Simple buzzer library to help me play music 
 * using the piezzo buzzer.
 */
#ifndef Buzzer_h
#define Buzzer_h
#include "Arduino.h"

// Some definitions
#define THIRTY_SECOND 0
#define SIXTEENTH 1
#define EIGHTH 2
#define QUARTER 3
#define HALF 4
#define WHOLE 5

class Buzzer
{
 public:
  Buzzer(int _pin);
  void play(char pitch, int octave, int noteLength);
 private:
  int outputPin; // What output pin the buzzer will be using
  int quarterNoteLength; // How long a quarter note should be in millis
  int getPitch(char pitch, int octave);
  int getLengthInMillis(int noteLength); 
};
#endif
