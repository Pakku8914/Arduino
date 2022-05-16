#define PIEZO 13

#define DELAY_TIME 1

void setup() {
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  delay(DELAY_TIME);
  digitalWrite(PIEZO, HIGH);
  delay(DELAY_TIME);
  digitalWrite(PIEZO, LOW);
  
}
