/*int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;*/
int ledArray[5] = {2, 3, 4, 5, 6};
int arrayLen = sizeof(ledArray)/sizeof(*ledArray);
int pot = A3;
int speed = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < arrayLen; i++){
    pinMode(ledArray[i], OUTPUT);
  }
  Serial.begin(9600);
  digitalWrite( ledArray[0], HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  speed = analogRead(pot)*10;
  speed = 100;

  for (int i = 0; i <= arrayLen; i++) {
    if (i>0) {
      digitalWrite(ledArray[i-1], LOW);
      delay(speed);
    }
    digitalWrite(ledArray[i], HIGH);
  }

  for (int i = arrayLen-1; i >= arrayLen; i--) {
    if (i<arrayLen-2) {
      digitalWrite(ledArray[i+1], LOW);
      delay(speed);
    }
    digitalWrite(ledArray[i], HIGH);
  }
  
}
