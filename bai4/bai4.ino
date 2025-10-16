int ledRed=6;
int ledGreen=7;
int btn=8;

int temp=0;
int pre_btn=LOW;
unsigned long lastPress = 0;
const int debounceDelay = 200;

void setup() {
  pinMode(ledRed,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(btn,INPUT);
  digitalWrite(ledRed,LOW);
  digitalWrite(ledGreen,LOW);
}

void loop() {
  int cruBtn = digitalRead(btn);
  unsigned long now = millis();

  if (cruBtn == HIGH && pre_btn == LOW && (now - lastPress) > debounceDelay) {
    temp++;
    if(temp > 4) temp = 1;

    switch(temp){
      case 1: digitalWrite(ledRed,HIGH); digitalWrite(ledGreen,HIGH); break;
      case 2: digitalWrite(ledRed,LOW);  digitalWrite(ledGreen,LOW);  break;
      case 3: digitalWrite(ledRed,HIGH); digitalWrite(ledGreen,LOW);  break;
      case 4: digitalWrite(ledRed,LOW);  digitalWrite(ledGreen,HIGH); break;
    }

    lastPress = now; 
  }

  pre_btn = cruBtn;
}
