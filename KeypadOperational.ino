#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

int lcdAddress = 0x27;
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns
LiquidCrystal_I2C *lcd;
const int trigPin = 22;
const int echoPin = 24;
long duration;
float distance;
int distanceInt;
Servo Servo1;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {39, 41, 43, 45}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {47, 49, 51, 53}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String inputString;
long inputInt;

void setup() {
  Serial.begin(9600);
  inputString.reserve(10); // maximum number of digit for a number is 10, change if needed
  lcd = new LiquidCrystal_I2C(lcdAddress, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  lcd->begin(16, 2);
  lcd->home();
  lcd->print("Key Pad Test!");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Servo1.attach(9);
  delay(3000);
}

void loop() {
  lcd->clear();
  lcd->print("Press a key");
  char key = keypad.getKey();
  

  if (key) {
    Serial.println(key);
    lcd->clear();
    lcd->print(key);
    
    switch(key){
      case '1' :
        lcd->print(" is lonely");
        servoMotorTest();
        break;
      case '2' :
      lcd->print(" is a couple");
          runPing();
        break;
      case '3' :
      lcd->print(" is magic");
        break;
      case '4' :
      lcd->print(" makes quartets");
        break;
      case '5' :
      lcd->print(" 10 15 20");
        break;
      case '6' :
      lcd->print(" is all there is");
        break;
      case '7' :
      lcd->print(" is lucky");
        break;
      case '8' :
      lcd->print(" is double four");
        break;
      case '9' :
      lcd->print(" is mighty");
        break;
      case '0' :
      lcd->print(" my hero");
        break;
      case 'A' :
      lcd->print("LL YOUR BASE!");
        break;
      case 'B' :
      lcd->print("ACK AWAY!");
        break;
      case 'C' :
      lcd->print("IRCE!");
        break;
      case 'D' :
      lcd->print("'OH!");
        break;
      
    }
   delay(1000);
  }
  delay(100);
}

void servoMotorTest(){
  Servo1.writeMicroseconds(1000);
  Servo1.write(0);
  delay(2000);
  Servo1.write(45);
  delay(2000);
  Servo1.write(90);
  delay(2000);
  //sleep.sleepDelay(2000);
  Servo1.write(180);
  delay(2000);
  Servo1.write(0);
  delay(2000);
}

void runPing(){
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
  delay(500);
}
