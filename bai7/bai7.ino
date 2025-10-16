#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte AW[8] = {
  B01010,
  B00100,
  B00000,
  B00100,
  B01010,
  B01110,
  B10001,
  B00000
};
byte AA[8] = {
  B00100,
  B01010,
  B00000,
  B00100,
  B01010,
  B01110,
  B10001,
  B00000
};
byte DD[8] = {
  B01110,
  B01001,
  B01001,
  B11101,
  B01001,
  B01001,
  B01110,
  B00000
};
byte OO[8] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B01010,
  B01010,
  B01110,
  B00000
};
byte OW[8] = {
  B00010,
  B00001,
  B00010,
  B01110,
  B01010,
  B01010,
  B01110,
  B00000
};
byte UW[8] = {
  B00110,
  B00001,
  B01010,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};
void setup() {
  lcd.begin(16,2);

  lcd.createChar(0,AW);
  lcd.createChar(1,AA);
  lcd.createChar(2,DD);
  lcd.createChar(3,OO);
  lcd.createChar(4,OW);
  lcd.createChar(5,UW);

  lcd.setCursor(0,0);
  lcd.print(char(0));
  lcd.print(char(1));
  lcd.print(char(2));
  lcd.print(char(3));
  lcd.print(char(4));
  lcd.print(char(5));
}

void loop() {
  // put your main code here, to run repeatedly:

}
