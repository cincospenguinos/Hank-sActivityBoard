#include "LogicPuzzle.h"
#include "Arduino.h"
#include "header.h"

LogicPuzzle::LogicPuzzle(int j){}

void LogicPuzzle::newLogicPuzzle(int turnsAway){
  for(int i = 0; i < 4; i++)
    currentState[i] = HIGH;

  randomSeed(analogRead(0));
  for(int i = 0; i < turnsAway; i++)
    submitButton(random(4));

  showCurrentState();
}

void LogicPuzzle::submitButton(int button){
  int color = COLOR_FROM_BUTTON(button);
  switch(color){
  case RED:
    toggle(YELLOW);
    toggle(BLUE);
    break;
  case YELLOW:
    toggle(YELLOW);
    toggle(GREEN);
    break;
  case GREEN:
    toggle(BLUE);
    toggle(RED);
    break;
  case BLUE:
    toggle(RED);
    toggle(GREEN);
    break;
  }

  showCurrentState();
}

void LogicPuzzle::toggle(int which){
  currentState[which] = !currentState[which];
}

void LogicPuzzle::showCurrentState(){
  for(int i = 0; i < 4; i++)
    digitalWrite(LED_FROM_COLOR(i), currentState[i]);
}
