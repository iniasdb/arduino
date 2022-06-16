int pot = A3;
int voltage = 0;
float vcc = 5.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(pot);
  float voltage = reading * (vcc/1023);
  int steps = voltage*10;

  Serial.print("voltage: ");
  Serial.println(voltage);
  Serial.print(0);
  for (int i = 0; i < steps; i++) {
    Serial.print("+");
  }
  Serial.println();
  Serial.println("---------------");
}
