int power(int x, int y) {
  int prod = 1;
  for (int i = 0; i < y; i++) {
    prod *= x;
  }
  return prod;
}

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(i + 2, OUTPUT);
    digitalWrite(i + 2, LOW);
  }
}

void showBinary(int wallSeconds) {
  for (int i = 0; i < 6; i++) {
    int bitMax = power(2, i);
    int val = (wallSeconds / bitMax) % 2;
    digitalWrite(i + 2, val);
  }
}

void showDecimal(int wallSeconds) {
  for (int i = 0; i < 6; i++) {
    int thresholdMin = 10 * i;
    int thresholdMax = 10 * i + 10;
    int valRaw = map(wallSeconds, thresholdMin, thresholdMax, 0, 255);
    int val = constrain(valRaw, 0, 255);
    analogWrite(i + 2, val);
  }
}

void loop() {
  setup();

  long ellapsedSeconds = millis() / 1000;
  int wallSeconds = ellapsedSeconds % 60;

  int toggleMinute = (ellapsedSeconds / 60) % 2;

  if (toggleMinute == 0) {
    showDecimal(wallSeconds);
  } else {
    showBinary(wallSeconds);
  }

  delay(10);
}
