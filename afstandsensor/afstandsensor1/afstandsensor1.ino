int trigPin = 2;
int echoPin = 3;
long duration = 0;
float distance = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  Serial.println(duration);

  distance = duration * 0.0343 / 2;
  Serial.print("distance = ");

  if (distance < 2 || distance > 400) {
    Serial.print("out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(500);
}
