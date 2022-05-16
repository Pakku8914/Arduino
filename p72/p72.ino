// フェード時間の設定
#define FADE_TIME 2
//ピン番号の配列
int led_pins[] = {5,6,9,10};

// 初期化
void setup() {
  // for文で使う変数を定義
  int i;
  for(i=0;i<4;i++){
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  int i,j;

  //LEDを明るくする
  for(j=0;j<4;j++){
    for(i=0;i<256;i++){
      analogWrite(led_pins[j],i);
      delay(FADE_TIME);
    }
  }
  //LEDを暗くする
  for(j=0;j<4;j++){
    for(i=255;i>-1;i--){
      analogWrite(led_pins[j],i);
      delay(FADE_TIME);
    }
  }
}
