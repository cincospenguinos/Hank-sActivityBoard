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

class Simon {
  public:
    static const int YELLOW = 0;
    static const int BLUE = 1;
    static const int GREEN = 2;
    static const int RED = 3;
    static const int PUZZLE_LENGTH = 10;
    
    Simon(Buzzer b);
    void newPuzzle();
    void showStartup(Buzzer b);
    void submitButton(int button, Buzzer b);
    void showCurrentPuzzle(Buzzer b);
  private:
    int puzzle[PUZZLE_LENGTH];
    int currentTurnIndex = 2;
    void showSuccess(Buzzer b);
    void showFailure(Buzzer b);
    void showWin(Buzzer b);
    void showColor(int color, int noteLength, Buzzer b);
    int getLedFromColor(int color);
    int getColorFromButton(int button);
    const char pitches[4] = { 'c', 'd', 'e', 'g' };
};
#endif
