#include <RCS620S.h>
#include <inttypes.h>
#include <string.h>

#define COMMAND_TIMEOUT  400
#define PUSH_TIMEOUT    2100
#define POLLING_INTERVAL 500

//#define LED_PIN 13

RCS620S rcs620s;
int waitCardReleased = 0;

void setup()
{
  int ret;
  
  //シリアルモニタ用のシリアル初期化
  Serial.begin(9600);
  //RCS602S用のシリアル初期化
  Serial.begin(115200);

  //RCS602Sの初期化
  ret = rcs620s.initDevice();
  while (!ret) {}
}

void loop()
{
  int ret;
  String IDm[8];
  char buf[2];
  
  rcs620s.timeout = COMMAND_TIMEOUT;
  //Felica状態の取得
  ret = rcs620s.polling();
  if (ret) {
    //Felicaがタッチされた場合
    for (int i = 0; i < 8; i++) {
      sprintf(buf, "%02X", rcs620s.idm[i]);
      Serial.println(buf);
    }
    
    
  } 
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}
