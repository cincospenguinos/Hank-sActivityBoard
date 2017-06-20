/**
 * Simon.h
 * 
 * A simple game of Simon for Hank to play.
 * 
 * YELLOW = 0
 * BLUE = 1
 * GREEN = 2
 * RED = 3
 */
#ifndef Simon_h
#define Simon_h
#include "Buzzer.h"
#include "Arduino.h"

class Simon {
  public:
    static const int PUZZLE_LENGTH = 10;
    
    Simon(Buzzer b);
    void newPuzzle();
    void showStartup(Buzzer b);
    int submitButton(int button, Buzzer b);
    void showCurrentPuzzle(Buzzer b);
  private:
    int puzzle[PUZZLE_LENGTH];
    int endOfTurnIndex = 2;
    int currentTurnIndex = 0;
    void showSuccess(Buzzer b);
    void showFailure(Buzzer b);
    void showWin(Buzzer b);
    void showColor(int color, int noteLength, Buzzer b);
    const char pitches[4] = { 'c', 'd', 'e', 'g' };
};
#endif
