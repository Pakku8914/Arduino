#define PIEZO 13

#define DELAY_TIME 500

void setup() {
  pinMode(PIEZO,OUTPUT);
}

void loop() {
  digitalWrite(PIEZO,HIGH);
  delayMicroseconds(DELAY_TIME);
  digitalWrite(PIEZO,LOW);
  delayMicroseconds(DELAY_TIME);
}
