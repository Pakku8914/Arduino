#define LED10 10
#define LED9 9
#define LED6 6
#define LED5 5

void setup() {
  pinMode(LED10, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  int i,j;

  // LED10を明るくする
  for(i = 0; i < 256; i++ ){
    analogWrite(LED10, i);
    delay(5);
  }
  // LED9を明るくする
  for(i = 0; i < 256; i++) {
    analogWrite(LED9, i);
    delay(5);
  }
  // LED6を明るくする
  for(i = 0; i < 256; i++) {
    analogWrite(LED6, i);
    delay(5);
  }
  // LED5を明るくする
  for(i = 0;i < 256; i++) {
    analogWrite(LED5, i);
    delay(5);
  }

  // LED10を暗くする
  for(i = 255; i > -1; i-- ){
    analogWrite(LED10, i);
    delay(5);
  }
  // LED9を暗くする
  for(i = 255; i > -1; i-- ){
    analogWrite(LED9, i);
    delay(5);
  }
  // LED6を暗くする
  for(i = 255; i > -1; i-- ){
    analogWrite(LED6, i);
    delay(5);
  }
  // LED5を暗くする
  for(i = 255; i > -1; i-- ){
    analogWrite(LED5, i);
    delay(5);
  }
}
