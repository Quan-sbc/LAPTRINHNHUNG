#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int btn_on_off = 9;
int btn_to_the_left = 8;
int btn_to_the_right = 10;
int pre_btn_on_off = LOW;
int pre_btn_to_the_left = LOW;
int pre_btn_to_the_right = LOW;
unsigned long pre_time = 0;
int solannhan = 0;
int x = 0;
void setup() {
  lcd.begin(16,2);
  pinMode(btn_on_off,INPUT);
  pinMode(btn_to_the_left,INPUT);
  pinMode(btn_to_the_right,INPUT);
}

void loop() {
  int cur_btn_on_off = digitalRead(btn_on_off);
  int cur_btn_to_the_left = digitalRead(btn_to_the_left);
  int cur_btn_to_the_right = digitalRead(btn_to_the_right);
  unsigned long cur_time = millis();
  solannhan = solannhan % 2;
  if(cur_btn_on_off == LOW && pre_btn_on_off == HIGH)
  {
    solannhan++;
    delay(100);
  }
  if(solannhan == 0)
  {
      lcd.display();
      lcd.setCursor(x,0);
      lcd.print("HELLO"); 
  }
  else
  {
    lcd.noDisplay();
  }
  if(cur_btn_to_the_right == LOW && pre_btn_to_the_right == HIGH)
  {
    x+=2;
    if(x>11)
      x=10;
    lcd.clear();
      lcd.display();
      lcd.setCursor(x,0);
      lcd.print("HELLO");
  }
  if(cur_btn_to_the_left == LOW && pre_btn_to_the_left == HIGH)
  {
    x-=2;
    if(x<0)
      x=0;
      lcd.clear();
      lcd.display();
      lcd.setCursor(x,0);
      lcd.print("HELLO");
  }
  pre_btn_on_off = cur_btn_on_off;
  pre_btn_to_the_left = cur_btn_to_the_left;
  pre_btn_to_the_right = cur_btn_to_the_right;
}