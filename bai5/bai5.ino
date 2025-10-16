#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int btn = 1;
int led = 0;
int solannhan = 0;
unsigned long pre_btn = LOW;
void setup() {
  lcd.begin(16,2);
  pinMode(led,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  unsigned long cur_btn = digitalRead(btn);
  solannhan = solannhan % 2;
  if(cur_btn == LOW && pre_btn == HIGH)
  {
    solannhan++;
  }
  if(solannhan == 0)
  {
    digitalWrite(led,LOW);
    lcd.clear();
    lcd.display();
    lcd.setCursor(1,1);
    lcd.print("...");
  }
  else
  {
    lcd.noDisplay();
    digitalWrite(led,HIGH);
  }
  pre_btn = cur_btn;
}
