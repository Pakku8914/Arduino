void setup() {
  Serial.begin(9600);
}

void loop() {
  int i;
//  A0の値を読み込み
  i = analogRead(0);
//  iの値を10進数としてシリアルポートに送る
  Serial.print(i, DEC);
//  改行
  Serial.print("\n");

  delay(1000);
}
