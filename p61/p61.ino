#define LED10 10
#define LED9 9

void setup() {
  // put your setup code here, to run once:
  pinMode(LED10, OUTPUT);
  pinMode(LED9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 10を点灯
  digitalWrite(LED10, HIGH);
  digitalWrite(LED9, LOW);
  delay(500);

  digitalWrite(LED10, LOW);
  digitalWrite(LED9, HIGH);
  delay(500);
}
