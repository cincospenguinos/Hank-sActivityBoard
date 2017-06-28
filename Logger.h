/**
 * Logger.h
 * Created by Andre LaFleur on 28 June 2017
 * 
 * Static class with static functions to help me debug stuff.
 */

#ifndef Logger_h
#define Logger_h

class Logger{
  public:
    static void info(char *message);
    static void error(char *message);
};
#endif
