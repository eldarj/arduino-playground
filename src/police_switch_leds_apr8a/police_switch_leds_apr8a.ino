int switchState = 0;
bool pressed = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == HIGH) {
    pressed = true;
    digitalWrite(3, LOW);

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(250);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
    delay(250);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(250);

  } else {
    if (pressed == true) {
      pressed = false;

      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(100);
      digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(3, LOW);
      delay(100);
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(100);
      digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(3, LOW);
      delay(100);
      digitalWrite(3, HIGH);
      delay(250);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    } else {
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
  }
}
