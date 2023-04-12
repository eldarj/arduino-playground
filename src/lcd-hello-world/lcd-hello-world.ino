#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int contrast = 0;

void setup() {
  Serial.begin(9600);
  analogWrite(6, contrast);
  lcd.begin(16, 2);

  byte allPixelsTurnedOn[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
  };

  lcd.createChar(1, allPixelsTurnedOn);
}

void loop() { 
  for (int i = 0; i < 5; i++) {
    load();
  }

  lcd.clear();

  for (int i = 0; i < 5; i++) {
    lightsUp();
  }

  slideHello();
  slideWorld();

  delay(5000);
}

void slideHello() {
  for (int i = 16; i > 0; i--) {
    lcd.setCursor(i - 1, 0);
    lcd.print("Hello           ");
    delay(50);
  }
}

void slideWorld() {
  for (int i = 16; i > 0; i--) {
    lcd.setCursor(i - 1, 1);
    lcd.print("World!          ");
    delay(50);
  }
}

void load() {
  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("Loading");
    delay(300); 

  for (int i = 0; i < 3; i++) {
    lcd.print(".");
    delay(300); 
  }
}

void lightsUp() {
  lcd.setCursor(0, 0);
  for(int i = 0; i < 16; i++) {
    lcd.write(byte(1));
  }

  lcd.setCursor(0, 1);
  for(int i = 0; i < 16; i++) {
    lcd.write(byte(1));
  }

  delay(300);
  lcd.clear();
  delay(300);
}
