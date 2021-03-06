#include <RCS620S.h>

#define COMMAND_TIMEOUT  400
#define POLLING_INTERVAL 2000

RCS620S rcs620s;

void setup() {
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
// #  捕捉したカードの IDm です。 #
// #############################
// IDmの上位2バイトの値を製造者コード、続く6倍とをカード識別番号
//  012E4CC89A093A47　カード番号
// 012E が製造者コード 以下カード識別番号

void loop() {
  // pollingが成功したかどうか？
  // ## 成功：１、失敗：０ ##
  int ret ;
  // IDmを保存するための変数
  String IDm = "";
  // 1byteを16進数で一時保存するための配列
  char buf[2];

  // #############################
  // #          polling()        #
  // #############################
  // FeliCaのタッチ状態を得る
  // FeliCaカードの補足を実行する
  // ---------------------------------------------------
  // 成功：return 1
  //      配列idmとpmmにカードのIDmとPMmが代入される
  //----------------------------------------------------
  // 失敗: return 0
  // ---------------------------------------------------
  ret = rcs620s.polling();

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
    // IDmを表示する
    Serial.println(IDm);
    Serial.println("#########################");
  }
  else {
    Serial.println("カード情報無し");
  }

  //停波
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}
