#include <Servo.h>
Servo myServo;

void setup()
{
myServo.attach (6);
}

void loop()
{
myServo.write(HIGH);
}
