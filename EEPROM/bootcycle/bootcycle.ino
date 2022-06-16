#include <EEPROM.h>

int addr = 0;
int data  = 0;

void setup() {
  Serial.begin(9600);
  data = EEPROM.read(addr);
  Serial.println(data);
  data++;
  EEPROM.write(addr, data);
}

void loop() {
  // put your main code here, to run repeatedly:

}
