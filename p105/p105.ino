#define LM35_IN 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int temp;
  
  temp = analogRead(LM35_IN);
  Serial.print(temp, DEC);
  Serial.print("\n");
  delay(1000);
}

//出力された値に0.0048をかけ、100倍した値が温度
