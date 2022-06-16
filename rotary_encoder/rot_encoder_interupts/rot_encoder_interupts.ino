int A = 2;
int B = 3;
int btn = 4;
int counter = 0;
int state = 0;
int previousState = 0;
int rot_dir = 0;
int rangeMax = 8;
int rangeMin = 0;

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  Serial.begin(9600);
  previousState = digitalRead(A);
  attachInterrupt(digitalPinToInterrupt(A), change, RISING);
  attachInterrupt(digitalPinToInterrupt(btn), clicked, RISING);
}

void loop() {
  state = digitalRead(A);
  Serial.println(counter);
  previousState = state;
}

void change() {
  rot_dir = digitalRead(B);
  state = 1;
  if (rot_dir != state) {
    if (counter < 8) {
      counter++;
    }
  } else {
    if (counter > 0) {
      counter--;
    }
  }  
}

void clicked() {
  Serial.println("de kut van a vader");
}
