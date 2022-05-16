#define FADE_TIME 10

int led_pins[] = {9,10,11};

void setup() {
  int i;

  //未使用アナログで乱数の種を初期化
  randomSeed(analogRead(0));

  //LEDのピンを出力に
  for(i=0;i<3;i++){
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  int i,j;

  //乱数で使用するピンをデタラメにする
  for(j=0;j<3;j++){
    //pinの範囲は9,10,11
    led_pins[j] = random(9,12);
  }

  //LEDを明るくする
  for(j=0;j<3;j++){
    for(i=0;i<256;i++){
      analogWrite(led_pins[j], i);
      delay(FADE_TIME);
    }
  }

  //LEDを暗くする
  for(j=0;j<3;j++){
    for(i=255;i>-1;i--){
      analogWrite(led_pins[j], i);
      delay(FADE_TIME);
    }
  }
}
