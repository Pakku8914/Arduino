#define LED_PIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputchar;
  inputchar = Serial.read();
  if(inputchar != -1){
    switch(inputchar){
      case 'o':
        Serial.print("LED ON\n");
        digitalWrite(LED_PIN, HIGH);
        break;
      case 'p':
        Serial.print("LED OFF\n");
        digitalWrite(LED_PIN, LOW);
        break;
    }
  }
}
