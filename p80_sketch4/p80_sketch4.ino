#define LED_PIN1 9
#define LED_PIN2 10

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  int i,j;
  for(i=255;i>-1;i--){
    analogWrite(LED_PIN1, i);
    j=255-i;
    analogWrite(LED_PIN2, j);
    delay(5);
  }
}
