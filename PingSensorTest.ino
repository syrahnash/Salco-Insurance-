#include <LiquidCrystal_I2C.h>

int lcdAddress = 0x27;
long duration;
float distance;
int distanceInt;

LiquidCrystal_I2C *lcd;
const int trigPin = 22;
const int echoPin = 24;

void setup() {
  // put your setup code here, to run once:
  lcd = new LiquidCrystal_I2C(lcdAddress, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  lcd->begin(16, 2); // initialize the lcd. Don't worry about the int values above.
  lcd->home(); 
  lcd->print("Ping sensor test"); // Print a welcome message
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  duration = -1;
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd->clear();               // Clear out the screen every iteration
  lcd->setCursor(0, 0);       // Moves the cursor to column 0, row 0
  lcd->print("Distance:");    // Print out a title on row 0
  lcd->setCursor(0, 1);       // Moves the cursor to column 0, row 1
                              // Gets the distance away from the ping sensor 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  if (duration == -1){
    lcd->print("Error");
  }
  else{
    distanceInt = distance;
    lcd->print(distanceInt);
  }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);    // Delay for half a second

}
