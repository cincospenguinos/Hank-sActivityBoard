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
#include "header.h"
#include "Simon.h"

// Macros
#define button_pressed(BUTTON) digitalRead(BUTTON) == LOW

// Some member variables
int mode = 0; // the current mode of the board
Buzzer buzzer(BUZZER);
Simon simon(buzzer);

// Function declarations
int buttonPressed();

void setup() {
  Serial.begin(19200); // For debugging
  
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
  int button = buttonPressed();

  Serial.print("Button pressed: ");
  Serial.println(button);

  if(button == MODE_BUTTON){
    mode = (mode + 1) % TOTAL_MODES;

    if(mode == MODE_SIMON){
      Serial.println("Creating new Simon puzzle...");
      simon.newPuzzle();
      simon.showStartup(buzzer);
      delay(1000);
    }
  }
  
  switch(mode){
  case MODE_MUSIC:
    break;
  case MODE_SIMON:
    break;
  case MODE_LOGIC:
    break;
  }

  delay(100);
}

////////// VARIOUS FUNCTIONS ////////////

/* Returns the button that is currently pressed, or -1 if none is pressed. */
int buttonPressed(){
  if(digitalRead(MODE_BUTTON) ==  LOW)
    return MODE_BUTTON;
  if(digitalRead(RED_BUTTON) ==  LOW)
    return RED_BUTTON;
  if(digitalRead(GREEN_BUTTON) ==  LOW)
    return GREEN_BUTTON;
  if(digitalRead(BLUE_BUTTON) ==  LOW)
    return BLUE_BUTTON;
  if(digitalRead(YELLOW_BUTTON) ==  LOW)
    return YELLOW_BUTTON;

  return -1;
}
