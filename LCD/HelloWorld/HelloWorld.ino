#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip

const int LCD_COLS = 16;
const int LCD_ROWS = 2;

void setup() {
  int status;
	status = lcd.begin(LCD_COLS, LCD_ROWS);
	if(status) {
		hd44780::fatalError(status); // does not return
	}
 
	lcd.print("Hello, World!");
}

void loop() {}
