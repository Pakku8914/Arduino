#include <Servo.h>

// サーボのインスタンスを宣言
Servo servo1;

#define SERVO1 10

void setup() {
  //サーボモーターを接続したピンを使用
  servo1.attach(SERVO1);  
}

void loop() {
  // サーボを30度の位置へ移動
  servo1.write(0);
  delay(1000);
  // サーボを150度の位置へ移動
  servo1.write(180);
  delay(1000);
}
