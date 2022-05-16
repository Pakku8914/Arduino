#define LED_PIN_10 10
#define LED_PIN_9 9

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN_10, OUTPUT);
  pinMode(LED_PIN_9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // pin10LEDを点灯
  digitalWrite(LED_PIN_10, HIGH);
  // pin9LEDを点灯
  digitalWrite(LED_PIN_9, HIGH);
  delay(500);

  // 消灯
  digitalWrite(LED_PIN_10, LOW);
  digitalWrite(LED_PIN_9, LOW);
  delay(500);
}
