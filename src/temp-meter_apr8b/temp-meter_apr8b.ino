const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print("Sensor value = ");
  Serial.print(sensorVal);
  
  Serial.print(", Volts = ");
  Serial.print(voltage);
  
  float temperature = (voltage - .5) * 100;
  Serial.print(", Degrees C = ");
  Serial.print(temperature);
  Serial.println();

  delay(100);
  Serial.print(".");
  delay(100);
  Serial.print("...");
  delay(100);
  Serial.println("..");
  delay(100);

  if (temperature > 24) {
    turnOnLeds(3);
  } else if (temperature > 23) {
    turnOnLeds(2);
  } else if (temperature > 22) {
    turnOnLeds(1);
  } else {
    turnOnLeds(0);
  }
}

void turnOnLeds(int numberOfLedsToTurnOn) {
  for (int pinNumber = 2, count = 0; pinNumber <= 4; pinNumber++) {
    if (count < numberOfLedsToTurnOn) {
      digitalWrite(pinNumber, HIGH);
    } else {
      digitalWrite(pinNumber, LOW);
    }
    count++;
  }
}
