//LED
#define LED_PIN 10
//cds
#define CDS_IN 0
//設定
#define SET_POT 1

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int brightness, set_val;
  int upper,lower;

  brightness = analogRead(0);
  set_val = analogRead(1);

  //明るい側の値を入力+10に
  upper = set_val + 10;
  //上限設定
  if(upper>1023) upper = 1023;
  
  //暗い側の値を入力-10に
  lower = set_val - 10;
  //下限設定
  if(lower < 0) lower = 0;

  if(brightness<lower){
    digitalWrite(LED_PIN, HIGH);
  }
  if(brightness>upper){
    digitalWrite(LED_PIN, LOW);
  }
}
