int led_pins[] = {5,10,11};

void setup() {
  int i;
  for(i=0;i<3;i++){
    pinMode(led_pins[i],OUTPUT);
  }
}

void loop() {
  int i,j;

  for(j = 0; j<3; j++){
    digitalWrite(led_pins[j], LOW);
    delay(500);
    digitalWrite(led_pins[j], HIGH);
    delay(500);
  }
}
