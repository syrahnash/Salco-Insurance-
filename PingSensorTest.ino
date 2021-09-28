#include "KNWRobot.h"
#include <LiquidCrystal_I2C.h>

int lcdAddress = 0x28;
long distance = 0.0;

KNWRobot *robot; 
LiquidCrystal_I2C *lcd;

void setup() {
  // put your setup code here, to run once:
  robot->setupPing(22, 22);
  lcd = new LiquidCrystal_I2C(lcdAddress, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  lcd->begin(16, 2); // initialize the lcd. Don't worry about the int values above.
  lcd->home(); 
  lcd->print("Ping sensor test"); // Print a welcome message
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd->clear();               // Clear out the screen every iteration
  lcd->setCursor(0, 0);       // Moves the cursor to column 0, row 0
  lcd->print("Distance:");    // Print out a title on row 0
  lcd->setCursor(0, 1);       // Moves the cursor to column 0, row 1
  distance = robot->getPing(22); // Gets the distance away from the ping sensor 
  lcd->print(distance);      // Print out the number of times we've looped

  delay(2000);    // Delay for two seconds

}
