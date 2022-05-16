// 初期化の処理を書く
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

// 繰り返される処理を書く
void loop() {
  // put your main code here, to run repeatedly:
  // 13番ピンを１（HIGH)にする。=>点灯させる
  digitalWrite(13, HIGH);
  // 500ミリ秒（0.5秒）待つ
  delay(500);
  // 13番ピンを０（LOW）にする。=>消灯する
  digitalWrite(13, LOW);
  // 500ミリ秒待機
  delay(500);
}
