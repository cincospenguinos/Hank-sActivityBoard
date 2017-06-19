#include "Buzzer.h"

Buzzer::Buzzer(int _pin){
  pinMode(outputPin, OUTPUT);
  outputPin = _pin;
  quarterNoteLength = 500;
}

void Buzzer::play(char pitch, int octave, int noteLength){
  int freq = getPitch(pitch, octave);
  int length = getLengthInMillis(noteLength);
  tone(outputPin, freq, length);
}

// TODO: black keys?
int Buzzer::getPitch(char pitch, int octave){
  int freq;
  
  switch(pitch){
  case 'c':
    freq = 16;
    break;
  case 'd':
    freq = 18;
    break;
  case 'e':
    freq = 20;
    break;
  case 'f':
    freq = 21;
    break;
  case 'g':
    freq = 24;
    break;
  case 'a':
    freq = 27;
    break;
  case 'b':
    freq = 31;
    break;
  }

  while(octave-- != 0){
    freq *= 2;
  }

  return freq;
}

// TODO: Dotted half? Tied notes? How do?
int Buzzer::getLengthInMillis(int noteLength){
  switch(noteLength){
  case THIRTY_SECOND:
    return quarterNoteLength / 8;
  case SIXTEENTH:
    return quarterNoteLength / 4;
  case EIGHTH:
    return quarterNoteLength / 2;
  case QUARTER:
    return quarterNoteLength;
  case HALF:
    return quarterNoteLength * 2;
  case WHOLE:
    return quarterNoteLength * 4;
  }
}
