int segments[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 9; i++) {
    pinMode(segments[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 9; i++) {
    digitalWrite(segments[i], HIGH);
    digitalWrite(segments[i - 1], LOW);
    delay(100);
  }
}
