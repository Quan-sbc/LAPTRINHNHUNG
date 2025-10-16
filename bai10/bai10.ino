#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int btn_State =8; 

int lm35 = A0;

int mode = 0;
int pre_btnState = HIGH;


int red=0;
int yellow=1;
int green=7;
void setup() {
  lcd.begin(16,2);
  pinMode(btn_State, INPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {

  int reading = analogRead(lm35);
  float voltage = reading * 5.0 / 1023.0;
  float tempC = voltage * 100.0;
  float tempF = (tempC * 1.8) + 32.0;
  
  int state = digitalRead(btn_State);
  if (state == LOW && pre_btnState == HIGH) {
    mode = !mode;
  }
  pre_btnState = state;
  lcd.setCursor(0,0);
  lcd.print("Nhiet do:");

  lcd.setCursor(0,1);
  if (mode) {
    lcd.print(tempC);
    lcd.print("C");
  } else {
    lcd.print(tempF);
    lcd.print("F");
  }
  if(tempC<17){
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
  }else if(tempC>=17 && tempC <=30){
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
  }else{
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
  }
  delay(300);
}
