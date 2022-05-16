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
  int i, j;
  // 0 ~ 255の間でLEDを点灯
  for(i = 0;i < 256; i++) {
    //iの値でLEDを点灯させる
    analogWrite(LED_PIN1, i);
    j = 255 - i;
    // jの値でLEDを点灯させる
    analogWrite(LED_PIN2, j);
    delay(10);
  }
  for(i = 255; i > -1; i--) {
    // iの値でLEDを消灯していく
    analogWrite(LED_PIN1, i);
    j = 255 -i;
    // jの値でLEDを消灯していく
    analogWrite(LED_PIN2, j);
    delay(10);
  }
}
