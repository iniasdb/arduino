int sw1 = 2;
int sw2 = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;
int led6 = 9;

int debounce = 200;
bool gameRunning = false;

int selector = 0;
int currPosition = 0;
int popupTime = 2000;
int tries = 1;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(sw1), setupGame, FALLING);
  attachInterrupt(digitalPinToInterrupt(sw2), startGame, FALLING);
}

void loop() {
  if (gameRunning) {
    currPosition = generateRandom();
    switch (currPosition) {
      case 1:
        digitalWrite(led1, HIGH);
        break;
      case 2:
        digitalWrite(led2, HIGH);
        break;
      case 3:
        digitalWrite(led3, HIGH);
        break;
      case 4:
        digitalWrite(led4, HIGH);
        break;
      case 5:
        digitalWrite(led5, HIGH);
        break;
      case 6:
        digitalWrite(led6, HIGH);
        break;
    }
    Serial.println(currPosition);
    delay(popupTime);

    for (int i = 4; i < 10; i++) {
      digitalWrite(i, LOW);
    }
  }
}

void setupGame() {
  if (gameRunning) {
    Serial.print("curr: ");
    Serial.println(currPosition); 

    if (currPosition == selector) {
      Serial.println("Raak!");
      Serial.print("Geraakt in ");
      Serial.print(tries);
      Serial.println(" pogingen");
      gameRunning = false;

      if (popupTime > 50) {
        popupTime -= 10;
      }
      
      setupGame();
      startGame();
      delay(debounce);
    } else {
      Serial.println("Fout gemikt!");
      tries++;
    }
  } else {
    selector = generateRandom();
    Serial.println(selector);    
  }
}

void startGame() {
  gameRunning = true;
}

int generateRandom() {
  int randomN = random(1, 7);
  return randomN;
}
