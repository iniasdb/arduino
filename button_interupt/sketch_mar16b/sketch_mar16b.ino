int sw1 = 3;
int sw2 = 2;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int count = 0;
int debounce = 200;
bool aanFlag = false;
bool uitFlag = false;

void setup() {
  Serial.begin(9600);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  attachInterrupt(digitalPinToInterrupt(sw1), aan, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), uit, FALLING);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void aan() {
  /*if (count < 3) {
    count++;
  }*/
  aanFlag = true;
  delay(debounce);
}

void uit() {
  /*if (count > 0) {
    count--;
  }*/
  uitFlag = true;
  delay(debounce);
}

void loop() {

  if (aanFlag) {
    delay(debounce);
    if (count < 3) {
      count++;
    }
    aanFlag = false;
  }

  if (uitFlag) {
    delay(debounce);
    if (count > 0) {
      count--;
    }
    uitFlag = false;
  }

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  Serial.println(count);

  switch(count) {
    case 3:
      digitalWrite(led3, HIGH);
    case 2:
      digitalWrite(led2, HIGH);
    case 1:
      digitalWrite(led1, HIGH);
  }

  delay(10);
}
