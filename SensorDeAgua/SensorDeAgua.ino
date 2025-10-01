int pinSensor = A0;
int valor = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valor = analogRead(pinSensor);
  Serial.println(valor);  // Muestra el valor crudo 0-1023
  delay(500);
}
