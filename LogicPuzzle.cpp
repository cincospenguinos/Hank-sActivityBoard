#include "LogicPuzzle.h"
#include "Arduino.h"
#include "header.h"

LogicPuzzle::LogicPuzzle(int j){}

void LogicPuzzle::newLogicPuzzle(int turnsAway){
  for(int i = 0; i < 4; i++)
    currentState[i] = HIGH;

  randomSeed(analogRead(0));

  int last = -1;
  for(int i = 0; i < turnsAway; i++){
    int button = -1;
    while(button == last)
      button = BUTTON_FROM_COLOR(random(4));
    
    static char buf[20];
    sprintf(buf, "Pressing button %i", button);
    submitButton(button);
  }

  showCurrentState();
}

bool LogicPuzzle::solved(){
  bool val = true;
  
  for(int i = 0; i < 4 ; i++)
    val = val && currentState[i];

  return val;
}

void LogicPuzzle::submitButton(int button){
  int color = COLOR_FROM_BUTTON(button);
  switch(color){
  case RED:
    LogicPuzzle::toggle(YELLOW);
    LogicPuzzle::toggle(BLUE);
    break;
  case YELLOW:
    LogicPuzzle::toggle(YELLOW);
    LogicPuzzle::toggle(GREEN);
    break;
  case GREEN:
    LogicPuzzle::toggle(BLUE);
    LogicPuzzle::toggle(RED);
    break;
  case BLUE:
    LogicPuzzle::toggle(RED);
    LogicPuzzle::toggle(GREEN);
    break;
  }

  showCurrentState();
}

void LogicPuzzle::toggle(int which){
  currentState[which] = !currentState[which];
}

void LogicPuzzle::showCurrentState(){
  Serial.println("*** CURRENT STATE ***");
  for(int i = 0; i < 4; i++){
    static char buf[6];
    sprintf(buf, "%i \t %i", i, currentState[i]);
    Serial.println(buf);
    digitalWrite(LED_FROM_COLOR(i), currentState[i]);
  }
}
