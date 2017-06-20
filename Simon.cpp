#include "Simon.h"

Simon::Simon(Buzzer b){
  b.setTempo(120);
}

void Simon::newPuzzle(){
  for(int i = 0; i < Simon::PUZZLE_LENGTH; i++)
    puzzle[i] = rand() % 4;

  currentTurnIndex = 2;

  Serial.println("\tPuzzle:");

  for(int i = 0; i < Simon::PUZZLE_LENGTH; i++){
    Serial.print(puzzle[i]);
    Serial.print(" ");
  }
}

void Simon::showStartup(Buzzer b){
  showColor(Simon::YELLOW, Buzzer::SIXTEENTH, b);
  showColor(Simon::BLUE, Buzzer::SIXTEENTH, b);
  showColor(Simon::GREEN, Buzzer::SIXTEENTH, b);
  showColor(Simon::RED, Buzzer::SIXTEENTH, b);

  for(int i = 0; i < 4; i++)
    digitalWrite(getLedFromColor(i), HIGH);

  b.play('c', 5, Buzzer::EIGHTH);
  b.play('c', 5, Buzzer::EIGHTH);

  for(int i = 0; i < 4; i++)
    digitalWrite(getLedFromColor(i), LOW);
}

void Simon::submitButton(int button, Buzzer b){
  int color = getColorFromButton(button);
  if (color == puzzle[currentTurnIndex]) {
    showSuccess(b);
    if(++currentTurnIndex == Simon::PUZZLE_LENGTH){
      showWin(b);
    }
  } else {
    showFailure(b);
    currentTurnIndex = 2;
  }
}

void Simon::showCurrentPuzzle(Buzzer b){
  for(int i = 0; i <= currentTurnIndex; i++){
    int color = puzzle[i];
    showColor(color, Buzzer::HALF, b);
  }
}

void Simon::showColor(int color, int noteLength, Buzzer b){
  int led = getLedFromColor(color);
  char note = pitches[color];
  digitalWrite(led, HIGH);
  b.play(note, 4, noteLength);
  digitalWrite(led, LOW);
}

void Simon::showSuccess(Buzzer b){
  showColor(YELLOW, Buzzer::EIGHTH, b);
  showColor(BLUE, Buzzer::EIGHTH, b);
  showColor(GREEN, Buzzer::EIGHTH, b);
  showColor(RED, Buzzer::EIGHTH, b);

  for(int i = 0; i < 4; i++)
    digitalWrite(getLedFromColor(i), HIGH);

  b.play('c', 5, Buzzer::QUARTER);

  for(int i = 0; i < 4; i++)
    digitalWrite(getLedFromColor(i), LOW);
}

void Simon::showFailure(Buzzer b){
  
}

void Simon::showWin(Buzzer b){
  
}

int Simon::getLedFromColor(int color){
  return color + 4;
}

int Simon::getColorFromButton(int button){
  return button - 10;
}
