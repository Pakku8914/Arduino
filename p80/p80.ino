#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int i;
  for(i=255;i>-1;i--){
    analogWrite(LED_PIN, i);
    delay(5);
  }
}
