#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int btn_F = 1;
int btn_C = 0;
int lm35 = A0;

int mode = 0;
int pre_btnC = HIGH;
int pre_btnF = HIGH;

void setup() {
  lcd.begin(16,2);
  pinMode(btn_F, INPUT);
  pinMode(btn_C, INPUT);
}

void loop() {

  int reading = analogRead(lm35);
  float voltage = reading * 5.0 / 1023.0;
  float tempC = voltage * 100.0;
  float tempF = (tempC * 1.8) + 32.0;
  
  int stateF = digitalRead(btn_F);
  if (stateF == LOW && pre_btnF == HIGH) {
    mode = 1;
  }
  pre_btnF = stateF;

  int stateC = digitalRead(btn_C);
  if (stateC == LOW && pre_btnC == HIGH) {
    mode = 0;
  }
  pre_btnC = stateC;

  lcd.setCursor(0,0);
  lcd.print("Nhiet do:");

  lcd.setCursor(0,1);
  if (mode == 0) {
    lcd.print(tempC);
    lcd.print("C");
  } else {
    lcd.print(tempF);
    lcd.print("F");
  }

  delay(300);
}
