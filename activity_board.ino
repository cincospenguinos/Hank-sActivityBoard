/**
 * HANK'S ACTIVITY BOARD
 * 
 * Sketch for the arduino portion of Hank's activity board. The
 * following are some ideas that this can implement:
 * 
 * -> Play music when a button is pressed
 * -> Play Simon when a button is pressed
 * -> Logic game to turn on all the LEDs
 */
#include "Buzzer.h"

// All the buttons
#define RED_BUTTON 13
#define GREEN_BUTTON 12
#define BLUE_BUTTON 11
#define YELLOW_BUTTON 10
#define MODE_BUTTON 2

// All the LEDs
#define RED_LED 7
#define GREEN_LED 6
#define BLUE_LED 5
#define YELLOW_LED 4

// The buzzer
#define BUZZER 3

// Actvity modes
#define MODE_MUSIC 0
#define MODE_SIMON 1
#define MODE_LOGIC 2

// Macros
#define button_pressed(BUTTON) digitalRead(BUTTON) == LOW

int mode = 0; // the current mode of the board
Buzzer buzzer(BUZZER);

//void buttonTest();

void setup() {
  // Let's setup the buttons
  pinMode(RED_BUTTON, INPUT);
  pinMode(GREEN_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(MODE_BUTTON, INPUT);

  // Setup all the LEDs
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  
}

//void buttonTest(){
//  if(button_pressed(RED_BUTTON)){
//    digitalWrite(RED_LED, HIGH);
//    delay(30);
//    digitalWrite(RED_LED, LOW);
//    delay(30);
//  }
//
//  if(button_pressed(GREEN_BUTTON)){
//    digitalWrite(GREEN_LED, HIGH);
//    delay(30);
//    digitalWrite(GREEN_LED, LOW);
//    delay(30);
//  }
//
//  if(button_pressed(BLUE_BUTTON)){
//    digitalWrite(BLUE_LED, HIGH);
//    delay(30);
//    digitalWrite(BLUE_LED, LOW);
//    delay(30);
//  }
//
//  if(button_pressed(YELLOW_BUTTON)){
//    digitalWrite(YELLOW_LED, HIGH);
//    delay(30);
//    digitalWrite(YELLOW_LED, LOW);
//    delay(30);
//  }
//
//  delay(100);
//}
