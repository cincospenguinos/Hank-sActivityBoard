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

class Buzzer
{
 public:
  static const int THIRTY_SECOND = 0;
  static const int SIXTEENTH = 1;
  static const int EIGHTH = 2;
  static const int QUARTER = 3;
  static const int HALF = 4;
  static const int WHOLE = 5;
 
  Buzzer(int _pin);
  void play(char pitch, int octave, int noteLength);
  void setTempo(int bpm);
 private:
  int outputPin; // What output pin the buzzer will be using
  int quarterNoteLength; // How long a quarter note should be in millis
  int getPitch(char pitch, int octave);
  int getLengthInMillis(int noteLength); 
};
#endif
