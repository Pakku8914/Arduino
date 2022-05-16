#define LED_PIN 10

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  //LEDを点灯
  digitalWrite(LED_PIN, HIGH);
  // 500ms待機
  delay(500);
  //LEDを消灯
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
