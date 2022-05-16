// 13番ピンに「LED_PIN」という名前をつける
#define LED_PIN 13

// 初期化の処理を書く
void setup() {
  // change( 13 => LED_PIN ) => 名前をつけたので、それを使用
  pinMode(LED_PIN, OUTPUT);
  // シリアルポートを9600bpsで初期化
  Serial.begin(9600);
}

// 繰り返される処理を書く
void loop() {
  int inputchar;
  // シリアルポートから1文字読み込み
  // 読み込むものがない場合 -1 を返す
  inputchar = Serial.read();

  // 読み込むものがあるとき
  if(inputchar != -1){
    switch(inputchar) {
      // 入力された文字が o なら・・・
      case 'o':
        Serial.print("LED ON\n");
        // LED点灯
        digitalWrite(LED_PIN, HIGH);
        break;
      // 入力された文字が p なら・・・
      case 'p':
        Serial.print("LED OFF\n");
        // LED消灯
        digitalWrite(LED_PIN, LOW);
        break;
    }
  }
}
