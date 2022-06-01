void setup() {
  Serial.begin(9600);
}

void loop() {
  int i;
  // 0番を読み込む
  i = analogRead(0);

  Serial.print(i, DEC);
  Serial.print("\n");

  delay(1000);
}

// 明るければ、シリアルモニタには数値が高いものが出る
// 暗ければ、シリアルモニタでの数値は低くなる。
