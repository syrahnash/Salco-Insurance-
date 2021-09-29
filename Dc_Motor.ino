int pin = 6;

void setup (){
  pinMode (pin, OUTPUT);
}

void loop (){
  analogWrite (pin, 90);

}
