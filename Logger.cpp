#include "Logger.h"
#include "Arduino.h"

static void Logger::info(char *message){
  Serial.print("[INFO] ");
  Serial.println(message);
}

static void Logger::error(char *message){
  Serial.print("[ERROR] ");
  Serial.println(message);
}
