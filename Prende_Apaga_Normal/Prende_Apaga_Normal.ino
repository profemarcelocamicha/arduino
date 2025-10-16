void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH); // Encender
  delay(1000);             // Esperar 1 segundo (bloquea)
  digitalWrite(2, LOW);  // Apagar
  delay(1000);             // Esperar 1 segundo (bloquea)
}
