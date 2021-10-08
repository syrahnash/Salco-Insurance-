#include <Servo.h>
Servo myservo;
void setup() {
 myservo.attach(6);
 //this attach the DC Motor to the correct pin on the arduino
 // we will need more than 2 DC motor

}

void loop() {
myservo.write(110);
// this set the speed of the DCmotor to 110
delay(5000);
 myservo.write(45);
// this set the speed to 45 and goes backward
// DC motor between 0-90 goes backward and from 90-240 goes forward
}
