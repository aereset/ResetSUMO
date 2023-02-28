#include <Arduino.h>
#include "pinoutRobot.h"
#include "radioRobot.h"
#include "motion.h"

void setup() {
  Serial.begin(9600);
  setupMotores();
}

void loop() {
  moveMotor('L', 1, 255);
  moveMotor('R', 1, 255);
  delay(2000);
  
  moveMotor('L', 1, 0);
  moveMotor('R', 1, 0);
  delay(2000);
  
  
  moveMotor('L', 0, 255);
  moveMotor('R', 0, 255);
  delay(2000);
  
  moveMotor('L', 1, 0);
  moveMotor('R', 1, 0);
  delay(2000);
}