int motorPin = 2;
void setup ()
{
  pinMode(motorPin, OUTPUT);
}

void loop (){
  digitalWrite (2,255);
  delay(10000);
  digitalWrite (2,200);
  delay(10000);
  digitalWrite (2,150);
  delay(10000);
}
