/**
 * LogicPuzzle.h
 * Created by Andre LaFleur on 20 June 2017
 * 
 * Simple Logic Puzzle for Hank to play with.
 */
#ifndef LogicPuzzle_h
#define LogicPuzzle_h


class LogicPuzzle {
  public:
    LogicPuzzle(int);
    void newLogicPuzzle(int turnsAway);
    void submitButton(int which);
  private:
    bool currentState[4];
    void toggle(int which);
    void showCurrentState();
};

#endif
