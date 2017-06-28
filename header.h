/**
 * header.h
 * 
 * Header file with definitions for the entire project.
 */
#ifndef header_h
#define header_h

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
#define TOTAL_MODES 4
#define MODE_MUSIC 0
#define MODE_INSTRUMENT 1
#define MODE_LOGIC 2
#define MODE_SIMON 3

// Vars for logic puzzle and simon
static const int YELLOW = 0;
static const int BLUE = 1;
static const int GREEN = 2;
static const int RED = 3;

// A couple macros
#define LED_FROM_COLOR(color) (color + 4)
#define COLOR_FROM_BUTTON(button) (button - 10)
#define BUTTON_FROM_COLOR(color) (color + 10)

#endif
