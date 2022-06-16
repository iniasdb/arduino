/*int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;*/
int ledArray[5] = {2, 3, 4, 5, 6};
int arrayLen = sizeof(ledArray)/sizeof(*ledArray);
int pot = A3;
int voltage = 0;

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
  int voltage = analogRead(pot);
  /*Serial.print("potentiometer: ");
  Serial.println(voltage);*/

  if (voltage == 0) {
    lightsOff();
  } else if (voltage <= 204) {
    //led 1
    Serial.println("led 1");
    controlLights(0);
  } else if (voltage > 204 && voltage <= 408) {
    //led 1 2
        Serial.println("led 2");
    controlLights(1);
  } else if (voltage > 408 && voltage <= 612) {
    //led 123
        Serial.println("led 3");
    controlLights(2);
  } else if (voltage > 612 && voltage <= 816) {
    //led 1234
        Serial.println("led 4");
    controlLights(3);
  } else {
    //led 12345
        Serial.println("led 5");
    controlLights(4);
  }
}

void lightsOff() {
  for (int i = 0; i <= arrayLen; i++){
    digitalWrite(ledArray[i], LOW);
  }
}


void controlLights(int led) {
  lightsOff();
  
  for (int i = 0; i <= led; i++) {
    digitalWrite(ledArray[i], HIGH);
  }
}
