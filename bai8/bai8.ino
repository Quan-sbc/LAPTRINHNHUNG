#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

// ===== Các ký tự đặc biệt =====
byte E_E[8] = {
  B00100,
  B01110,
  B10001,
  B11111,
  B10000,
  B11111,
  B10001,
  B10001
};

byte O_O[8] = {
  B00100,
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte E_F[8] = {
  B01000,
  B00100,
  B11111,
  B10000,
  B11111,
  B10001,
  B11111,
  B10001
};

byte E_S[8] = {
  B00100,
  B01000,
  B11111,
  B10000,
  B11111,
  B10001,
  B11111,
  B10001
};

byte O_F[8] = {
  B01000,
  B00100,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte O_S[8] = {
  B00100,
  B01000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

// ===== Khai báo chân nút =====
int btn_E = 7;
int btn_O = 8;
int btn_F = 9;
int btn_S = 10;

char lastKey = '\0'; // ký tự trước đó

// ===== SETUP =====
void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,E_E);
  lcd.createChar(1,O_O);
  lcd.createChar(2,E_F);
  lcd.createChar(3,E_S);
  lcd.createChar(4,O_F);
  lcd.createChar(5,O_S);

  pinMode(btn_E, INPUT_PULLUP);
  pinMode(btn_O, INPUT_PULLUP);
  pinMode(btn_F, INPUT_PULLUP);
  pinMode(btn_S, INPUT_PULLUP);

  lcd.print("Ban phim EOFS");
  delay(1500);
  lcd.clear();
}

// ===== LOOP =====
void loop() {
    lcd.setCursor(0,0);
  char key = readKey();  // đọc nút nhấn
  if (key != '\0') {     // nếu có phím được bấm
    if (lastKey != '\0') {
      processCombo(lastKey, key);
      lastKey = '\0';
    } else {
      lastKey = key;
    }
  }
}

// ===== Hàm đọc phím =====
char readKey() {
  if (digitalRead(btn_E) == LOW) { delay(200); return 'E'; }
  if (digitalRead(btn_O) == LOW) { delay(200); return 'O'; }
  if (digitalRead(btn_F) == LOW) { delay(200); return 'F'; }
  if (digitalRead(btn_S) == LOW) { delay(200); return 'S'; }
  return '\0';
}

// ===== Xử lý tổ hợp =====
void processCombo(char first, char second) {
  if (first=='E' && second=='E') lcd.write(byte(0));   // Ê
  else if (first=='O' && second=='O') lcd.write(byte(1)); // Ô
  else if (first=='E' && second=='F') lcd.write(byte(2)); // È
  else if (first=='E' && second=='S') lcd.write(byte(3)); // É
  else if (first=='O' && second=='F') lcd.write(byte(4)); // Ò
  else if (first=='O' && second=='S') lcd.write(byte(5)); // Ó
  else {
    lcd.print(first);
    lcd.print(second);
  }
}
