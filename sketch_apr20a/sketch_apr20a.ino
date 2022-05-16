#define LED_PIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode (LED_PIN, OUTPUT); //13番ピンをデジタル出力に設定する
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH); // LEDを点灯する
  delay(1000); // 1秒待機する（1000ミリ秒）
  digitalWrite(LED_PIN, LOW); //LEDを消灯する
  delay(1000);// 1秒待機する
}
