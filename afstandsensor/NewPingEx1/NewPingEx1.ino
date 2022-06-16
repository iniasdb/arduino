#include <NewPing.h>

int trigPin = 2;
int echoPin = 3;
int maxDistance = 400;
long duration = 0;
float distance = 0.0;

NewPing sonar(trigPin, echoPin, maxDistance);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.println(sonar.convert_cm(sonar.ping_median(5)));
  Serial.println("cm");
}
