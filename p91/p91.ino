#define PIEZO 13

#define DELAY_TIME1 400
#define DELAY_TIME2 500

void setup() {
  pinMode(PIEZO, OUTPUT);
}

void loop() {
  int i;

  for(i=0;i<400;i++){
    digitalWrite(PIEZO, HIGH);
    delayMicroseconds(DELAY_TIME1);
    digitalWrite(PIEZO, LOW);
    delayMicroseconds(DELAY_TIME1);
  }

  for(i=0;i<200;i++){
    digitalWrite(PIEZO, HIGH);
    delayMicroseconds(DELAY_TIME2);
    digitalWrite(PIEZO,LOW);
    delayMicroseconds(DELAY_TIME2);
  }
}
