// LED
#define LED_PIN 10
//CdS
#define CDS_IN 0
// 設定値
#define SET_POT 1

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int brightness, set_val;
  // 光の大きさを取得
  brightness = analogRead(0);
  //半固定抵抗値を取得
  set_val = analogRead(1);
  // 半固定抵抗値の抵抗値が
  if(brightness<set_val){
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN,LOW);
  }
}
