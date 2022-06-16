int segments[] = {2, 3, 4, 5, 6, 7, 8, 9};
int displays[] = {A0, A1, A2, A3};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 9; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int k = 0; k < 4; k++) {
    analogWrite(displays[k], 0);
    delay(100);
    for (int i = 0; i < 9; i++) {
      digitalWrite(segments[i], HIGH);
      digitalWrite(segments[i - 1], LOW);
      delay(100);
    }
    analogWrite(displays[k], 255);
  }
}
