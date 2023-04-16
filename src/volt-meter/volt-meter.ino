#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int contrast = 0;


float input_voltage = 0.0;
float temp=0.0;

void setup() {
  Serial.begin(9600);
  analogWrite(6, contrast);
  lcd.begin(16, 2);
}

void loop() { 
  lcd.setCursor(0, 0);
  lcd.print("Volt meter");

  int analog_value = analogRead(A0);
  input_voltage = (analog_value * 5.0) / 1024.0; 

  Serial.print("Analog volts: ");
  Serial.println(analog_value);
  Serial.print("Volts: ");
  Serial.println(input_voltage);

  lcd.setCursor(0, 1);
  lcd.print("Volts = ");
  lcd.print(input_voltage);
  delay(200);
}
