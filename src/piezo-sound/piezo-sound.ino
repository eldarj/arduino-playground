// Input and output pins for our piezo and phototransistor
const int piezoOutputPin = 8;
const int phototransistorInputPin = A0;

// Values used for calibrating the phototransistor
int sensorHigh = 0;
int sensorLow = 1023;

void setup() {
  Serial.begin(9600);
  calibratePhototransistor();
}

void loop() {
  int photoSensorValue = analogRead(phototransistorInputPin);
  int pitch = map(photoSensorValue, sensorLow, sensorHigh, 0, 4000);

  tone(piezoOutputPin, pitch, 100);

  log(photoSensorValue, pitch);
  delay(120);
}


void log(int photoSensorValue, int pitch) {
  Serial.print("Phototransistor value: ");
  Serial.print(photoSensorValue);
  Serial.print(", pitch: ");
  Serial.println(pitch);
}

void calibratePhototransistor() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.println("Calibrating phototransistor...");
  while (millis() < 5000) {
    int photoSensorValue = analogRead(phototransistorInputPin);

    if (photoSensorValue > sensorHigh) {
      sensorHigh = photoSensorValue;
    } else {
      sensorLow = photoSensorValue;
    }
  }

  Serial.println("Calibration completed.");
  Serial.print("Max sensor high calibrated to: ");
  Serial.print(sensorHigh);
  Serial.print(", Min sensor high calibrated to: ");
  Serial.println(sensorLow);

  digitalWrite(LED_BUILTIN, LOW);
}
