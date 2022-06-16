char incoming;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incoming = Serial.readString()[0];
    Serial.println(incoming);
    switch (incoming){
      case '0':
        Serial.println("rood");
        break;
      case '1':
        Serial.println("groen");
        break;
      default:
        Serial.println("error");
    }
  }
}
