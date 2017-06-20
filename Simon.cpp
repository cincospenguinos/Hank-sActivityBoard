#include "Simon.h"
#include "header.h"

Simon::Simon(Buzzer b){
  b.setTempo(120);
}

void Simon::newPuzzle(){
  randomSeed(analogRead(0));
  for(int i = 0; i < Simon::PUZZLE_LENGTH; i++)
    puzzle[i] = random(4);

  endOfTurnIndex = 2;

  Serial.println("\tPuzzle:");

  for(int i = 0; i < Simon::PUZZLE_LENGTH; i++){
    Serial.print(puzzle[i]);
    Serial.print(" ");
  }
  Serial.println("");
}

void Simon::showStartup(Buzzer b){
  showColor(YELLOW, Buzzer::SIXTEENTH, b);
  showColor(BLUE, Buzzer::SIXTEENTH, b);
  showColor(GREEN, Buzzer::SIXTEENTH, b);
  showColor(RED, Buzzer::SIXTEENTH, b);

  for(int i = 0; i < 4; i++)
    digitalWrite(LED_FROM_COLOR(i), HIGH);

  b.play('c', 5, Buzzer::EIGHTH);
  b.play('c', 5, Buzzer::EIGHTH);

  for(int i = 0; i < 4; i++)
    digitalWrite(LED_FROM_COLOR(i), LOW);
}

int Simon::submitButton(int button, Buzzer b){
  int color = COLOR_FROM_BUTTON(button);
  if (color == puzzle[currentTurnIndex]) {
    Serial.println("CORRECT!");
    showColor(color, Buzzer::SIXTEENTH, b);
    currentTurnIndex++;
    
    if(currentTurnIndex > endOfTurnIndex){
      Serial.println("END OF TURN");
      showSuccess(b);
      delay(250);
      currentTurnIndex = 0;

      if(++endOfTurnIndex == Simon::PUZZLE_LENGTH){
        showWin(b);
        delay(2000);
        newPuzzle(); // TODO: Keep this here?
      }
      
      return 1;
    }

    return 0;
  } else {
    Serial.println("INCORRECT!");
    showFailure(b);
    Serial.println("Resetting...");
    currentTurnIndex = 0;
    endOfTurnIndex = 2;
    return -1;
  }
}

void Simon::showCurrentPuzzle(Buzzer b){
  for(int i = 0; i <= endOfTurnIndex; i++){
    int color = puzzle[i];
    showColor(color, Buzzer::HALF, b);
    delay(Buzzer::HALF);
  }
}

void Simon::showColor(int color, int noteLength, Buzzer b){
  int led = LED_FROM_COLOR(color);
  char note = pitches[color];
  digitalWrite(led, HIGH);
  b.play(note, 4, noteLength);
  digitalWrite(led, LOW);
}

void Simon::showSuccess(Buzzer b){
  showColor(YELLOW, Buzzer::SIXTEENTH, b);
  showColor(BLUE, Buzzer::SIXTEENTH, b);
  showColor(GREEN, Buzzer::SIXTEENTH, b);
  showColor(RED, Buzzer::SIXTEENTH, b);

  for(int i = 0; i < 4; i++)
    digitalWrite(LED_FROM_COLOR(i), HIGH);

  b.play('c', 5, Buzzer::EIGHTH);

  for(int i = 0; i < 4; i++)
    digitalWrite(LED_FROM_COLOR(i), LOW);
}

void Simon::showFailure(Buzzer b){
  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 4; i++)
    digitalWrite(LED_FROM_COLOR(i), HIGH);

    b.play('a', 4, Buzzer::QUARTER);

    for(int i = 0; i < 4; i++)
      digitalWrite(LED_FROM_COLOR(i), LOW);
  }
}

void Simon::showWin(Buzzer b){
  static char winSong[15] = { 'e', 'e', 'f', 'g', 'g', 'f', 'e', 'd', 'c', 'c', 'd', 'e', 'd', 'c', 'c' };

  for(int i = 0; i < 15; i++){
    char note = winSong[i];
    char led = LED_FROM_COLOR(i % 4);
    digitalWrite(led, HIGH);
    b.play(note, 5, Buzzer::EIGHTH);
    digitalWrite(led, LOW);
  }
}
