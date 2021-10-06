// Include the Servo library
//#include <Sleep_n0ml.h>
#include <Servo.h> 

Servo Servo1;
//Sleep sleep;

void setup()
 {
  // We need to attach the servo to the used pin number
  Servo1.attach(9);
 //sleep.pwrDownMode();
}

void loop(){
 //sleep.sleepDelay(2000);
 //how long the servo motor will take to get to the next position
 Servo1.writeMicroseconds(1000);
 //the angle that the servo motor is going to 
  Servo1.write(0);
 //the time in microseconds the servo motor takes from one angle to the next
  delay(2000);
  //the angle that the servo motor is going to 
  Servo1.write(90);
  delay(2000);
  //sleep.sleepDelay(2000);
  Servo1.write(180);
  delay(2000);
  //sleep.sleepDelay(2000);

 // Servo1.write(180);
 // delay(4000);
//  Servo1.write(0);
//  delay(2000);
  exit(0);
}
