#include <Servo.h>

Servo s;

int const potPin = A0;
int const servoPin = 9;
int const trigPin = 2;
int const echoPin = 3;

int potVal;
int angle;
long duration;
float distance;

void setup() {
  s.attach(servoPin);
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(servoPin, OUTPUT);
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

  distance = duration * 0.0343 / 2;
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  int angle = map(distance, 0, 50, 45, 135);
  Serial.println(angle);
  s.write(angle);
  /*if (distance > 50) {
    s.write(135);
  } else if (distance < 20) {
    s.write(45);
  } else {
    s.write(90);
  }*/

  delay(500);
}
