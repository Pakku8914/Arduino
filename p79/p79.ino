#define LED_PIN 9

int led_pins[] = {9,10};

void setup() {
  int i;
  for(i=0;i<2;i++){
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(led_pins[1], HIGH);
  int i;
  int j;
  for(j=0;j<2;j++){
    for(i=0;i<256;i++){
    analogWrite(led_pins[0], i);
    delay(5);
    }
  }
}
