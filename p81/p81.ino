#define FADE_TIME 10

int led_pins[] = {9,10,11};

void setup() {
  int i,j;
  //LEDを明るくする
  for(j=0;j<3;j++){
    for(i=0;i<256;i++){
      analogWrite(led_pins[j],i);
      delay(FADE_TIME);
    }
  }
  //LEDを暗くする
  for(j=0;j<3;j++){
    for(i=255;i>-1;i--){
      analogWrite(led_pins[j],i);
      delay(FADE_TIME);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
