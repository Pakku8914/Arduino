#include <RCS620S.h>
#include <Servo.h>

// サーボのインスタンスを宣言
Servo servo1;

#define COMMAND_TIMEOUT  400
#define POLLING_INTERVAL 500
#define SERVO1 10

RCS620S rcs620s;

enum STATE {
  Lock,
  Read,
  Open
};

// 状態遷移変数
enum STATE state;

// ------------------------------------------------
// | 引数 | 読み取ったカード番号                     |
// ------------------------------------------------
// | 処理 | 読み取ったカード番号が登録されていれば     |
// | 　　 | stateをOpenにする　                     |
// ------------------------------------------------
void card_reading(int card_num){
  // IDmを保存するための変数
  String IDm = "";
  // 1byteを16進数で一時保存するための配列
  char buf[2];

  // FeliCaがタッチされた場合
  if (ret) {
    // IDmを取得する
    // 8byteで保存されているため、1byteずつ読み込む
    for (int i = 0; i < 8; i++) {
      // buf配列にコピー
      // %02X => 2桁の16進数で出力(英大文字)
      // 第2引数で指定されたフォーマットで、rcs620s.idm[i]を出力し、それをbufに保存
      sprintf(buf, "%02X", rcs620s.idm[i]);
      IDm += buf;
    }
    Serial.println("\n#########################");
    // IDm（カード番号）を表示する
    Serial.println(IDm);
    Serial.println("#########################");
    state = Open;
  }
  else {
    Serial.println("カード情報無し");
  }
}

void setup() {
  // 状態の初期状態：Lock
  state = Lock;
  
  //サーボモーターを接続したピンを使用
  servo1.attach(SERVO1);
  
  int ret;

  //シリアルポート初期化
  Serial.begin(115200);
  Serial.println("Initializing UART...OK");

  Serial.begin(115200); // initDevice()を呼び出す前に必ず呼び出し
  ret = rcs620s.initDevice(); // RC-S620Sの初期化 return...成功: 1, 失敗: 0
  while (!ret) {}
  rcs620s.timeout = COMMAND_TIMEOUT;
  Serial.println("Initializing rcs620s...OK");

}

// #############################
// #  uint8_t idm[8]; 配列idm   #
// #  捕捉したカードの IDm      #
// #############################
// IDmの上位2バイトの値を製造者コード、続く6倍とをカード識別番号
// 012E4CC89A093A47 カード番号
// 012E が製造者コード 以下カード識別番号

void loop() {
  switch(state){
// ##############
// #   施錠状態   #
// ##############
    case Lock:
      // サーボを0度の位置へ移動
      servo1.write(0);
      state = Read;
      delay(1000);
      break;
      
//##################
//# カード読み取り状態 #
//##################
    case Read:
      // pollingが成功したかどうか？
      // ## 成功：１、失敗：０ ##
      int ret;

// #############
// # polling() #
// #############
// FeliCaのタッチ状態を得る
// FeliCaカードの補足を実行する
// ---------------------------------------------------
// 成功：return 1
//      配列idmとpmmにカードのIDmとPMmが代入される
//----------------------------------------------------
// 失敗: return 0
// ---------------------------------------------------
      ret = rcs620s.polling();
    
      card_reading(ret);

      //停波
      rcs620s.rfOff();
      delay(POLLING_INTERVAL);
      break;
//#################
//#    解錠状態    #
//#################
    case Open:
      servo1.write(180);
      for(int i = 0; i < 15000;) {
        int ret = rcs620s.polling();
        if (ret) {
          card_reading(ret);
          break;
        }
        else {
          delay(POLLING_INTERVAL);
          i += POLLING_INTERVAL;
        }
      }
      break;
  }
  
}
