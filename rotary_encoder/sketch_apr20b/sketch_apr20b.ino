int A = 2;
int B = 3;
int btn = 4;
int counter = 0;
int state = 0;
int previousState = 0;

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  Serial.begin(9600);
  previousState = digitalRead(A);
}

void loop() {
  state = digitalRead(A);
  if (state != previousState) {
    if (digitalRead(B) != state) {
      counter++;
    } else {
      counter--;
    }
  }
  if (digitalRead(btn) == HIGH) {
    Serial.println("de kut van a vader");
  }
  Serial.println(counter);
  previousState = state;
}
