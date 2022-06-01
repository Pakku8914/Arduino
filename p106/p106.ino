#include <inttypes.h>
#include <string.h>
#include <avr/pgmspace.h>
#include <RTClib.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <RCS620S.h>
#include <SPI.h>
#include <SD.h>

#define LCD_I2C 0x3F

const char IDm001[] PROGMEM = "0000000000000001";
const char IDm002[] PROGMEM = "0000000000000002";
const char IDm003[] PROGMEM = "0000000000000003";
const char* const IDms[] PROGMEM = { IDm001, IDm002, IDm003 };

const char name001[] PROGMEM = "Dummy1";
const char name002[] PROGMEM = "Dummy2";
const char name003[] PROGMEM = "Dummy3";
const char* const names[] PROGMEM = { name001, name002, name003 };

DateTime *enter_t, *leave_t;
long *last_touch;
long last_touch_unknown;
String last_touch_unknown_IDm = "";
int num_felica;
int r_timer;
int next_tone = 0;

#define COMMAND_TIMEOUT  400
#define POLLING_INTERVAL 200
#define TOUCH_PERIOD 50
#define BUZZER_PERIOD 1
#define SHOW_PERIOD 15
#define SD_CS 53
#define BUZZER_PIN 2
#define ENTER_LED_PIN 3
#define LEAVE_LED_PIN 4
#define ERROR_LED_PIN 5
#define TONE_E5 659
#define TONE_C5 523
#define TONE_F4S 369

RCS620S rcs620s;
LiquidCrystal_I2C lcd(LCD_I2C, 20, 4);
RTC_DS3231 rtc;

// 日付の文字列から年などを取得
int convToNum(char* buf, int start, int digit) {
  int i, num = 0, pow = 1, pos;

  pos = start + digit - 1;
  for (i = 0; i < digit; i++) {
    num += (buf[pos] - '0') * pow;
    pow *= 10;
    pos--;
  }
  return num;
}

void setup()
{
  int i, j, ret, y = 0;
  int ye, mo, da, ho, mi, se;
  char fname[15], buf[100], IDm[17], IDm_buf[17], user[20], pos;
  size_t bc;

  pinMode(ENTER_LED_PIN, OUTPUT);
  pinMode(LEAVE_LED_PIN, OUTPUT);
  pinMode(ERROR_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(ENTER_LED_PIN, LOW);
  digitalWrite(LEAVE_LED_PIN, LOW);
  digitalWrite(ERROR_LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(9600);
  Serial.begin(9600);

  // 変数の初期化
//  num_felica = sizeof(names) / sizeof(char*);
//  enter_t = (DateTime*) malloc(num_felica * sizeof(DateTime));
//  leave_t = (DateTime*) malloc(num_felica * sizeof(DateTime));
//  last_touch = (long*) malloc(num_felica * sizeof(long));
//  for (i = 0; i < num_felica; i++) {
//    last_touch[i] = 0;
//  }
//  last_touch_unknown = 0;
//  r_timer = 0;
  
  // LCDの初期化
//  lcd.init();
//  lcd.backlight();
//  lcd.clear();

  // SDの初期化
//  lcd.setCursor(0, y);
//  if (!SD.begin(SD_CS)) {
//    lcd.print("SD failed!");
//    while (1);
//  }
//  lcd.print("SD init OK");
//  y++;

  // 日時の初期化
//  if (SD.exists("time.txt")) {
//    File f = SD.open("time.txt");
//    f.read(buf, 29);
//    f.close();
//    ye = convToNum(buf, 0, 4);
//    mo = convToNum(buf, 5, 2);
//    da = convToNum(buf, 8, 2);
//    ho = convToNum(buf, 11, 2);
//    mi = convToNum(buf, 14, 2);
//    se = convToNum(buf, 17, 2);
    //setTime(ho, mi, se, da, mo, ye);
//    rtc.adjust(DateTime(ye, mo, da, ho, mi, se));
//    SD.remove("time.txt");
//    lcd.setCursor(0, y);
//    lcd.print("Set time");
//    y++;
//    lcd.setCursor(0, y);
//    sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d", ye, mo, da, ho, mi, se);
//    lcd.print(buf);
//    y++;
//  }
  // RC-S620Sの初期化
  ret = rcs620s.initDevice();
  while (!ret) {}
  rcs620s.timeout = COMMAND_TIMEOUT;
  lcd.setCursor(0, y);
  lcd.print("RC-S620S init ok");
  y++;
  
  // 今日のファイルがあれば、そこから入退室時刻のデータを読み込む
//  DateTime t = rtc.now();
//  sprintf(fname, "%04d%02d%02d", t.year(), t.month(), t.day());
//  strcat(fname, ".csv");
//  if (SD.exists(fname)) {
//    File f = SD.open(fname, FILE_READ);
//    while (f.available()) {
//      bc = f.readBytesUntil(0x0a, buf, 99);
//      buf[bc] = 0;
//      strncpy(IDm, buf, 16);
//      IDm[16] = 0;
//      pos = 17;
//      while (buf[pos] != ',') {
//        user[pos - 17] = buf[pos];
//        pos++;
//      }
//      user[pos - 17] = 0;
//      pos++;
//      for (i = 0; i < num_felica; i++) {
//        strcpy_P(IDm_buf, (char*) pgm_read_word(&IDms[i]));
//        if (strcmp(IDm, IDm_buf) == 0) {
//          ye = convToNum(buf, pos, 4);
//          mo = convToNum(buf, pos + 5, 2);
//          da = convToNum(buf, pos + 8, 2);
//          ho = convToNum(buf, pos + 11, 2);
//          mi = convToNum(buf, pos + 14, 2);
//          se = convToNum(buf, pos + 17, 2);
//          enter_t[i] = DateTime(ye, mo, da, ho, mi, se);
//          pos += 20;          
//          ye = convToNum(buf, pos, 4);
//          mo = convToNum(buf, pos + 5, 2);
//          da = convToNum(buf, pos + 8, 2);
//          ho = convToNum(buf, pos + 11, 2);
//          mi = convToNum(buf, pos + 14, 2);
//          se = convToNum(buf, pos + 17, 2);
//          leave_t[i] = DateTime(ye, mo, da, ho, mi, se);
//          sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d",
//                  enter_t[i].year(), enter_t[i].month(), enter_t[i].day(), 
//                  enter_t[i].hour(), enter_t[i].minute(), enter_t[i].second());
//          sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d",
//                  leave_t[i].year(), leave_t[i].month(), leave_t[i].day(), 
//                  leave_t[i].hour(), leave_t[i].minute(), leave_t[i].second());
//        }
//      }
//
//    }
//    f.close();
//    lcd.setCursor(0, y);
//    lcd.print("Loaded today file");
//  }
//
//  // ディスプレイの初期表示
//  delay(2000);
//  lcd.clear();
//  lcd.setCursor(0, 1);
//  lcd.print("Wait FeliCa");
}

void loop()
{
  int i, ret;
  String IDm = "";
  char buf[30], fname[15], uname[30], IDm_buf[17];
  DateTime t;
  
  // 時刻の表示
  t = rtc.now();
  lcd.setCursor(0, 0);
  sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d", t.year(), t.month(), t.day(), t.hour(), t.minute(), t.second());
  lcd.print(buf);

  // タッチ直後の場合の処理
  if (r_timer > 0) {
    r_timer--;
    if (SHOW_PERIOD - r_timer == 1) {
      if (next_tone) {
        tone(BUZZER_PIN, next_tone);
      }
      else {
        noTone(BUZZER_PIN);
      }
      digitalWrite(ENTER_LED_PIN, 0);
      digitalWrite(LEAVE_LED_PIN, 0);
      digitalWrite(ERROR_LED_PIN, 0);
    }
    if (SHOW_PERIOD - r_timer == 2) {
      noTone(BUZZER_PIN);
    }
    if (r_timer == 0) {
      lcd.setCursor(0, 1);
      lcd.print("Wait FeliCa ");
      lcd.setCursor(0, 2);
      lcd.print("                    ");
    }
  }

  // 短時間での二重タッチを防止する処理
  for (i = 0; i < num_felica; i++) {
    if (last_touch[i] > 0) {
      last_touch[i]--;
    }
  }
  if (last_touch_unknown > 0) {
    last_touch_unknown--;
  }
  
  // FeliCaのタッチ状態を得る
  ret = rcs620s.polling();

  // FeliCaがタッチされた場合
  if(ret) {
    // 今日のファイルがなければ、今日の入退室時刻等の初期化を行う
    sprintf(fname, "%04d%02d%02d", t.year(), t.month(), t.day());
    strcat(fname, ".csv");
    if (!SD.exists(fname)) {
      for (i = 0; i < num_felica; i++) {
        enter_t[i] = DateTime(2000, 1, 1, 0, 0, 0);
        leave_t[i] = DateTime(2000, 1, 1, 0, 0, 0);
      }
      last_touch_unknown = 0;
      File f = SD.open(fname, FILE_WRITE);
      f.println("");
      f.close();
    }
    // IDmを取得する
    for(int i = 0; i < 8; i++){
      sprintf(buf, "%02X", rcs620s.idm[i]);
      IDm += buf;
    }
    // IDmをデータベースと比較する
    strcpy(uname, "Unknown user");
    for (i = 0; i < num_felica; i++) {
      strcpy_P(IDm_buf, (char*) pgm_read_word(&IDms[i]));
      if (IDm.compareTo(IDm_buf) == 0) {
        strcpy_P(uname, (char*) pgm_read_word(&names[i]));
        break;
      }
    }
    // 前回のタッチから時間がたっている場合
    if (
      (i < num_felica && last_touch[i] == 0)
      ||
      (i == num_felica && (last_touch_unknown == 0 || IDm.compareTo(last_touch_unknown_IDm) != 0))
    ) {
      lcd.setCursor(0, 1);
      // データベースにないFeliCaがタッチされた場合
      if (i == num_felica) {
        tone(BUZZER_PIN, TONE_F4S);
        next_tone = 0;
        last_touch_unknown = TOUCH_PERIOD;
        last_touch_unknown_IDm = IDm;
        digitalWrite(ERROR_LED_PIN, HIGH);
        next_tone = 0;
        lcd.print(F("Touch       "));
        Serial.print("Unknown FeliCa: IDm = ");
        Serial.println(IDm);
      }
      // 入室の場合
      else if (enter_t[i].year() == 2000) {
        tone(BUZZER_PIN, TONE_E5);
        next_tone = TONE_C5;
        last_touch[i] = TOUCH_PERIOD;
        enter_t[i] = t;
        digitalWrite(ENTER_LED_PIN, HIGH);
        lcd.print(F("Enter       "));
      }
      // 退室の場合
      else {
        tone(BUZZER_PIN, TONE_C5);
        next_tone = TONE_E5;
        last_touch[i] = TOUCH_PERIOD;
        leave_t[i] = t;
        digitalWrite(LEAVE_LED_PIN, HIGH);
        lcd.print(F("Leave       "));
      }
      lcd.setCursor(0, 2);
      lcd.print(F("                    "));
      lcd.setCursor(0, 2);
      lcd.print(uname);
      // ファイルに入退室時刻を記録
      SD.remove(fname);
      File f = SD.open(fname, FILE_WRITE);
      if (f) {
        for (i = 0; i < num_felica; i++) {
          strcpy_P(IDm_buf, (char*) pgm_read_word(&IDms[i]));
          strcpy_P(uname, (char*) pgm_read_word(&names[i]));
          f.print(IDm_buf);
          f.print(",");
          f.print(uname);
          f.print(",");
          sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d",
                  enter_t[i].year(), enter_t[i].month(), enter_t[i].day(),
                  enter_t[i].hour(), enter_t[i].minute(), enter_t[i].second());
          f.print(buf);
          f.print(",");
          sprintf(buf, "%04d/%02d/%02d %02d:%02d:%02d",
                  leave_t[i].year(), leave_t[i].month(), leave_t[i].day(),
                  leave_t[i].hour(), leave_t[i].minute(), leave_t[i].second());
          f.println(buf);
        }
        f.close();
      }
      else {
        Serial.println("File open error");
      }
    }
    else {
      tone(BUZZER_PIN, TONE_F4S);
      next_tone = 0;
      digitalWrite(ERROR_LED_PIN, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Double touch");     
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print(uname);
    }
    r_timer = SHOW_PERIOD;
  }
  rcs620s.rfOff();
  delay(POLLING_INTERVAL);
}
