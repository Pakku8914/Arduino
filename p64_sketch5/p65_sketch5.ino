#define LED_PIN1 9
#define LED_PIN2 10

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 出力値
  int i;
  // 0 ~ 255の間でLEDを点灯
  for(i = 0;i < 256; i++) {
    analogWrite(LED_PIN1, i);
    analogWrite(LED_PIN2, i);
    delay(10);
  }
}
