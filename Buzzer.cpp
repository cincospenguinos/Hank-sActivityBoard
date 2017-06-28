#include "Buzzer.h"
#include "Arduino.h"

Buzzer::Buzzer(int _pin){
  pinMode(outputPin, OUTPUT);
  outputPin = _pin;
  quarterNoteLength = 500;
}

void Buzzer::play(char pitch, int octave, int noteLength){
  int freq = getPitch(pitch, octave);
  int lengthOfNote = getLengthInMillis(noteLength);
  tone(outputPin, freq, lengthOfNote);
  delay(lengthOfNote);
}

void Buzzer::setTempo(int bpm){
  quarterNoteLength = 3 * bpm / 50;
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
  case Buzzer::THIRTY_SECOND:
    return quarterNoteLength / 8;
  case Buzzer::SIXTEENTH:
    return quarterNoteLength / 4;
  case Buzzer::EIGHTH:
    return quarterNoteLength / 2;
  case Buzzer::QUARTER:
    return quarterNoteLength;
  case Buzzer::HALF:
    return quarterNoteLength * 2;
  case Buzzer::WHOLE:
    return quarterNoteLength * 4;
  }
}
