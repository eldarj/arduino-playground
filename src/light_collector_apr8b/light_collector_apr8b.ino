const int greenLedPin = 9;
const int redLedPin = 10;
const int blueLedPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int red = 0;
int green = 0;
int blue = 0;

int redSensor = 0;
int greenSensor = 0;
int blueSensor = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  redSensor = analogRead(redSensorPin);
  delay(5);
  greenSensor = analogRead(greenSensorPin);
  delay(5);
  blueSensor = analogRead(blueSensorPin);

  log(redSensor, greenSensor, blueSensor);

  red = redSensor / 4;
  green = (greenSensor / 4) + 30;
  blue = blueSensor / 4;

  analogWrite(redLedPin, red);
  analogWrite(greenLedPin, green);
  analogWrite(blueLedPin, blue);

  log(red, green, blue);
}

void log(int r, int g, int b) {
  Serial.print("Color Values \t red: ");
  Serial.print(r);
  Serial.print("\t green: ");
  Serial.print(g);
  Serial.print("\t blue: ");
  Serial.println(b);
  Serial.print(".");
  delay(300);
  Serial.print("...");
  delay(300);
  Serial.println("....");
  delay(300);
}
