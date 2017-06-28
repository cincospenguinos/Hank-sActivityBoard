#include "LogicPuzzle.h"
#include "Arduino.h"
#include "header.h"
#include "Logger.h"

LogicPuzzle::LogicPuzzle(int j){}

void LogicPuzzle::newLogicPuzzle(int turnsAway){
  for(int i = 0; i < 4; i++)
    currentState[i] = HIGH;

  randomSeed(analogRead(0));
  
  Logger::info("Creating puzzle...");
  for(int i = 0; i < turnsAway; i++){
    int button = BUTTON_FROM_COLOR(random(4));
    static char buf[20];
    sprintf(buf, "Pressing button %i", button);
    Logger::info(buf);
    submitButton(button);
  }

  showCurrentState();
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
  Logger::info(" ***CURRENT STATE*** ");
  for(int i = 0; i < 4; i++){
    static char buf[6];
    sprintf(buf, "%i \t %i", i, currentState[i]);
    Logger::info(buf);
    digitalWrite(LED_FROM_COLOR(i), currentState[i]);
  }
}
