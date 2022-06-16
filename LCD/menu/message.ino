int dr1 = 2;
int dr2 = 3;

bool flag_scroll = false;
bool flag_selecteer = false;


bool selecthigh = false;
int telsc = 1;
int led = 0;
int runlevel = 0;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // put your setup code here, to run once:
  pinMode(dr1, INPUT);
  pinMode(dr2, INPUT);
  attachInterrupt(digitalPinToInterrupt(dr1), scroll, RISING);
  attachInterrupt(digitalPinToInterrupt(dr2), selecteer, RISING);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(telsc);
  if (runlevel == 0) {
    hoofdMenu();
    if (selecthigh) {
      switch (telsc) {
        case 1:
          runlevel = 1;
          telsc = 1;
          break;
        case 2:
          runlevel = 2;
          telsc = 1;
          break;
      }
      selecthigh = false;
    }
  }
  if (runlevel == 1) {
    menuIL();
    if (selecthigh) {
      telsc = 1;
      switch (telsc) {
        case 1:
          runlevel = 3;
          led = 1;
          break;
        case 2:
          runlevel = 3;
          led = 2;
          break;
        case 3:
          runlevel = 3;
          led = 3;
          break;
        case 4:
          runlevel = 3;
          led = 4;
          break;
        case 5:
          runlevel = 0;
          telsc = 1;
          break;
      }
      selecthigh = false;
    }
  }

  if (runlevel == 2) {
    menuKL();
    if (selecthigh) {
      telsc = 1;
      switch (telsc) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          runlevel = 0;
          break;
      }
      selecthigh = false;
    }
  }

  if (runlevel == 3) {
    menuAU();
  }



  if (flag_scroll) {
    Serial.println("scroll");
    telsc++;
    delay(200);
    flag_scroll = false;
  }

  if (flag_selecteer) {
    Serial.println("selecteer");
    delay(200);
    selecthigh = true;
    flag_selecteer = false;
  }

}


void hoofdMenu() {
  switch (telsc) {
    case 1:
      lcd.clear();
      lcd.print(">individuele led");
      lcd.setCursor(0, 1);
      lcd.print("kleur");
      break;
    case 2:
      lcd.clear();
      lcd.print("individuele led");
      lcd.setCursor(0, 1);
      lcd.print(">kleur");
      break;
    case 3:
      telsc = 1;
      break;
  }
  delay(500);
}

void menuIL() {
  switch (telsc) {
    case 1:
      lcd.clear();
      lcd.print(">1");
      lcd.setCursor(0, 1);
      lcd.print("2");
      break;
    case 2:
      lcd.clear();
      lcd.print("1");
      lcd.setCursor(0, 1);
      lcd.print(">2");
      break;
    case 3:
      lcd.clear();
      lcd.print(">3");
      lcd.setCursor(0, 1);
      lcd.print("4");

      break;
    case 4:
      lcd.clear();
      lcd.print("3");
      lcd.setCursor(0, 1);
      lcd.print(">4");
      break;
    case 5:
      lcd.clear();
      lcd.print("terug naar hoofdmenu");
      break;
    case 6:
      telsc = 1;
      break;
  }
  delay(500);
}

void menuAU() {
  switch (telsc) {
    case 1:
      lcd.clear();
      lcd.print(">aan");
      lcd.setCursor(0, 1);
      lcd.print("uit");
      break;
    case 2:
      lcd.clear();
      lcd.print("aan");
      lcd.setCursor(0, 1);
      lcd.print(">uit");
      break;
    case 3:
      telsc = 1;
      break;
  }
  delay(500);

}

void menuKL() {
  switch (telsc) {
    case 1:
      lcd.clear();
      lcd.print(">rood");
      lcd.setCursor(0, 1);
      lcd.print("groen");
      break;
    case 2:
      lcd.clear();
      lcd.print("rood");
      lcd.setCursor(0, 1);
      lcd.print(">groen");
      break;
    case 3:
      lcd.clear();
      lcd.print(">terug hoofdm");

      break;
    case 4:
      telsc = 1;
      break;
  }
  delay(500);

}



void scroll() {
  flag_scroll = true;
}

void selecteer() {
  flag_selecteer = true;
}
