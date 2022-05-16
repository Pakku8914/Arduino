// 13番ピンに「LED_PIN」という名前をつける
#define LED_PIN 13

// 初期化の処理を書く
void setup() {
  // change( 13 => LED_PIN ) => 名前をつけたので、それを使用
  pinMode(LED_PIN, OUTPUT);
}

// 繰り返される処理を書く
void loop() {
  // put your main code here, to run repeatedly:
  // 13番ピンを１（HIGH)にする。=>点灯させる
  digitalWrite(LED_PIN, HIGH);
  // 500ミリ秒（0.5秒）待つ
  delay(200);
  // 13番ピンを０（LOW）にする。=>消灯する
  digitalWrite(LED_PIN, LOW);
  // 500ミリ秒待機
  delay(200);
}
