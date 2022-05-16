#define LED10 10
#define LED9 9

void setup() {
  // put your setup code here, to run once:
  pinMode(LED10, OUTPUT);
  pinMode(LED9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite: PWMを使用して明るさを調節できる(0 ~ 255)
  analogWrite(LED10, 255);
  analogWrite(LED9, 96);
}
