int ledPin = 9;
int buttonFast = 11;
int buttonSlow = 10;

int delayTime = 500;  // tốc độ nhấp nháy ban đầu (ms)
int minDelay = 100;
int maxDelay = 1000;

unsigned long previousMillis = 0; // thời điểm LED đổi trạng thái
bool ledState = false;            // trạng thái LED hiện tại

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonFast, INPUT_PULLUP);
  pinMode(buttonSlow, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  // --- đọc nút nhấn ---
  if (digitalRead(buttonFast) == LOW) {
    delayTime -= 50;
    if (delayTime < minDelay) delayTime = minDelay;
  
  }

  if (digitalRead(buttonSlow) == LOW) {
    delayTime += 50;
    if (delayTime > maxDelay) delayTime = maxDelay;

  }

  // --- xử lý chớp LED bằng millis ---
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;   // cập nhật mốc thời gian
    ledState = !ledState;             // đảo trạng thái
    digitalWrite(ledPin, ledState);   // ghi trạng thái LED
  }
}
