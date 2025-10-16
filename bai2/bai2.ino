int red1=5, red2=8, red3=11;
int green1=7, green2=10, green3=13;
int yellow1=6, yellow2=9, yellow3=12;
void setup() {
  int leds[]={red1,red2,red3,green1,green2,green3,yellow1,yellow2,yellow3};
  for(int i=0;i<9;i++){
    pinMode(leds[i],OUTPUT);
  }

}

void loop() {
    digitalWrite(green1,HIGH);
    digitalWrite(red2,HIGH);
    digitalWrite(red3,HIGH);
    delay(1000);


    digitalWrite(yellow1,HIGH);
    digitalWrite(green1,LOW);
    delay(500);

    digitalWrite(yellow1,LOW);
    digitalWrite(red1,HIGH);
    digitalWrite(red2,LOW);
    digitalWrite(red3,LOW);
    digitalWrite(green2,HIGH);
    digitalWrite(green3,HIGH);
    delay(1000);

    digitalWrite(yellow2,HIGH);
    digitalWrite(yellow3,HIGH);
    digitalWrite(green2,LOW);
    digitalWrite(green3,LOW);
    delay(500);

    digitalWrite(red1,LOW);
    digitalWrite(green1,HIGH);
    digitalWrite(red2,HIGH);
    digitalWrite(red3,HIGH);
    digitalWrite(yellow2,LOW);
    digitalWrite(yellow3,LOW);
}
