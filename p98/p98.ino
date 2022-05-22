#define LED_PIN 10

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int i;
  i = analogRead(0);

  if(i < 400){
    digitalWrite(LED_PIN,HIGH);
  }
  else {
    digitalWrite(LED_PIN,LOW);
  }
}
