void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH); // Encender
  delay(1000);             // Esperar 1 segundo (bloquea)
  digitalWrite(led, LOW);  // Apagar
  delay(1000);             // Esperar 1 segundo (bloquea)
}
