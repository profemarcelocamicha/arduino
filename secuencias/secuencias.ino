void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 3; i++) {
    int varI = 6;
    int varD = 7;

    while (varD <= 11) {
      digitalWrite(varI, HIGH);
      digitalWrite(varD, HIGH);
      delay(50);
      digitalWrite(varI, LOW);
      digitalWrite(varD, LOW);
      delay(10);
      varI--;
      varD++;
    }

    varI = 2;
    varD = 11;

    while (varD >= 7) {
      digitalWrite(varI, HIGH);
      digitalWrite(varD, HIGH);
      delay(50);
      digitalWrite(varI, LOW);
      digitalWrite(varD, LOW);
      delay(10);
      varI++;
      varD--;
    }
  }

  for (int i = 2; i <= 11; i++) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 2, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    digitalWrite(i + 2, LOW);
    delay(10);
  }

  for (int i = 12; i >= 2; i--) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 2, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    digitalWrite(i + 2, LOW);
    delay(10);
  }

  for (int i = 2; i <= 11; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(10);
  }

  for (int i = 12; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
    delay(10);
  }

  for (int i = 2; i <= 11; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }

  for (int i = 2; i <= 11; i++) {
    digitalWrite(i, LOW);
    delay(50);
  }

  for (int i = 12; i >= 2; i--) {
    digitalWrite(i, HIGH);
    delay(50);
  }
  for (int i = 12; i >= 2; i--) {
    digitalWrite(i, LOW);
    delay(50);
  }
  for (int i = 2; i <= 11; i++) {
    digitalWrite(i, HIGH);
  }
  delay(400);
  for (int i = 2; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  delay(100);
}