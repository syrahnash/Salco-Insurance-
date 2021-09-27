#include "KNWRobot.h"

KNWRobot robot;

void setup() {
  // put your setup code here, to run once:
  robot.setupPing(8,8);
  int keyPadNumber = 0;


void loop() {
  // put your main code here, to run repeatedly:
  robot.getPing(8);
  keyPadNumber = robot.getKeypadInput (20,21)
