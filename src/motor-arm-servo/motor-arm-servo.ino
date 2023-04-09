#include <Servo.h>

Servo servoMotor;
const int outputPin = 9;
const int analogKnobInputPin = A0;

void setup() {
  servoMotor.attach(outputPin);
  Serial.begin(9600);
}

void loop() {
  int knobValue = analogRead(analogKnobInputPin);
  int angle = setAngle(knobValue);
  log(knobValue, angle);
  delay(50);
}

int setAngle(int knobValue) {
  int angle = map(knobValue, 0, 1023, 0, 179);
  servoMotor.write(angle);
  return angle;
}

void log(int knobValue, int angle) {
  Serial.print("Knob value: ");
  Serial.print(knobValue);
  Serial.print(", angle: ");
  Serial.println(angle);
}